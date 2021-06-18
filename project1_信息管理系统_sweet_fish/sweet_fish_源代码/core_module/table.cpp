//
// Created by hby on 2021/3/26.
//
#include "table.h"
#include "../error_solve/ErrorTB.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <QStandardItem>
#include <QHeaderView>

const int DEFAULT_CH_WORD_LENGTH=3;

using namespace std;

fixed_chars::fixed_chars() {}

fixed_chars::fixed_chars(string value) {
    if(value.length()>=20){throw(ErrorTB("Var_name is out of range of length.","101"));}
    strcpy(t,value.c_str());
}

fixed_chars::fixed_chars(const char *value) {
    if(strlen(value)>=20){throw(ErrorTB("Var_name is out of range of length.","102"));}
    strcpy(t,value);
}

table::table() {}


table::table(const char *src,bool open_map_accelerate,int second_primary_key) {
    ifstream f(src,ios::binary);
    if(!f.is_open()){
        throw(ErrorTB("File can't open."+string(src),"201"));
    }
    f.read((char *)&_vars_num,sizeof(_vars_num));
    f.read((char *)&_counter,sizeof(_counter));
    f.read((char *)&_pre_token, sizeof(_pre_token));
    fixed_chars var_name;int var_type,var_size;
    for(int i=0;i<_vars_num;i++){
        f.read(var_name.t,sizeof(var_name.t));
        f.read((char *)&var_type,sizeof(var_type));
        f.read((char *)&var_size,sizeof(var_size));
        _vars_name.push_back(var_name);
        _vars_type_id.push_back(var_type);
        _vars_size.push_back(var_size);
    }
    _open_map_accelerate=open_map_accelerate,_second_primary_key=second_primary_key;
    while(1){
        vector<db_type> tmp;
        bool judge_eof=0;
        for(int i=0;i<_vars_num;i++){
            db_type td(_vars_type_id[i],_vars_size[i]);
            f.read(td._protected_get_p(),_vars_size[i]);
            if(f.eof()){judge_eof=1;break;}
            tmp.push_back(td);
        }
        if(judge_eof)break;
        _content.push_back(tmp);
        if(_open_map_accelerate)_name_uid_map[tmp[_second_primary_key].get_string()+tmp[0].get_string()]=tmp[0].get_string();
    }
}

table::table(int vars_num, const vector<fixed_chars> &vars_name, const vector<int> &vars_type_id,
             const vector<int> &vars_size,int counter,char pre_token,bool open_map_accelerate) {
    if(vars_num!=vars_name.size()||vars_num!=vars_type_id.size()||vars_num!=vars_size.size()){
        throw(ErrorTB("Create table with false var_information.","301"));}
    _vars_num=vars_num,_counter=counter,_pre_token=pre_token;
    _vars_name.assign(vars_name.begin(),vars_name.end());
    _vars_type_id.assign(vars_type_id.begin(),vars_type_id.end());
    _vars_size.assign(vars_size.begin(),vars_size.end());
    _open_map_accelerate=open_map_accelerate;
}

void table::cp_head(const table *other) {
    _vars_num=other->_vars_num,_counter=other->_counter,_pre_token=other->_pre_token;
    _vars_name.assign(other->_vars_name.begin(),other->_vars_name.end());
    _vars_type_id.assign(other->_vars_type_id.begin(),other->_vars_type_id.end());
    _vars_size.assign(other->_vars_size.begin(),other->_vars_size.end());
}

void table::write_file(const char *src)const{
    ofstream f(src,ios::binary|ios::ate);
    if(!f.is_open()){
        throw(ErrorTB("File can't open."+string(src),"202"));}
    f.write((char *)&_vars_num, sizeof(_vars_num));
    f.write((char *)&_counter, sizeof(_counter));
    f.write((char *)&_pre_token, sizeof(_pre_token));
    for(int i=0;i<_vars_num;i++){
        f.write(_vars_name[i].t,sizeof(_vars_name[i].t));
        f.write((char *)&_vars_type_id[i],sizeof(_vars_type_id[i]));
        f.write((char *)&_vars_size[i],sizeof(_vars_size[i]));
    }
    for(auto i:_content)
        for(auto j:i)
            f.write(j._protected_get_p(),j.get_size());
}

bool table::empty() const{
    return _content.empty();
}

db_type table::generate_id() {
    _counter++;
    char gen_id[7];
    snprintf(gen_id,7,"%c%05d",_pre_token,_counter);
    return db_type(1,7,string(gen_id));
}

