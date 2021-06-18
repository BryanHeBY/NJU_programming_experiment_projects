//
// Created by hby on 2021/4/23.
//

#include "DTable.h"
#include "SQLError.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include "DCol.h"
#include "DExpr.h"

using namespace std;

DTRow::DTRow(const DTable &table, ifstream &ifs) :DObject(20){
    _row.reserve(table._vars_num);
    for(DVarDeclare i:table._varsDeclare)_row.emplace_back(DData{i.type_id,i.size,ifs});
}

DTRow::DTRow(const vector<DData> &row) :DObject(20){
    for(DData i:row)_row.emplace_back(i);
}

void DTRow::write_file(ofstream &ofs) {
    for(DData &i:_row)i.write_file(ofs);
}

const DData &DTRow::operator[](int index) const{
    return _row[index];
}



DTable::DTable(const string &str,const vector<DVarDeclare> &varDeclare)
    :DObject(21),_vars_num(varDeclare.size()),_varsDeclare(varDeclare),_counter(0),has_changed(1){
    if(str.length()+1>MAX_NAME_SIZE)throw SQLError("201","Name is out of length limit.");
    strcpy(_name,str.c_str());
    _primary_key=-1;
    set<string> col_name;

    for(size_t i=0;i<_varsDeclare.size();i++){
        if(_varsDeclare[i].primary_key){
            if(_primary_key==-1)_primary_key=i;
            else throw SQLError("103","Not Single primary_key");
        }
        auto j=col_name.find(_varsDeclare[i].name);
        if(j!=col_name.end())throw SQLError("108","Name of column is not unique.");
        col_name.insert(_varsDeclare[i].name);
    }
    /*
    if(_primary_key==-1){
        _vars_num++;
        _varsDeclare.emplace_back(DVarDeclare(3,4,"@PRIMARY_KEY",1,1,1));
        _primary_key=_vars_num-1;
        _end_last=1;
    }*/
}

DTable::DTable(const char *f_src) :DObject(21),has_changed(0){
    ifstream f(f_src,ios::binary);
    if(!f.is_open())throw SQLError("102","File can't open.");
    f.read(_name,sizeof _name);
    f.read((char *)&_vars_num,sizeof _vars_num);
    f.read((char *)&_primary_key,sizeof _primary_key);
    f.read((char *)&_counter,sizeof _counter);
    _varsDeclare.reserve(_vars_num);
    for(int i=0;i<_vars_num;i++){
        DVarDeclare dvar;
        f.read((char *)&dvar,sizeof dvar);
        _varsDeclare.emplace_back(dvar);
    }
    while(1){
        try{_table.emplace_back(DTRow(*this,f));}
        catch(SQLError &e){
            if(e.code()=="101")break;
            else throw e;
        }
    }
}

void DTable::write_file(const char *f_src) {
    ofstream f(f_src,ios::binary|ios::ate);
    if(!f.is_open())throw SQLError("102","File can't open.");
    f.write(_name,sizeof _name);
    f.write((char *)&_vars_num,sizeof _vars_num);
    f.write((char *)&_primary_key,sizeof _primary_key);
    f.write((char *)&_counter,sizeof _counter);
    for(DVarDeclare &i:_varsDeclare)f.write((char *)&i,sizeof i);
    for(DTRow &i:_table)i.write_file(f);
}

DTable SELECT(const string &name,bool distinct,const vector<DCol> &dCols, const vector<DTable *> &tables,const DExpr &where,const DColIndex &OrderBy,bool desc,int limit_num) {
    vector<pair<DTRow,DData>> cmp_pair;
    for(DColInter i(tables);!i.is_end();++i)if(where.getValue(i).isTrue()){
        vector<DData> row;
        for(DCol j:dCols){
            row.emplace_back(i.get(j._index));
        }
        cmp_pair.emplace_back(make_pair(DTRow(row),i.get(OrderBy)));
    }
    if(distinct){
        sort(cmp_pair.begin(),cmp_pair.end(),cmp_pair_less());
        int len=(cmp_pair.end()-cmp_pair.begin())-(unique(cmp_pair.begin(),cmp_pair.end(),row_same())-cmp_pair.begin());
        while(len--)cmp_pair.pop_back();
    }
    sort(cmp_pair.begin(),cmp_pair.end(),row_order(desc));
    DTable res(name,gen_varsDeclare(dCols,tables));
    if(limit_num<=0||limit_num>cmp_pair.size())limit_num=cmp_pair.size();
    res._table.reserve(limit_num);
    for(int i=0;i<limit_num;i++)res._table.emplace_back(cmp_pair[i].first);
    return res;
}

