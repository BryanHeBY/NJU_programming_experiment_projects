//
// Created by hby on 2021/5/31.
//

#ifndef EVALUATER_EFUNC_H
#define EVALUATER_EFUNC_H
#include "EObject.h"
#include <functional>
#include <vector>
#define ECALL 15
#define EFUNC 16
#define EVAR 17

using namespace std;

class EFunc;

class EVar: public EObject{
    string _name;
public:
    EVar(const string &name);
    EVar(const char *name);
    EData eval(const EEnv &env)const;
    EFunc *func(const EEnv &env)const;
    const string &name()const;
};

class ECall: public EObject{
private:
    EVar *_func;
    vector<EObject*> _args;
public:
    ECall(EVar *func,const vector<EObject*>& args);
    ~ECall();
    EData eval(const EEnv &env)const;
    const vector<EObject*> &get_args();
    friend ostream &operator<<(ostream &os,const ECall &a);
};

extern EError apply_error;

class EFunc: public EObject{
protected:
    int arg_num;
    bool _lazy;
public:
    EFunc(int arg_num,bool lazy=false);
    EData eval(const EEnv &env)const;
    bool lazy()const;
    virtual EData apply(const vector<EData>& args,const EEnv &env)=0;
};

class ECFunc: public EFunc{
    EData _c;
public:
    ECFunc(const EData &c);
    EData apply(const vector<EData>& args,const EEnv &env);
};

class EBTFunc: public EFunc{
    function<EData(const vector<EData>& args)> _func;
public:
    EBTFunc(int arg_num,const function<EData(const vector<EData>& args)>& func);
    EData apply(const vector<EData>& args,const EEnv &env);
};

class EPairFunc: public EFunc{
public:
    EPairFunc();
    EData apply(const vector<EData>& args,const EEnv &env);
};

class ETernaryFunc: public EFunc{
public:
    ETernaryFunc();
    EData apply(const vector<EData>& args,const EEnv &env);
};

void init_global(EEnv &env);

class EUDFunc: public EFunc{
private:
    EEnv *_penv;
    vector<EVar> _para;
    EObject *_expr;
public:
    EUDFunc(EEnv *penv,const vector<EVar> &para,EObject *expr);
    ~EUDFunc();
    EData apply(const vector<EData>& args,const EEnv &env);
};
#endif //EVALUATER_EFUNC_H
