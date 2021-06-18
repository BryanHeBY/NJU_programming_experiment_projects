//
// Created by hby on 2021/5/31.
//

#include <iostream>
#include "EFunc.h"
#include "EEnv.h"
#include <cmath>

ECall::ECall(EVar *func, const vector<EObject*> &args):EObject(ECALL),_func(func),_args(args){}

EData ECall::eval(const EEnv &env) const {
    vector<EData> cal_args;
    EFunc *func=_func->func(env);//寻找函数
    if(func==NULL)throw EError("201","Function NOT FOUND: "+_func->name()+".");
    if(!func->lazy()){
        cal_args.reserve(_args.size());
        for(const auto &i:_args)cal_args.push_back(i->eval(env));//执行参数的eval(env)
        return func->apply(cal_args,env);//apply(所得参数,env)
    }else return EData((EObject*)this);
}

ECall::~ECall() {
    delete _func;
    for(const auto &i:_args)delete i;
}

const vector<EObject *> &ECall::get_args() {
    return _args;
}

ostream &operator<<(ostream &os, const ECall &a) {
    os<<"(";
    os<<a._func->name();
    for(const auto &i:a._args)cout<<" "<<*i;
    os<<")";
    return os;
}

EError apply_error("202","Function args apply error.");

EFunc::EFunc(int num,bool lazy):EObject(EFUNC),arg_num(num),_lazy(lazy){}

EData EFunc::eval(const EEnv &env) const {
    return EData();
}

bool EFunc::lazy() const {
    return _lazy;
}

ECFunc::ECFunc(const EData &c):EFunc(0),_c(c){}

EData ECFunc::apply(const vector<EData> &args, const EEnv &env) {
    if(args.size()!=0)throw apply_error;
    return _c;
}

EBTFunc::EBTFunc(int arg_num,const function<EData(const vector<EData>& args)>& func): EFunc(arg_num),_func(func) {}

EData EBTFunc::apply(const vector<EData> &args, const EEnv &env) {
    if(args.size()!=arg_num)throw apply_error;
    return _func(args);
}


void init_global(EEnv &env){
    env.insert("+",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]+args[1];
    }));
    env.insert("-",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]-args[1];
    }));
    env.insert("m-",new EBTFunc(1,[](const vector<EData>& args){
        return -args[0];
    }));
    env.insert("*",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]*args[1];
    }));
    env.insert("/",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]/args[1];
    }));
    env.insert("%",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]%args[1];
    }));
    env.insert("==",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]==args[1];
    }));
    env.insert("!=",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]!=args[1];
    }));
    env.insert("<",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]<args[1];
    }));
    env.insert("<=",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]<=args[1];
    }));
    env.insert(">",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]<args[1];
    }));
    env.insert(">=",new EBTFunc(2,[](const vector<EData>& args){
        if(args.size()!=2)throw apply_error;
        return args[0]<=args[1];
    }));
    env.insert("**",new EBTFunc(2,[](const vector<EData>& args){
        return args[0].epow(args[1]);
    }));
    env.insert("&&",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]&&args[1];
    }));
    env.insert("||",new EBTFunc(2,[](const vector<EData>& args){
        return args[0]||args[1];
    }));
    env.insert("sin",new EBTFunc(1,[](const vector<EData>& args){
        return EData(sin(args[0].float_value()));
    }));
    env.insert("cos",new EBTFunc(1,[](const vector<EData>& args){
        return EData(cos(args[0].float_value()));
    }));
    env.insert("tan",new EBTFunc(1,[](const vector<EData>& args){
        return EData(tan(args[0].float_value()));
    }));
    env.insert("cot",new EBTFunc(1,[](const vector<EData>& args){
        return EData((float)1.0/tan(args[0].float_value()));
    }));
    env.insert("arcsin",new EBTFunc(1,[](const vector<EData>& args){
        return EData(asin(args[0].float_value()));
    }));
    env.insert("arccos",new EBTFunc(1,[](const vector<EData>& args){
        return EData(acos(args[0].float_value()));
    }));
    env.insert("arctan",new EBTFunc(1,[](const vector<EData>& args){
        return EData(atan(args[0].float_value()));
    }));
    env.insert("ln",new EBTFunc(1,[](const vector<EData>& args){
        return EData(log(args[0].float_value()));
    }));
    env.insert("log",new EBTFunc(2,[](const vector<EData>& args){
        return EData(log(args[1].float_value())/log(args[0].float_value()));
    }));
    env.insert("exp",new EBTFunc(1,[](const vector<EData>& args){
        return EData(exp(args[0].float_value()));
    }));
    env.insert("sqrt",new EBTFunc(1,[](const vector<EData>& args){
        return EData(sqrt(args[0].float_value()));
    }));
    env.insert("abs",new EBTFunc(1,[](const vector<EData>& args){
        return args[0].abs();
    }));
    env.insert(":",new EPairFunc());
    env.insert("?",new ETernaryFunc());
    env.insert("PI",new ECFunc((float)3.1415926));
    env.insert("|",new EBTFunc(2,[](const vector<EData>& args){
        return EData(args[0].int_value()|args[1].int_value());
    }));
    env.insert("&",new EBTFunc(2,[](const vector<EData>& args){
        return EData(args[0].int_value()&args[1].int_value());
    }));
    env.insert("^",new EBTFunc(2,[](const vector<EData>& args){
        return EData(args[0].int_value()^args[1].int_value());
    }));
    env.insert("<<",new EBTFunc(2,[](const vector<EData>& args){
        return EData(args[0].int_value()<<args[1].int_value());
    }));
    env.insert(">>",new EBTFunc(2,[](const vector<EData>& args){
        return EData(args[0].int_value()>>args[1].int_value());
    }));
    env.insert("~",new EBTFunc(1,[](const vector<EData>& args){
        return EData(~args[0].int_value());
    }));
    env.insert("!",new EBTFunc(1,[](const vector<EData>& args){
        return EData(args[0].is_zero());
    }));
}



EUDFunc::EUDFunc(EEnv *penv, const vector<EVar> &para, EObject *expr):EFunc(para.size()),_penv(penv),_para(para),_expr(expr) {}

EData EUDFunc::apply(const vector<EData> &args, const EEnv &env) {
    EEnv new_env(_penv);
    int len=_para.size();
    if(len!=args.size())throw apply_error;
    for(int i=0;i<len;i++){
        if(new_env.existed(_para[i]))throw apply_error;//变量名互斥检测
        new_env.insert(_para[i],new ECFunc(args[i]));//常值函数 x=1 => x()=1
    }
    return _expr->eval(new_env);
}

EUDFunc::~EUDFunc() {
    delete _expr;
}

EVar::EVar(const string &name):EObject(EVAR),_name(name){}
EVar::EVar(const char *name):EObject(EVAR),_name(name){}

EData EVar::eval(const EEnv &env) const {
    return EData();
}

EFunc *EVar::func(const EEnv &env)const {
    return env.find(*this);
}

const string &EVar::name()const{
    return _name;
}

EPairFunc::EPairFunc():EFunc(2, true){}

EData EPairFunc::apply(const vector<EData> &args, const EEnv &env) {
    return EData();
}

ETernaryFunc::ETernaryFunc():EFunc(2){}

EData ETernaryFunc::apply(const vector<EData> &args, const EEnv &env) {
    if(args.size()!=2)throw apply_error;
    if(!args[1].is_instance(EREF))throw EError("203","Not a ternary expr.");
    if(args[0].is_zero())return ((ECall*)(args[1].ref()))->get_args()[1]->eval(env);
    else return ((ECall*)(args[1].ref()))->get_args()[0]->eval(env);
}