void table::insert(const vector<db_type> &values) {
    if(values.size()!=_vars_num){
        throw(ErrorTB("values size error!","302"));}
    vector<db_type> res;
    for(int i=0;i<_vars_num;i++) {
        if(values[i].get_type_id()==-1&&values[i].get_size()==1)res.push_back(generate_id());
        else res.push_back(values[i]);
        if (res[i].get_type_id() != _vars_type_id[i] || res[i].get_size() != _vars_size[i])
            throw(ErrorTB("values type error!","303"));
    }
    _content.push_back(res);
    if(_open_map_accelerate){
        _name_uid_map[res[_second_primary_key].get_string()+res[0].get_string()]=res[0].get_string();
    }
}

void table::tr_sort(int td_key, bool sort_lesser) {
    sort(_content.begin(),_content.end(),
         [td_key,sort_lesser](const vector<db_type> &a,const vector<db_type> &b)
         {return sort_lesser?a[td_key]<b[td_key]:a[td_key]>b[td_key];});
}

table table::sub_table(const vector<int> &td_vars)const{
    vector<fixed_chars> vars_name;vector<int> type_id,type_size;
    for(int i:td_vars){
        if(i>=_vars_num)throw(ErrorTB("Index is out of range!.","304"));
        vars_name.push_back(_vars_name[i]);
        type_id.push_back(_vars_type_id[i]);
        type_size.push_back(_vars_size[i]);
    }

    table res(td_vars.size(),vars_name,type_id,type_size);
    for(auto i:_content) {
        vector<db_type> tmp;
        for (auto j:td_vars)tmp.push_back(i[j]);
        res.insert(tmp);
    }
    return res;


}

table table::tr_sorted(int td_key, bool sort_lesser)const{
    table res(*this);
    res.tr_sort(td_key,sort_lesser);
    return res;
}

table table::select(int td_key,const db_type &value, bool (*judge)(const db_type&, const db_type&))const{
    if(td_key>_vars_num||value.get_type_id()!=_vars_type_id[td_key]||value.get_size()!=_vars_size[td_key])
        throw(ErrorTB("values types error.","305"));
    table res;
    res.cp_head(this);
    //首变量检索二分加速
    if(td_key==0&&judge==db_type_equal){
        auto begin_p=_content.begin();
        int l=0,r=_content.end()-begin_p;
        while(l<r){
            int mid=(l+r)>>1;
            if((*(begin_p+mid))[0]<value)l=mid+1;
            else r=mid;
        }
        auto i=begin_p+l;
        if(i!=_content.end()&&(*i)[0]==value)res._content.push_back(*i);
        return res;
    }else if(_open_map_accelerate&&td_key==_second_primary_key&&judge==db_type_equal){
        auto i=_name_uid_map.lower_bound(value.get_string());
        while(i!=_name_uid_map.end()){
            table tmp_get_tr=select(0,{_vars_type_id[0],_vars_size[0],i->second},judge);
            if(!judge(tmp_get_tr.get_item(0,td_key),value))break;
            res._content.push_back(tmp_get_tr._content[0]);
            i++;
        }
        return res;
    }
    for(auto i:_content)
        if(judge(i[td_key],value)){
            res._content.push_back(i);
        }

    return res;
}

void table::update(int td_key,const db_type &pre_value,int to_key, const db_type &to_value, bool (*judge)(const db_type &, const db_type &)) {
    if(td_key>_vars_num)throw(ErrorTB("values types error.","306"));
    if(_vars_type_id[td_key]!=pre_value.get_type_id()||_vars_size[td_key]!=pre_value.get_size()
    ||_vars_type_id[to_key]!=to_value.get_type_id()&&_vars_type_id[to_key]!=to_value.get_type_id()-5||_vars_size[to_key]!=to_value.get_size())
        throw(ErrorTB("values types error.","307"));
    //首变量检索二分加速
    if(td_key==0&&judge==db_type_equal){
        auto begin_p=_content.begin();
        int l=0,r=_content.end()-begin_p;
        while(l<r){
            int mid=(l+r)>>1;
            if((*(begin_p+mid))[0]<pre_value)l=mid+1;
            else r=mid;
        }
        auto i=begin_p+l;
        if(i!=_content.end()&&judge((*i)[td_key],pre_value)){
            if(to_value.get_type_id()==_vars_type_id[to_key])(*i)[to_key]=to_value;
            if(to_value.get_type_id()==_vars_type_id[to_key]+5)(*i)[to_key]+=to_value;
        }
        return;
    }else if(_open_map_accelerate&&td_key==_second_primary_key&&judge==db_type_equal){
        auto i=_name_uid_map.lower_bound(pre_value.get_string());
        while(i!=_name_uid_map.end()){
            table tmp_get_tr=select(0,{_vars_type_id[0],_vars_size[0],i->second},judge);
            if(!judge(tmp_get_tr.get_item(0,td_key),pre_value))break;
            update(0,{1,_vars_size[0],i->second},to_key,to_value,judge);
            i++;
        }
        return;
    }
    for(auto i=_content.begin();i!=_content.end();i++)
        if(judge((*i)[td_key],pre_value)){
            if(to_value.get_type_id()==_vars_type_id[to_key])(*i)[to_key]=to_value;
            if(to_value.get_type_id()==_vars_type_id[to_key]+5)(*i)[to_key]+=to_value;
        }
}

