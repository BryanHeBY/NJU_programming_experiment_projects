//
// Created by hby on 2021/3/26.
//
#include <iostream>
#include <cstring>
#include "db_type.h"
#include "../error_solve/ErrorTB.h"
#include <QString>
#include <QRegularExpression>


db_type::db_type(int type_id, int size) {
    _type_id=type_id;
    _size=size;
    _p=new char[size];
}

db_type::db_type(const db_type &other) {
    _type_id=other._type_id;
    _size=other._size;
    _p=new char[_size];
    memcpy(_p,other._p,_size);
}

db_type::~db_type() {
    delete []_p;
}

int db_type::get_type_id() const{return _type_id;}
int db_type::get_size() const{return _size;}

void db_type::load_int(int value) {
    *(int *)_p=value;
}

void db_type::load_string(string &value) {
    if(value.length()+1>_size){
        throw(ErrorTB("String is out of range!","001","你的输入超过长度限制!\n"));}
    strcpy(_p,value.c_str());
}

void db_type::load_float(float value) {
    *(float *)_p=value;
}

int db_type::get_int()const{return *(int *)_p;}
const string db_type::get_string()const{return string(_p);}
float db_type::get_float()const{return *(float *)_p;}

db_type::db_type(int type_id, int size, int value) {
    _type_id=type_id;
    _size=size;
    _p=new char[size];
    load_int(value);
}

db_type::db_type(int type_id, int size, string value) {
    _type_id=type_id;
    _size=size;
    _p=new char[size];
    load_string(value);
}

db_type::db_type(int type_id, int size, float value) {
    _type_id=type_id;
    _size=size;
    _p=new char[size];
    load_float(value);
}

void db_type::show() const{
    if(_type_id==0)printf("%16d",*(int *)_p);
    else if(_type_id==1)printf("%16s",_p);
    else if(_type_id==2)printf("%16.1f",*(float *)_p);
}

bool db_type::same_type(const db_type &other) const {
    return _type_id==other._type_id&&_size==other._size;
}

db_type &db_type::operator =(const db_type &other){
    if(!same_type(other)){
        throw(ErrorTB("Types doesn't match.","009"));}
    memcpy(_p,other._p,_size);
    return *this;
}

db_type &db_type::operator +=(const db_type &other) {
    if(_type_id!=other.get_type_id()-5||_size!=other.get_size()){
        throw(ErrorTB("Types doesn't match.","010"));}
    if(_type_id==1){throw(ErrorTB("String can't add.","011"));}
    if(_type_id==0){*(int *)_p+=*(int *)other._p;return *this;}
    if(_type_id==2){*(float *)_p+=*(float *)other._p;return *this;}
    throw(ErrorTB("Types doesn't match.","012"));
}

bool db_type::operator==(const db_type &other) const {
    if(!same_type(other)){
        throw(ErrorTB("Types doesn't match.","002"));}
    if(_type_id==0)return *(int *)_p==*(int *)other._p;
    if(_type_id==1)return strcmp(_p,other._p)==0;
    if(_type_id==2)return *(float *)_p==*(float *)other._p;
    throw(ErrorTB("Types doesn't match.","003"));
}

bool db_type::operator<(const db_type &other) const {
    if(!same_type(other)){throw(ErrorTB("Types doesn't match.","004"));}
    if(_type_id==0)return *(int *)_p<*(int *)other._p;
    if(_type_id==1)return strcmp(_p,other._p)<0;
    if(_type_id==2)return *(float *)_p<*(float *)other._p;
    throw(ErrorTB("Types doesn't match.","005"));
}

bool db_type::operator>(const db_type &other) const {
    if(!same_type(other)){throw(ErrorTB("Types doesn't match.","006"));}
    if(_type_id==0)return *(int *)_p>*(int *)other._p;
    if(_type_id==1)return strcmp(_p,other._p)>0;
    if(_type_id==2)return *(float *)_p>*(float *)other._p;
    throw(ErrorTB("Types doesn't match.","007"));
}

string db_type::show_str() const{
    char buffer[100];
    if(_type_id==0)snprintf(buffer,100,"%d",*(int *)_p);
    if(_type_id==1)snprintf(buffer,100,"%s",_p);
    if(_type_id==2)snprintf(buffer,100,"%.1f",*(float *)_p);
    return string(buffer);
}

bool db_type_equal(const db_type &a,const db_type &b) {return a==b;}

bool db_type_str_include(const db_type &td,const db_type &value){
    if(td.get_type_id()!=1&&td.get_type_id()!=1){
        throw(ErrorTB("Types doesn't match with str.","008"));
    }
    int l_td=strlen(td._p),l_value=strlen(value._p);
    for(int i=0;i<l_td-l_value+1;i++)
    {
        bool equal=1;
        for(int j=0;j<l_value;j++)
            if(td._p[i+j]!=value._p[j]){equal=0;break;}
        if(equal)return 1;
    }
    return 0;
}

bool db_type_not_equal(const db_type &a, const db_type &b) {return !(a==b);}

char *db_type::_protected_get_p() {
    return _p;
}

bool db_type_type_set_include(const db_type &td, const db_type &value)
{
    QString qtd(td._p),qvalue(value._p);
    for(QString type:qvalue.split(";")){
        QRegularExpression rtype("(^|;)"+type+"($|;)");
        if(!rtype.match(qtd).hasMatch())return 0;
    }
    return 1;
}
