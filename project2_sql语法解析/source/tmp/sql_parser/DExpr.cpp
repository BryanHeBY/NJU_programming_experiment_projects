//
// Created by hby on 2021/4/29.
//

#include "DExpr.h"
#include "DFunc.h"
#include "SQLError.h"
#include "DCol.h"
#include <iostream>

DExpr::DExpr():DObject(50){}
DExpr::~DExpr() {
    for(const auto &i:_expr)delete i;
    while(!_func.empty()){delete _func.top();_func.pop();}
}

void DExpr::push(DObject *dObject) {
    if(dObject->get_type_id()==40){
        if(((DFunc *)dObject)->in_func()) {
            clear_func(((DFunc *)dObject)->func_rank());
            _func.push(dObject);
        }else{

        }
    }else if(dObject->get_type_id()==52){
        clear_func(1);

    }else{
        _expr.emplace_back(dObject);

    }
}

void DExpr::clear_func(int low_func) {
    while(!_func.empty()&&low_func<=((DFunc *)_func.top())->func_rank()){
        _expr.emplace_back(_func.top()),_func.pop();
    }
}


void DExpr::end_expr() {
    clear_func(-1);
    if(!_func.empty())throw SQLError("702","Expression error");
}

DData DExpr::getValue(DColInter &colIter)const{
    stack<DData> res;
    for(const auto &i:_expr){
        if(i->get_type_id()==40){
            vector<DData> tmp;
            for(int j=0;j<(((DFunc *)i)->arg_num());j++){
                if(res.empty())throw SQLError("703","Expression eval error");
                tmp.emplace_back(res.top()),res.pop();
            }
            if(((DFunc *)i)->in_func())res.push((*((InFunc*)i))(tmp[1],tmp[0]));
        }else if(i->get_type_id()==23){
            res.push(colIter.get(*(DColIndex *)i));
        }else if((i->get_type_id())<=7){
            res.push(*(DData*)i);
        }
    }
    if(res.size()!=1)throw SQLError("704","Expression eval error");
    return res.top();
}

int DExpr::expr_size() {return _expr.size();}

DExpr::DExpr(const DExpr &other):DObject(50){

}

DData DExpr::getValue(const DTRow &row) const {
    stack<DData> res;
    for(const auto &i:_expr){
        if(i->get_type_id()==40){
            vector<DData> tmp;
            for(int j=0;j<(((DFunc *)i)->arg_num());j++){
                if(res.empty())throw SQLError("703","Expression eval error");
                tmp.emplace_back(res.top()),res.pop();
            }
            if(((DFunc *)i)->in_func())res.push((*((InFunc*)i))(tmp[1],tmp[0]));
        }else if(i->get_type_id()==23){
            res.push(row[(*(DColIndex*)i)._CIndex]);
        }else if((i->get_type_id())<=7){
            res.push(*(DData*)i);
        }
    }
    if(res.size()!=1)throw SQLError("704","Expression eval error");
    return res.top();
}

DLPToken::DLPToken():DFunc(0,1,1,0) {}

DRPToken::DRPToken():DObject(52) {}

void getTrueExpr(DExpr &expr) {
    expr.push(new DBoolean(-1));
    expr.end_expr();
}

