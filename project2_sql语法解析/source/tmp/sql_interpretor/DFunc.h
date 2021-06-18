//
// Created by hby on 2021/4/29.
//

#ifndef SQL_INTERPRETOR_DFUNC_H
#define SQL_INTERPRETOR_DFUNC_H

#include "DObject.h"

class DFunc: public DObject{
protected:
    bool _in_func;
    int _func_id;
    int _func_rank;
    int _arg_num;
public:
    DFunc(bool in_func,int func_id,int func_rank,int arg_num);
    bool in_func();
    int func_rank();
    int func_id();
    int arg_num();
};

class InFunc: public DFunc{
public:
    InFunc(int func_id,int func_rank);
    virtual ~InFunc()=default;
    virtual DData operator() (const DData &a,const DData &b)=0;
};

class addFunc: public InFunc{
public:
    addFunc();
    DData operator() (const DData &a,const DData &b);
};

class subFunc: public InFunc{
public:
    subFunc();
    DData operator() (const DData &a,const DData &b);
};

class mulFunc: public InFunc{
public:
    mulFunc();
    DData operator() (const DData &a,const DData &b);
};

class divFunc: public InFunc{
public:
    divFunc();
    DData operator() (const DData &a,const DData &b);
};

class lessFunc: public InFunc{
public:
    lessFunc();
    DData operator() (const DData &a,const DData &b);
};

class greaterFunc: public InFunc{
public:
    greaterFunc();
    DData operator() (const DData &a,const DData &b);
};

class eqFunc: public InFunc{
public:
    eqFunc();
    DData operator() (const DData &a,const DData &b);
};

class leFunc: public InFunc{
public:
    leFunc();
    DData operator() (const DData &a,const DData &b);
};

class geFunc: public InFunc{
public:
    geFunc();
    DData operator() (const DData &a,const DData &b);
};

class neqFunc: public InFunc{
public:
    neqFunc();
    DData operator() (const DData &a,const DData &b);
};

class andFunc: public InFunc{
public:
    andFunc();
    DData operator() (const DData &a,const DData &b);
};

class orFunc: public InFunc{
public:
    orFunc();
    DData operator() (const DData &a,const DData &b);
};

class likeFunc: public InFunc{
public:
    likeFunc();
    DData operator() (const DData &a,const DData &b);
};

#endif //SQL_INTERPRETOR_DFUNC_H