const DTRow &DTable::operator[](int index) const{
    return _table[index];
}

const vector<DVarDeclare> &DTable::varsDeclare() {
    return _varsDeclare;
}

void DTable::INSERT(vector<DData> values) {
    if(values.size()!=_vars_num)throw SQLError("104","Insert VARS Error.");
    for(int i=0;i<_vars_num;i++){
        values[i]=values[i].shift_type(_varsDeclare[i].type_id,_varsDeclare[i].size);
    }
    DTRow row(values);
    auto lower=_primary_key==-1?_table.end():lower_bound(_table.begin(),_table.end(),row,row_less(_primary_key));
    if(lower!=_table.end()&&row_eq(_primary_key)(*lower,row))throw SQLError("105","UNIQUE constraint failed.");
    _table.insert(lower,row);
    has_changed=1;
}
const int DEFAULT_CH_WORD_LENGTH=3;

int get_str_len(string str) {
    int res=0,pre_len=str.length();
    for(int i=0;i<pre_len;i++){
        if((int)str[i]<0){
            res+=2;
            i+=DEFAULT_CH_WORD_LENGTH-1;
        }
        else res+=1;
    }
    return res;
}

void put_repeat(ostream &os,char ch,int num){
    for(int i=0;i<num;i++)os<<ch;
}



ostream &operator<<(ostream &os,const DTable &table) {
    vector<int> col_max_len;
    col_max_len.reserve(table._vars_num);
    for(int i=0;i<table._vars_num;i++)col_max_len[i]=get_str_len(table._varsDeclare[i].name);
    for(const auto &i:table._table)
        for(int j=0;j<table._vars_num;j++){
            int len=get_str_len(i[j].shift_type(7).ptr());
            if(len>col_max_len[j])col_max_len[j]=len;
        }
    os<<'+';
    for(int i=0;i<table._vars_num;i++){
        put_repeat(os,'-',col_max_len[i]+4),os<<'+';
    }
    os<<'\n';

    os<<'|';
    for(int j=0;j<table._vars_num;j++){
        string out_str=table._varsDeclare[j].name;
        int self_len=get_str_len(out_str),blank_left=(col_max_len[j]+4-self_len)/2,
                blank_right=col_max_len[j]+4-blank_left-self_len;
        put_repeat(os,' ',blank_left);
        os<<out_str;
        put_repeat(os,' ',blank_right);
        os<<'|';
    }
    os<<'\n';

    os<<'+';
    for(int i=0;i<table._vars_num;i++){
        put_repeat(os,'-',col_max_len[i]+4),os<<'+';
    }
    os<<'\n';


    for(const auto &i:table._table){
        os<<'|';
        for(int j=0;j<table._vars_num;j++){
            string out_str=i[j].shift_type(7).ptr();
            int self_len=get_str_len(out_str),blank_left=(col_max_len[j]+4-self_len)/2,
                    blank_right=col_max_len[j]+4-blank_left-self_len;
            put_repeat(os,' ',blank_left);
            os<<out_str;
            put_repeat(os,' ',blank_right);
            os<<'|';
        }
        os<<'\n';
    }
    os<<'+';
    for(int i=0;i<table._vars_num;i++){
        put_repeat(os,'-',col_max_len[i]+4),os<<'+';
    }
    os<<'\n';
    cout<<"\033[33m"<<table._table.size()<<" row(s) in set."<<"\033[0m"<<endl;

    /*
    for(auto i:table._table){
        for(auto j=i._row.begin();j!=i._row.end()-1;j++)os<<*j<<"|";
        os<<*(i._row.end()-1)<<endl;
    }*/
    return os;
}

const string DTable::name()const {
    return _name;
}

const vector<DTRow> &DTable::table() const {return _table;}

const int DTable::changed() {return has_changed;}

void DTable::print_table_info(ostream &os) {
    os<<_name<<"("<<_varsDeclare[0];
    for(auto i=_varsDeclare.begin()+1;i!=_varsDeclare.end();i++)os<<","<<*i;
    os<<")\n";
}

int DTable::primary_key() {return _primary_key;}

void DTable::DELETE(const DExpr &where) {
    for(auto i=_table.begin();i!=_table.end();){
        if(where.getValue(*i).isTrue())i=_table.erase(i);
        else i++;
    }
    has_changed=1;
}

