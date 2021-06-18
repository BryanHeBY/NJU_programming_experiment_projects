//
// Created by hby on 2021/5/30.
//

#include <iostream>
#include "parser.h"
#include "EEnv.h"

vector<pair<regex,string>> replace_list{
        make_pair(regex("\\(")," ( "),
        make_pair(regex("\\)")," ) "),
        make_pair(regex("\\,")," , "),
        make_pair(regex("\\+")," + "),
        make_pair(regex("&")," & "),
        make_pair(regex("\\|")," | "),
        make_pair(regex("\\^")," ^ "),
        make_pair(regex("~")," ~ "),
        make_pair(regex("!")," ! "),
        make_pair(regex("-")," - "),
        make_pair(regex("\\*")," * "),
        make_pair(regex("%")," % "),
        make_pair(regex("/")," / "),
        make_pair(regex("=")," = "),
        make_pair(regex("<")," < "),
        make_pair(regex(">")," > "),
        make_pair(regex(":")," : "),
        make_pair(regex("\\?")," ? "),
        make_pair(regex("=  =")," == "),
        make_pair(regex("<  =")," <= "),
        make_pair(regex(">  =")," >= "),
        make_pair(regex("!  =")," != "),
        make_pair(regex("\\*  \\*")," ** "),
        make_pair(regex("&  &")," && "),
        make_pair(regex("\\|  \\|")," || "),
        make_pair(regex("<  <")," << "),
        make_pair(regex(">  >")," >> "),
};
regex tint("^\\d+$"),tfloat("^\\d+\\.\\d+$"), var("^[a-zA-Z]+$");
regex var_sentence("^Var\\s+(.*?)\\s*=\\s*(.*?)$",wregex::icase);
regex var_value_sentence("^([a-zA-Z]+)\\s*=\\s*([^=].*?)$",wregex::icase);
regex assign_sentence("^([a-zA-Z]+)\\s*:=\\s*([^=].*?)$",wregex::icase);
regex func_sentence("^Func\\s+(.*?)\\((.*?)\\)\\s*=\\s*(.*?)$",wregex::icase);
regex exit_sentence("^exit$",wregex::icase);
regex show_vars_sentence("^SHOW VARS$",wregex::icase);
regex show_funcs_sentence("^SHOW FUNCS$",wregex::icase);
regex print_sentence("^print\\((.+?)\\)$",wregex::icase);


map<string,int> func_rank;
EError unknown_token("301","Unknown token.");
EError unexpected_token("302","Unexpected token.");
EError existed_var("303","Function has existed.");
EError not_existed_var("303","Function doesn't exist.");

void split_without_none(const string& s,queue<string>& sv,const char flag) {
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        if(!temp.empty())sv.push(temp);
    }
}

void split_without_none_vector(const string& s,vector<string>& sv,const char flag) {
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        if(!temp.empty())sv.push_back(temp);
    }
}

EObject *get_atom(queue<string> &tokens,bool begin);
EObject *expr_with_end(queue<string> &tokens,string &end,int rank=0);


void init_parser(){
    func_rank.insert(make_pair("?",1));
    func_rank.insert(make_pair(":",2));
    func_rank.insert(make_pair("||",3));
    func_rank.insert(make_pair("&&",4));
    func_rank.insert(make_pair("|",5));
    func_rank.insert(make_pair("^",6));
    func_rank.insert(make_pair("&",7));
    func_rank.insert(make_pair("==",8));
    func_rank.insert(make_pair("!=",8));
    func_rank.insert(make_pair("<",9));
    func_rank.insert(make_pair("<=",9));
    func_rank.insert(make_pair(">",9));
    func_rank.insert(make_pair(">=",9));
    func_rank.insert(make_pair("<<",10));
    func_rank.insert(make_pair(">>",10));
    func_rank.insert(make_pair("+",11));
    func_rank.insert(make_pair("-",11));
    func_rank.insert(make_pair("*",12));
    func_rank.insert(make_pair("/",12));
    func_rank.insert(make_pair("%",12));
    func_rank.insert(make_pair("**",13));
    func_rank.insert(make_pair("!",14));
    func_rank.insert(make_pair("~",14));

}

EObject *get_expr(string str) {
    queue<string> tokens;
    for(auto &i:replace_list)str=regex_replace(str,i.first,i.second);
    split_without_none(str,tokens,' ');
    tokens.push("");
    //while(!tokens.empty())(cout<<tokens.front()<<" "),tokens.pop();
    string end;
    EObject *res=expr_with_end(tokens,end);
    if(end!="")throw unexpected_token;
    return res;
    //return new EData();
}

