//
// Created by hby on 2021/4/26.
//

#ifndef SQL_INTERPRETOR_PARSER_H
#define SQL_INTERPRETOR_PARSER_H

#include <string>
#include <queue>
#include <regex>
#include <iostream>
#include "DObject.h"
#include "SQLError.h"
#include "DCol.h"
#include "DExpr.h"
#include "DFunc.h"

using namespace std;
/*
class DToken: public DObject{
    short _num;
    string _name;
public:
    DToken(int num,string name):DObject(30),_num(num),_name(name){}
    ~DToken()=default;
    friend ostream &operator<<(ostream &os,const DToken &dToken){return os<<dToken._name,os;}
};

queue<DObject *> tokens;
void clear_tokens(){
    while(!tokens.empty()){delete tokens.front();tokens.pop();}
}


regex integer_token("^(\\+|-)?\\d+$"),float_token("^(\\+|-)?\\d+\\.\\d+$"),str_token("\"((.|\\n)*)\"");
regex add_token("^\\+$"),sub_token("^-$");
regex exit_token("\\.exit", wregex::icase),
    end_token("^;$"),
    comma_token("^,$"),
    all_token("^\\*$"),
    lpan_token("^\\($"),
    rpan_token("^\\)$"),
    create_token("^CREATE$",wregex::icase),
    table_token("^TABLE$",wregex::icase),
    select_token("^SELECT$",wregex::icase),
    from_token("^FROM$",wregex::icase),
    where_token("^WHERE$",wregex::icase);
regex table_name_token("^[a-zA-z][0-9]+$");
regex boolean_var_token("^BOOLEAN$",wregex::icase),
    integer_var_token("^(INT)|(INTEGER)$",wregex::icase),
    double_var_token("^DOUBLE$",wregex::icase),
    varchar_var_token("^varchar$",wregex::icase);

void begin_parser();

void in_token(const string &token,bool &end_of_sentence){
    end_of_sentence=0;
    if(regex_match(token,exit_token)){
        if(tokens.empty())exit(0);
        else throw SQLError("401","Unknown token: "+token);
    }
    else if(regex_match(token,end_token)){tokens.push(new DToken(0,";"));end_of_sentence=1;return begin_parser();}
    else if(regex_match(token,comma_token)){tokens.push(new DToken(1,","));return;}
    else if(regex_match(token,all_token)){tokens.push(new DToken(2,"*"));return;}
    else if(regex_match(token,lpan_token)){tokens.push(new DToken(3,"("));return;}
    else if(regex_match(token,rpan_token)){tokens.push(new DToken(4,")"));return;}
    else if(regex_match(token,select_token)){tokens.push(new DToken(11,"SELECT"));return;}
    else if(regex_match(token,from_token)){tokens.push(new DToken(12,"FROM"));return;}
    else if(regex_match(token,where_token)){tokens.push(new DToken(13,"WHERE"));return;}
    else if(regex_match(token,boolean_var_token)){tokens.push(new DToken(21,"BOOLEAN"));return;}
    else if(regex_match(token,integer_var_token)){tokens.push(new DToken(23,"INTEGER"));return;}
    else if(regex_match(token,double_var_token)){tokens.push(new DToken(26,"DOUBLE"));return;}
    else if(regex_match(token,varchar_var_token)){tokens.push(new DToken(27,"varchar"));return;}
    else if(regex_match(token,integer_token)){tokens.push(new DInteger(atoi(token.c_str())));return;}
    else if(regex_match(token,float_token)){tokens.push(new DDouble(atof(token.c_str())));return;}
    else if(regex_match(token,str_token)){tokens.push(new Dvarchar(token.substr(1,token.size()-2).c_str()));return;}
    throw SQLError("401","Unknown token: "+token);
}


const int MAX_BUFFER_SIZE=500;
static char buffer[MAX_BUFFER_SIZE];
static int buffer_top=0;
static bool in_str=0;
void clear_buffer(bool &end_of_sentence){
    buffer[buffer_top]='\0';
    if(buffer_top)in_token(buffer,end_of_sentence);
    buffer_top=0;
}
void in_buffer(char ch){buffer[buffer_top++]=ch;}
void in_char_tokens(char ch,bool &end_of_sentence){
    if(ch=='\"'){
        in_buffer(ch);
        end_of_sentence=0;
        if(in_str)clear_buffer(end_of_sentence),in_str=0;
        else in_str=1;
        return;
    }
    if(in_str)return in_buffer(ch);
    if(ch==' '||ch=='\t'||ch=='\n')return clear_buffer(end_of_sentence);
    if(ch==';'||ch==','||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'){
        clear_buffer(end_of_sentence);
        in_buffer(ch);
        clear_buffer(end_of_sentence);
        return;
    }
    in_buffer(ch);
    //if(buffer_top>=2)
}

void debug(){
    //in_token("12"),in_token("1.12"),in_token("\"12121  4sss\"");
    //in_token("select"),in_token("FROM"),in_token(";");
    while(!tokens.empty()){
        DObject *ptr=tokens.front();
        if(ptr->get_type_id()>=1&&ptr->get_type_id()<=7){
            cout<<*(DData *)tokens.front()<<" ";
        }
        else{
            cout<<*(DToken *)tokens.front()<<" ";
        }
        delete tokens.front();
        tokens.pop();
    }
    cout<<endl;
}

void begin_parser(){
    debug();
    clear_tokens();SELECT 1 FROM WHERE 1;
}

class DSyntaxTree: public DObject{
private:
    int _syntax_id;
public:
    DSyntaxTree(int syntax_id):DObject(40),_syntax_id(syntax_id){}
    ~DSyntaxTree()=default;
};

class DSyntaxList: public DSyntaxTree{

};


*/
/*
void init_tables(){

}
*/


