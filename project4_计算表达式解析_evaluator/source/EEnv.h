//
// Created by hby on 2021/5/31.
//

#ifndef EVALUATER_EENV_H
#define EVALUATER_EENV_H
#include "EObject.h"
#include "EFunc.h"
#include <map>
using namespace std;

class EEnv {
    EEnv *_parent;
    map<string,EFunc*> _env;
public:
    EEnv(EEnv *parent);
    ~EEnv();
    void insert(const EVar &var, EFunc *value);
    EFunc *find(const EVar &var)const;
    bool existed(const EVar &var)const;
    map<string,string> declare_var,declare_func;
    void show_vars();
    void show_funcs();
};


#endif //EVALUATER_EENV_H
