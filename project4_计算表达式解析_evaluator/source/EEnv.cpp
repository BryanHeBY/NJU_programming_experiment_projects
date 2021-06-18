//
// Created by hby on 2021/5/31.
//

#include <iostream>
#include "EEnv.h"

EEnv::EEnv(EEnv *parent):_parent(parent){}

EEnv::~EEnv() {
    for(const auto &i:_env)delete i.second;
}

void EEnv::insert(const EVar &var, EFunc *value) {
    auto i=_env.find(var.name());
    if(i!=_env.end()){
        delete i->second;
        _env.erase(i);
    }
    _env.insert(pair<string,EFunc*>{var.name(),value});
}

EFunc *EEnv::find(const EVar &var) const {
    auto i=_env.find(var.name());
    if(i==_env.end()){
        if(_parent==NULL)return nullptr;
        else return _parent->find(var);
    }
    return i->second;
}

void EEnv::show_vars() {
    for(auto &i:declare_var)cout<<i.second<<endl;
}

void EEnv::show_funcs() {
    for(auto &i:declare_func)cout<<i.second<<endl;
}

bool EEnv::existed(const EVar &var) const {
    auto i=_env.find(var.name());
    return i!=_env.end();
}