void table::Delete(int td_key, const db_type &value, bool (*judge)(const db_type &, const db_type &)) {
    if(td_key>_vars_num||value.get_type_id()!=_vars_type_id[td_key]||value.get_size()!=_vars_size[td_key])
        throw(ErrorTB("values types error.","308"));
    //首变量检索二分加速
    if(td_key==0&&judge==db_type_equal){
        auto begin_p=_content.begin();
        int l=0,r=_content.end()-begin_p;
        while(l<r){
            int mid=(l+r)>>1;
            if((*(begin_p+mid))[0]<value)l=mid+1;
            else r=mid;
        }
        auto i=begin_p+l;
        if(i!=_content.end()&&judge((*i)[td_key],value))
            _content.erase(i);
        return;
    }else if(_open_map_accelerate&&td_key==_second_primary_key&&judge==db_type_equal){
        auto i=_name_uid_map.lower_bound(value.get_string());
        while(i!=_name_uid_map.end()){
            table tmp_get_tr=select(0,{_vars_type_id[0],_vars_size[0],i->second},judge);
            if(!judge(tmp_get_tr.get_item(0,td_key),value))break;
            Delete(0,{_vars_type_id[0],_vars_size[0],i->second},judge);
            i=_name_uid_map.erase(i);
        }
        return;
    }
    for(auto i=_content.begin();i!=_content.end();)
        if(judge((*i)[td_key],value)){
            i=_content.erase(i);
        }else i++;
}

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

void put_repeat(char ch,int num){
    for(int i=0;i<num;i++)putchar(ch);
}

void table::show()const{
    vector<int> td_max_len(_vars_size);
    for(int i=0;i<_vars_num;i++)
        td_max_len[i]=get_str_len(_vars_name[i].t);
    for(auto i:_content)
        for(int j=0;j<_vars_num;j++)
            if(get_str_len(i[j].show_str())>td_max_len[j])
                td_max_len[j]=get_str_len(i[j].show_str());

    putchar('+');
    for(int i=0;i<_vars_num;i++){
        put_repeat('-',td_max_len[i]+4),putchar('+');
    }
    putchar('\n');

    putchar('|');
    for(int j=0;j<_vars_num;j++){
        string out_str=_vars_name[j].t;
        int self_len=get_str_len(out_str),blank_left=(td_max_len[j]+4-self_len)/2,
                blank_right=td_max_len[j]+4-blank_left-self_len;
        put_repeat(' ',blank_left);
        printf("%s",out_str.c_str());
        put_repeat(' ',blank_right);
        putchar('|');
    }
    putchar('\n');

    putchar('+');
    for(int i=0;i<_vars_num;i++){
        put_repeat('-',td_max_len[i]+4),putchar('+');
    }
    putchar('\n');

    for(auto i:_content){
        putchar('|');
        for(int j=0;j<_vars_num;j++){
            string out_str=i[j].show_str();
            int self_len=get_str_len(out_str),blank_left=(td_max_len[j]+4-self_len)/2,
                blank_right=td_max_len[j]+4-blank_left-self_len;
                put_repeat(' ',blank_left);
                printf("%s",out_str.c_str());
                put_repeat(' ',blank_right);
                putchar('|');
        }
        putchar('\n');
        putchar('+');
        for(int i=0;i<_vars_num;i++){
            put_repeat('-',td_max_len[i]+4),putchar('+');
        }
        putchar('\n');
    }
    putchar('\n');
}

void table::show_details()const{
    printf("*******************************************************************************\n");
    for(auto i:_content){
        for(int j=0;j<_vars_num;j++)cout<<_vars_name[j].t<<": "<<i[j].show_str()<<endl;
        printf("*******************************************************************************\n");
    }
}

void table::show_in_gui(QTableView *tableView)const
{
    QStandardItemModel *model=new QStandardItemModel;
    QStringList vars_name;
    for(auto i:_vars_name)vars_name.append(i.t);
    model->setHorizontalHeaderLabels(vars_name);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i=0;i<_content.size();i++)
        for(int j=0;j<_vars_num;j++)
            model->setItem(i,j,new QStandardItem(_content[i][j].show_str().c_str()));
    tableView->setModel(model);
}

const db_type table::get_item(int i, int j) const{
    if(i>_content.size()||j>_vars_num){cout<<"index out of range!\nError_code:table::010";exit(-1);}
    return _content[i][j];
}

table table::limit(int limit_num)const{
    table res;
    res.cp_head(this);
    int max_r=limit_num;
    if(_content.size()<max_r)max_r=_content.size();
    for(int i=0;i<max_r;i++)
        res._content.push_back(_content[i]);
    return res;
}


