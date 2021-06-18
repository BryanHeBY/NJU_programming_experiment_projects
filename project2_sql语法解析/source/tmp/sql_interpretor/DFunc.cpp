//
// Created by hby on 2021/4/29.
//

#include "DFunc.h"
#include <regex>

using namespace std;

DFunc::DFunc(bool in_func,int func_id,int func_rank,int arg_num)
    :DObject(40),_in_func(in_func),_func_id(func_id),_func_rank(func_rank),_arg_num(arg_num){}

bool DFunc::in_func() {return _in_func;}
int DFunc::func_rank() {return _func_rank;}
int DFunc::func_id() {return _func_id;}
int DFunc::arg_num() {return _arg_num;}

InFunc::InFunc(int func_id,int func_rank):DFunc(1,func_id,func_rank,2){}

addFunc::addFunc():InFunc(11,5){}
DData addFunc::operator()(const DData &a, const DData &b) {return a+b;}

subFunc::subFunc():InFunc(12,5){}
DData subFunc::operator()(const DData &a, const DData &b) {return a-b;}

mulFunc::mulFunc():InFunc(13,6){}
DData mulFunc::operator()(const DData &a, const DData &b) {return a*b;}

divFunc::divFunc():InFunc(14,6){}
DData divFunc::operator()(const DData &a, const DData &b) {return a/b;}

lessFunc::lessFunc():InFunc(15,4){}
DData lessFunc::operator()(const DData &a, const DData &b) {return a<b;}

greaterFunc::greaterFunc():InFunc(16,4){}
DData greaterFunc::operator()(const DData &a, const DData &b) {return a>b;}

eqFunc::eqFunc():InFunc(17,4){}
DData eqFunc::operator()(const DData &a, const DData &b) {return a==b;}

leFunc::leFunc():InFunc(18,4){}
DData leFunc::operator()(const DData &a, const DData &b) {return a<=b;}

geFunc::geFunc():InFunc(19,4){}
DData geFunc::operator()(const DData &a, const DData &b) {return a>=b;}

neqFunc::neqFunc():InFunc(20,4){}
DData neqFunc::operator()(const DData &a, const DData &b) {return DBoolean(!((a==b).isTrue()));}

andFunc::andFunc():InFunc(21,3){}
DData andFunc::operator()(const DData &a, const DData &b) {return a&&b;}

orFunc::orFunc():InFunc(22,2){}
DData orFunc::operator()(const DData &a, const DData &b) {return a||b;}

likeFunc::likeFunc():InFunc(23,5){}
DData likeFunc::operator()(const DData &a, const DData &b) {
    string pattern(b.shift_type(7).ptr()),str(a.shift_type(7).ptr());
    pattern=regex_replace(pattern,regex("%"),".*");
    pattern=regex_replace(pattern,regex("_"),".");
    return DBoolean(regex_match(str,regex("^"+pattern+"$")));
}