regex integer_token("^\\s*((\\+|-)?\\d+)\\s*$"),float_token("^\\s*((\\+|-)?\\d+\\.\\d+)\\s*$"),str_token("^\\s*\"((.|\\n)*)\"\\s*$");
regex var_token("^\\s*([a-zA-Z_][a-zA-Z_\\-0-9]*)\\s*$"),table_var_token("^\\s*([a-zA-Z_][a-zA-Z_\\-\\.0-9]*)\\s*$"),all_cols_token("^\\s*\\*\\s*$");
regex boolean_var_declare("^\\s*(.*?)\\s+BOOLEAN(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase),
        smallint_var_declare("^\\s*(.*?)\\s+SMALLINT(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase),
        integer_var_declare("^\\s*(.*?)\\s+((INTEGER)|(INT))(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase),
        bigint_var_declare("^\\s*(.*?)\\s+BIGINT(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase),
        float_var_declare("^\\s*(.*?)\\s+FLOAT(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase),
        double_var_declare("^\\s*(.*?)\\s+DOUBLE(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase),
        varchar_var_declare("^\\s*(.*?)(\\s+VARCHAR\\s*\\(\\s*(\\d+)\\s*\\))?(\\s+NOT\\s+NULL)?(\\s+PRIMARY\\s+KEY)?(\\s+AUTO_INCREMENT)?\\s*$", wregex::icase);
regex create_table_sentence("^\\s*CREATE\\s+TABLE\\s+(.+?)\\s*\\((.+?)\\)\\s*;\\s*$", wregex::icase),
        insert_sentence("^\\s*INSERT\\s+INTO\\s+(.+?)\\s+VALUES\\s*\\(\\s*(.+?)\\s*\\)\\s*;\\s*$", wregex::icase),
        select_sentence("^\\s*SELECT\\s+(\\s*DISTINCT\\s*)?(.+?)\\s+FROM\\s+(.+?)\\s*(\\s+WHERE\\s+(.+?))?(\\s+ORDER\\s+BY\\s+(.+?)(\\s+ASC)?(\\s+DESC)?)?(\\s+LIMIT\\s+(.+?)\\s*)?\\s*;\\s*$", wregex::icase),
        delete_sentence("^\\s*DELETE\\s+FROM\\s+(.+?)\\s+WHERE\\s+(.+?)\\s*;\\s*$", wregex::icase),
        update_sentence("^\\s*UPDATE\\s+(.+?)\\s+SET\\s+(.+?)(\\s+WHERE\\s+(.+?))?\\s*;\\s*$", wregex::icase),
        update_cell("^\\s*(.+?)=(.+?)\\s*$"),
        drop_table_sentence("^\\s*DROP\\s+TABLE\\s*(\\s+IF\\s+EXISTS)?\\s*([^\\s]+?)\\s*;\\s*$", wregex::icase),
        show_tables_sentence("^\\s*SHOW\\s+TABLES\\s*;\\s*$", wregex::icase);
regex l_p_token("^\\($"),
    r_p_token("^\\)$"),
    add_token("^\\+$"),
    sub_token("^-$"),
    mul_token("^\\*$"),
    div_token("^/$"),
    less_token("^<$"),
    greater_token("^>$"),
    eq_token("^==?$"),
    le_token("^<=$"),
    ge_token("^>=$"),
    neq_token("^(!=)|(<>)$"),
    and_token("^AND$",wregex::icase),
    like_token("^LIKE$",wregex::icase),
    or_token("^OR$",wregex::icase);

istream &is=std::cin;
ostream &os=std::cout;

regex end_sentence_token("(.|\\n)*;\\s*$"),exit_sentence("^\\s*exit\\s*$");

map<string,DTable*> table_env;

string get_var_name(const string &name);
DData get_data(const string &data);
DData *pget_data(const string &data);
void split(const string& s,vector<string>& sv,const char flag = ' ');
void split_without_none(const string& s,vector<string>& sv,const char flag = ' ');
DVarDeclare getVarDeclare(const string &str);
void get_table_list(const string &str,vector<DTable *> &pTables);
DCol get_col(const string &str,const map<string,DColIndex> &dictCols);

bool show_tables(const string &sentence);
bool create_table(const string &sentence);
bool insert(const string &sentence);
bool delete_from(const string &sentence);
bool drop_table(const string &sentence);
bool update(const string &sentence);

void parser(string &sentence);


DColIndex get_col_index(const string &str,const map<string,DColIndex> &dictCols){
    smatch match;
    if(!regex_match(str,match,table_var_token))throw SQLError("408","Col name token error: "+str);
    auto iter=dictCols.find(match[1]);
    if(iter==dictCols.end())throw SQLError("409","Unknown col: "+str);
    return DColIndex(iter->second._TIndex,iter->second._CIndex);
}

DColIndex *pget_col_index(const string &str,const map<string,DColIndex> &dictCols){
    smatch match;
    if(!regex_match(str,match,table_var_token))throw SQLError("408","Col name token error: "+str);
    auto iter=dictCols.find(match[1]);
    if(iter==dictCols.end())throw SQLError("409","Unknown col: "+str);
    return new DColIndex(iter->second._TIndex,iter->second._CIndex);
}

void get_cols_list(const string &str,vector<DCol> &cols,const map<string,DColIndex> &dictCols){
    vector<string> tablesToken;
    split(str,tablesToken,',');
    smatch match;
    for(auto i:tablesToken){
        cols.emplace_back(get_col(i,dictCols));
    }

}

void load_col_env(const vector<DTable *> &pTables,map<string,DColIndex> &res){
    vector<string> deleted;
    for(int i=0;i<pTables.size();i++)
        for(int j=0;j<pTables[i]->varsDeclare().size();j++){
        res.insert(make_pair(string(pTables[i]->name()+"."+pTables[i]->varsDeclare()[j].name),DColIndex(i,j)));
        if(res.find(pTables[i]->varsDeclare()[j].name)==res.end())res.insert(make_pair(string(pTables[i]->varsDeclare()[j].name),DColIndex(i,j)));
        else deleted.emplace_back(pTables[i]->varsDeclare()[j].name);
    }
    for(const auto str:deleted){
        auto iter=res.find(str);
        if(iter!=res.end())res.erase(iter);
    }
}

vector<pair<regex,string>> replace_list{
        make_pair(regex("\\(")," ( "),
        make_pair(regex("\\)")," ) "),
        make_pair(regex("\\+")," + "),
        make_pair(regex("-")," - "),
        make_pair(regex("\\*")," * "),
        make_pair(regex("/")," / "),
        make_pair(regex("=")," = "),
        make_pair(regex("<")," < "),
        make_pair(regex(">")," > "),
        make_pair(regex("!")," ! "),
        make_pair(regex("=  =")," == "),
        make_pair(regex("<  =")," <= "),
        make_pair(regex(">  =")," >= "),
        make_pair(regex("!  =")," != "),
        make_pair(regex("<  >")," <> "),
        make_pair(regex(" and ",wregex::icase)," AND "),
        make_pair(regex(" or ",wregex::icase)," OR "),
        make_pair(regex("^\\s*-\\s*")," -"),
        make_pair(regex("<\\s*-\\s*"),"< -"),
        make_pair(regex(">\\s*-\\s*"),"> -"),
        make_pair(regex("=\\s*-\\s*"),"= -"),
        make_pair(regex("AND\\s*-\\s*"),"AND -"),
        make_pair(regex("OR\\s*-\\s*"),"OR -"),
        make_pair(regex("\\(\\s*(-)\\s*")," ( -")
};

void get_expr(string str,const map<string,DColIndex> &dictCols,DExpr &expr){
    for(auto &i:replace_list)str=regex_replace(str,i.first,i.second);
    vector<string> tokens;
    split_without_none(str,tokens);
    for(auto i:tokens){
        if(regex_match(i,l_p_token))expr.push(new DLPToken());
        else if(regex_match(i,r_p_token))expr.push(new DRPToken());
        else if(regex_match(i,add_token))expr.push(new addFunc());
        else if(regex_match(i,sub_token))expr.push(new subFunc());
        else if(regex_match(i,mul_token))expr.push(new mulFunc());
        else if(regex_match(i,div_token))expr.push(new divFunc());
        else if(regex_match(i,less_token))expr.push(new lessFunc());
        else if(regex_match(i,greater_token))expr.push(new greaterFunc());
        else if(regex_match(i,eq_token))expr.push(new eqFunc());
        else if(regex_match(i,le_token))expr.push(new leFunc());
        else if(regex_match(i,ge_token))expr.push(new geFunc());
        else if(regex_match(i,neq_token))expr.push(new neqFunc());
        else if(regex_match(i,and_token))expr.push(new andFunc());
        else if(regex_match(i,or_token))expr.push(new orFunc());
        else if(regex_match(i,like_token))expr.push(new likeFunc());
        else if(regex_match(i,table_var_token))expr.push(pget_col_index(i,dictCols));
        else if(regex_match(i,integer_token)||regex_match(i,float_token)||regex_match(i,str_token))expr.push(pget_data(i));
    }
    expr.end_expr();

}


bool select(const string &sentence){
    smatch match;
    if(!regex_match(sentence,match,select_sentence))return false;
    //tables_list
    vector<DTable *> pTables;
    get_table_list(match[3],pTables);
    //load all cols
    map<string,DColIndex> dictCols;
    load_col_env(pTables,dictCols);
    //distinct
    bool distinct=match[1].matched;
    //select cols
    vector<DCol> cols;
    if(regex_match(match[2].str(),all_cols_token))cols=gen_all(pTables);
    else get_cols_list(match[2],cols,dictCols);
    //where expression
    DExpr where_expr;
    if(match[5].matched)get_expr(match[5],dictCols,where_expr);
    else getTrueExpr(where_expr);
    //order by col
    DColIndex order_by(0,pTables[0]->primary_key()==-1?0:pTables[0]->primary_key());
    if(match[7].matched)order_by=get_col_index(match[7],dictCols);
    //asc(default)/desc
    bool desc=match[9].matched;
    //limit
    int limit_num=-1;
    if(match[10].matched){
        limit_num=*(int*)get_data(match[11]).shift_type(3).ptr();
    }
    os<<SELECT("",distinct,cols,pTables,where_expr,order_by,desc,limit_num);
    return true;
}


void init_parser(){
    fstream tables_inf("TABLES_LIST.tb",ios::binary|ios::in|ios::out);
    if(!fstream("TABLES_LIST.tb",ios::binary|ios::in|ios::out).is_open()){
        DTable TABLES_LIST("TABLES_LIST",{
            DVarDeclare{7,30,"TABLE_NAME",true,true}
        });
        TABLES_LIST.INSERT({DVarchar("TABLES_LIST")});
        TABLES_LIST.write_file("TABLES_LIST.tb");
    }
    DTable *TABLES_LIST=new DTable("TABLES_LIST.tb");
    for(const auto &i:TABLES_LIST->table())table_env.insert(make_pair(string(i[0].ptr()),new DTable((string(i[0].ptr())+".tb").c_str())));
}

void save_tables(){
    for(const auto &i:table_env){
        if(i.second->changed())i.second->write_file((i.first+".tb").c_str());
        delete i.second;
    }
}




string get_var_name(const string &name){
    smatch match;
    if(!regex_match(name,match,var_token))throw SQLError("401","False Var Name: "+name);
    return match[1];
}


DData get_data(const string &data){
    smatch match;
    if(regex_match(data,match,integer_token))return DInteger(stoi(match[1]));
    else if(regex_match(data,match,float_token))return DDouble(stof(match[1]));
    else if(regex_match(data,match,str_token))return DVarchar(match[1].str().c_str());
    throw SQLError("404","Unknown data token: "+data);
}


DData *pget_data(const string &data){
    smatch match;
    if(regex_match(data,match,integer_token))return new DInteger(stoi(match[1]));
    else if(regex_match(data,match,float_token))return new DDouble(stof(match[1]));
    else if(regex_match(data,match,str_token))return new DVarchar(match[1].str().c_str());
    throw SQLError("404","Unknown data token: "+data);
}

void split(const string& s,vector<string>& sv,const char flag) {
    sv.clear();
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        sv.push_back(temp);
    }
    return;
}

void split_without_none(const string& s,vector<string>& sv,const char flag) {
    sv.clear();
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        if(!temp.empty())sv.push_back(temp);
    }
    return;
}

const int MAX_VARCHAR_SIZE=1000;
DVarDeclare getVarDeclare(const string &str){
    smatch match;
    if(regex_match(str,match,boolean_var_declare))return DVarDeclare(1,1,get_var_name(match[1].str()).c_str(),match[2].matched,match[3].matched,match[4].matched);
    else if(regex_match(str,match,smallint_var_declare))return DVarDeclare(2,2,get_var_name(match[1].str()).c_str(),match[2].matched,match[3].matched,match[4].matched);
    else if(regex_match(str,match,integer_var_declare))return DVarDeclare(3,4,get_var_name(match[1].str()).c_str(),match[5].matched,match[6].matched,match[7].matched);
    else if(regex_match(str,match,bigint_var_declare))return DVarDeclare(4,8,get_var_name(match[1].str()).c_str(),match[2].matched,match[3].matched,match[4].matched);
    else if(regex_match(str,match,float_var_declare))return DVarDeclare(5,4,get_var_name(match[1].str()).c_str(),match[2].matched,match[3].matched,match[4].matched);
    else if(regex_match(str,match,double_var_declare))return DVarDeclare(6,8,get_var_name(match[1].str()).c_str(),match[2].matched,match[3].matched,match[4].matched);
    else if(regex_match(str,match,varchar_var_declare)){
        if(match[2].matched)return DVarDeclare(7,stoi(match[3]),get_var_name(match[1].str()).c_str(),match[4].matched,match[5].matched,match[6].matched);
        else return DVarDeclare(7,MAX_VARCHAR_SIZE,get_var_name(match[1].str()).c_str(),match[4].matched,match[5].matched,match[6].matched);
    }
    throw SQLError("403","Unknown varDeclare: "+str);
}

bool show_tables(const string &sentence){
    if(!regex_match(sentence,show_tables_sentence))return false;
    os<<table_env.size()-1<<" table(s):\n";
    for(auto &i:table_env)if(i.first!="TABLES_LIST")i.second->print_table_info(cout);
    return true;
}

bool create_table(const string &sentence){
    smatch match;
    if(!regex_match(sentence,match,create_table_sentence))return false;
    string table_name=get_var_name(match[1]);
    if(table_env.find(table_name)!=table_env.end())throw SQLError("402","TABLE "+table_name+" has existed.");
    vector<string> varsDeclareToken;
    split(match[2],varsDeclareToken,',');
    vector<DVarDeclare> varsDeclare;
    varsDeclare.reserve(varsDeclareToken.size());
    for(string str:varsDeclareToken){
        varsDeclare.emplace_back(getVarDeclare(str));
    }
    table_env.insert(make_pair(table_name,new DTable(table_name,varsDeclare)));
    table_env["TABLES_LIST"]->INSERT({DVarchar(table_name.c_str())});
    return true;
}

bool insert(const string &sentence){
    smatch match;
    if(!regex_match(sentence,match,insert_sentence))return false;
    string table_name=get_var_name(match[1]);
    if(table_env.find(table_name)==table_env.end())throw SQLError("405","TABLE "+table_name+" doesn't existed.");
    vector<string> dataTokenStr;
    split(match[2],dataTokenStr,',');
    vector<DData> values;
    values.reserve(dataTokenStr.size());
    for(const auto& str:dataTokenStr){
        values.emplace_back(get_data(str));
    }
    table_env.find(table_name)->second->INSERT(values);
    return true;
}

void get_table_list(const string &str,vector<DTable *> &pTables){
    vector<string> varsToken;
    split(str,varsToken,',');
    smatch match;
    for(auto i:varsToken){
        if(!regex_match(i,match,var_token))throw SQLError("406","Table name token error: "+i);
        auto iter=table_env.find(match[1]);
        if(iter==table_env.end())throw SQLError("407","Unknown table: "+i);
        pTables.emplace_back(iter->second);
    }
}

void parser(string &sentence){
    sentence=regex_replace(sentence,regex("PRIMARY_KEY",wregex::icase),"PRIMARY KEY");
    if(show_tables(sentence));
    else if(create_table(sentence))cout<<"\033[33m"<<"Create table successfully!"<<"\033[0m"<<endl;
    else if(insert(sentence))cout<<"\033[33m"<<"Insert into table successfully!"<<"\033[0m"<<endl;
    else if(delete_from(sentence))cout<<"\033[33m"<<"Delete from table successfully!"<<"\033[0m"<<endl;
    else if(drop_table(sentence))cout<<"\033[33m"<<"Drop table successfully!"<<"\033[0m"<<endl;
    else if(update(sentence))cout<<"\033[33m"<<"Update table successfully!"<<"\033[0m"<<endl;
    else if(select(sentence));
    else throw SQLError("801","Unknown sentence : "+sentence);
}

DCol get_col(const string &str,const map<string,DColIndex> &dictCols){
    smatch match;
    if(!regex_match(str,match,table_var_token))throw SQLError("408","Col name token error: "+str);
    auto iter=dictCols.find(match[1]);
    if(iter==dictCols.end())throw SQLError("409","Unknown col: "+str);
    return DCol(iter->second._TIndex,iter->second._CIndex,str.c_str());
}

bool delete_from(const string &sentence){
    smatch match;
    if(!regex_match(sentence,match,delete_sentence))return false;
    //tables_list
    vector<DTable *> pTables;
    get_table_list(match[1],pTables);
    if(pTables.size()!=1)throw SQLError("407","Unknown table: "+match[1].str());
    //load all cols
    map<string,DColIndex> dictCols;
    load_col_env(pTables,dictCols);
    //where expression
    DExpr where_expr;
    get_expr(match[2],dictCols,where_expr);
    pTables[0]->DELETE(where_expr);
    return true;
}

bool drop_table(const string &sentence){
    smatch match;
    if(!regex_match(sentence,match,drop_table_sentence))return false;
    bool if_exist=match[1].matched;
    string table_name=get_var_name(match[2]);
    auto i=table_env.find(table_name);
    if(i==table_env.end()){
        if(!if_exist)throw SQLError("410","Table doesn't exist: "+match[2].str());
        return true;
    }
    delete_from("DELETE FROM TABLES_LIST WHERE TABLE_NAME=\""+table_name+"\";");
    if(ifstream(table_name+".tb").is_open())system(("rm "+table_name+".tb").c_str());
    delete i->second;
    table_env.erase(i);
    return true;
}

bool update(const string &sentence){
    smatch match;
    if(!regex_match(sentence,match,update_sentence))return false;
    //tables_list
    vector<DTable *> pTables;
    get_table_list(match[1],pTables);
    if(pTables.size()!=1)throw SQLError("407","Unknown table: "+match[1].str());
    //load all cols
    map<string,DColIndex> dictCols;
    load_col_env(pTables,dictCols);
    vector<string> update_cell_list_str;
    split(match[2],update_cell_list_str,',');
    vector<pair<DColIndex,DExpr*>> update_cell_list;
    for(const string &i:update_cell_list_str){
        smatch match1;
        if(!regex_match(i,match1,update_cell))throw SQLError("411","Update error : "+i);
        DExpr *tmp=new DExpr;
        get_expr(match1[2],dictCols,*tmp);
        update_cell_list.emplace_back(make_pair(get_col_index(match1[1],dictCols),tmp));
    }
    //where expression
    DExpr where_expr;
    if(match[3].matched)get_expr(match[4],dictCols,where_expr);
    else getTrueExpr(where_expr);
    pTables[0]->UPDATE(update_cell_list,where_expr);
    for(auto i:update_cell_list)delete i.second;
    return true;
}

#endif //SQL_INTERPRETOR_PARSER_H