void DTable::UPDATE(vector<pair<DColIndex, DExpr*>> &update_list, const DExpr &where) {
    bool primary_key_change=0;
    for(auto &j:update_list){
        if(j.first._CIndex==_primary_key)primary_key_change=1;
    }
    if(!primary_key_change){
        for(auto i=_table.begin();i!=_table.end();i++)if(where.getValue(*i).isTrue()){
                for(const auto &j:update_list)(*i)._row[j.first._CIndex]=j.second->getValue(*i).shift_type(_varsDeclare[j.first._CIndex].type_id,_varsDeclare[j.first._CIndex].size);
            }
    }else{
        vector<DTRow> primary_key_changed_list;
        for(auto i=_table.begin();i!=_table.end();){
            if(where.getValue(*i).isTrue()) {
                for(const auto &j:update_list)(*i)._row[j.first._CIndex]=j.second->getValue(*i).shift_type(_varsDeclare[j.first._CIndex].type_id,_varsDeclare[j.first._CIndex].size);
                primary_key_changed_list.emplace_back(*i);
                i=_table.erase(i);
            }
            else i++;
        }
        for(const auto &i:primary_key_changed_list){
            auto k=lower_bound(_table.begin(),_table.end(),i,row_less(_primary_key));
            if(k!=_table.end()&&row_eq(_primary_key)(i,*k))throw SQLError("105","UNIQUE constraint failed.");
            _table.insert(k,i);
        }
    }
    has_changed=1;
}

bool cmp_pair_less::operator()(const pair<DTRow,DData> &a, const pair<DTRow,DData> &b) {
    int len=a.first._row.size();
    for(int i=0;i<len;i++)if(!((a.first._row[i]==b.first._row[i]).isTrue()))return (a.first._row[i]<b.first._row[i]).isTrue();
    return false;
}



bool row_less::operator()(const DTRow &a, const DTRow &b) {
    return (a._row[compare_key]<b._row[compare_key]).isTrue();
}
row_less::row_less(int key):compare_key(key) {}

bool row_eq::operator()(const DTRow &a, const DTRow &b) {
    return (a._row[compare_key]==b._row[compare_key]).isTrue();
}

row_eq::row_eq(int key):compare_key(key) {}

bool row_same::operator()(const pair<DTRow,DData> &a, const pair<DTRow,DData> &b) {
    if(a.first._row.size()!=b.first._row.size())return false;
    int size=a.first._row.size();
    for(int i=0;i<size;i++)if(!(a.first[i]==b.first[i]).isTrue())return false;
    return true;
}


DVarDeclare::DVarDeclare(short _type_id, short _size, const char *_name, bool _not_null,bool _primary_key,bool _auto_increment)
    :type_id(_type_id),size(_size),not_null(_not_null),primary_key(_primary_key),auto_increment(_auto_increment){
    if(strlen(_name)>=MAX_NAME_SIZE)throw SQLError("201","Name is out of length limit.");
    strcpy(name,_name);
}

DVarDeclare::DVarDeclare() {}




vector<DCol> gen_all(const vector<DTable *> &tables) {
    vector<DCol> res;
    if(tables.size()==1){
        for(int i=0;i<tables[0]->varsDeclare().size();i++){
            res.emplace_back(DCol(0,i,tables[0]->varsDeclare()[i].name));
        }
    }else{
        for(int i=0;i<tables.size();i++)
            for(int j=0;j<tables[i]->varsDeclare().size();j++){
                res.emplace_back(DCol(i,j,string(tables[i]->name()+"."+tables[i]->varsDeclare()[j].name).c_str()));
            }
    }
    return res;
}
vector<DVarDeclare> gen_varsDeclare(const vector<DCol> &dCols,const vector<DTable *> &tables){
    vector<DVarDeclare> res;
    for(DCol i:dCols)res.emplace_back(tables[i._index._TIndex]->varsDeclare()[i._index._CIndex].type_id,
                                      tables[i._index._TIndex]->varsDeclare()[i._index._CIndex].size,
                                      i._name);
    return res;
}


row_order::row_order(int _desc):desc(_desc) {}
bool row_order::operator()(const pair<DTRow, DData> &a, const pair<DTRow, DData> &b) {
    return (desc?a.second>b.second:a.second<b.second).isTrue();
}

ostream &operator<<(ostream &os, const DVarDeclare &var) {
    os<<var.name<<" ";
    switch (var.type_id) {
        case 1:os<<"BOOLEAN";break;
        case 2:os<<"SMALLINT";break;
        case 3:os<<"INTEGER";break;
        case 4:os<<"BIGINT";break;
        case 5:os<<"FLOAT";break;
        case 6:os<<"DOUBLE";break;
        case 7:os<<"VARCHAR("<<var.size<<")";break;
    }
    if(var.not_null)os<<" NOT NULL";
    if(var.primary_key)os<<" PRIMARY KEY";
    return os;
}