void check_var(const string &str){
    if(!regex_match(str,var))throw EError("501","Var name error.");
}

bool senctence_with_end(const string &sentence,EEnv &env, bool interpreter_mode) {
    smatch match;
    if(regex_match(sentence,match,var_sentence)){
        check_var(match[1]);
        if(!interpreter_mode&&env.existed(EVar(match[1])))throw existed_var;
        env.insert(EVar(match[1]),new EUDFunc(&env,{},get_expr(match[2])));
        env.declare_var[match[1]]=sentence;
        cout<<match[1];
    }else if(regex_match(sentence,match,func_sentence)){
        check_var(match[1]);
        if(!interpreter_mode&&env.existed(EVar(match[1])))throw existed_var;
        vector<string> vars;
        split_without_none_vector(match[2],vars,',');
        vector<EVar> args;
        for(const auto &i:vars){
            check_var(i);
            args.push_back(EVar(i));
        }
        env.insert(EVar(match[1]),new EUDFunc(&env,args,get_expr(match[3])));
        env.declare_func[match[1]]=sentence;
        cout<<match[1]<<"("<<match[2]<<")";
    }else if(regex_match(sentence,match,var_value_sentence)) {
        check_var(match[1]);
        if(!interpreter_mode&&!env.existed(EVar(match[1])))throw not_existed_var;
        env.insert(EVar(match[1]),new EUDFunc(&env,{},get_expr(match[2])));
        env.declare_var[match[1]]=sentence;
        cout<<match[1];
    }else if(regex_match(sentence,match,assign_sentence)) {
        check_var(match[1]);
        if(!interpreter_mode&&!env.existed(EVar(match[1])))throw not_existed_var;
        EObject *expr=get_expr(match[2]);
        env.insert(EVar(match[1]),new ECFunc(expr->eval(env)));
        delete expr;
        env.declare_var[match[1]]=sentence;
        cout<<match[1];
    }else if(regex_match(sentence,match,exit_sentence)){
        return true;
    }else if(regex_match(sentence,match,show_vars_sentence)){
        env.show_vars();
    }else if(regex_match(sentence,match,show_funcs_sentence)){
        env.show_funcs();
    }else if(regex_match(sentence,match,print_sentence)){
        EObject *res=get_expr(match[1]);
        cout<<*res;
        delete res;
    }else {
        EObject *expr=get_expr(sentence);
        cout<<expr->eval(env);
        delete expr;
    }
    return false;
}


EObject *expr_with_end(queue<string> &tokens,string &end,int rank){
    EObject *now=get_atom(tokens,rank==0);
    while(1){
        string str=tokens.front();
        if(str==","||str==")"||str==""){
            end=str;
            break;
        }
        else if(func_rank.find(str)!=func_rank.end()){
            int new_rank=func_rank.find(str)->second;
            if(new_rank<=rank)break;
            tokens.pop();
            now=new ECall(new EVar(str),{now,expr_with_end(tokens,end,new_rank)});
        }else throw unknown_token;
    }
    return now;
}

EObject *get_atom(queue<string> &tokens,bool begin) {
    string now=tokens.front();
    tokens.pop();
    if(regex_match(now,tint))return new EData(stoi(now));
    else if(regex_match(now,tfloat))return new EData(stof(now));
    else if(regex_match(now,var)){
        EVar *func=new EVar(now);
        vector<EObject*> args;
        string nexts=tokens.front();
        if(nexts=="("){
            tokens.pop();
            string end;
            while(1){
                args.push_back(expr_with_end(tokens,end,0));
                tokens.pop();
                if(end==",")continue;
                else if(end==")")break;
                else if(end=="")throw unexpected_token;
            }
        }
        return new ECall(func,args);
    }else if(now=="("){
        string end;
        EObject *res=expr_with_end(tokens,end,0);
        tokens.pop();
        if(end==")")return res;
        else throw unexpected_token;
    }else if(begin&&now=="+"){
        return get_atom(tokens, false);
    }else if(begin&&now=="-"){
        EObject *res=get_atom(tokens, false);
        return new ECall(new EVar("m-"),{res});
    }else if(now=="!"||now=="~"){
        EObject *res=get_atom(tokens, false);
        return new ECall(new EVar(now),{res});
    }else throw unexpected_token;
}