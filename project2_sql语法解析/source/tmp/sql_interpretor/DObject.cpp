//
// Created by hby on 2021/4/21.
//

#include <cstring>
#include <sstream>
#include <iostream>
#include "DObject.h"
#include "SQLError.h"

DObject::DObject(short _type_id) :_type_id(_type_id){}
int DObject::get_type_id() const{
    return _type_id;
}


DData::DData(short type_id, short size, const char *p) :DObject(type_id),_size(size){
    if(type_id<=0||type_id>=8)throw SQLError("001","Var type error.");
    _p=new char[_size];
    memcpy(_p,p,_size);
}

DData::DData(short type_id,short size,ifstream &ifs):DObject(type_id),_size(size){
    _p=new char[_size];
    ifs.read(_p,_size);
    if(ifs.eof())throw SQLError("101","FILE_EOF");
}

DData::~DData() {
    if(_p!= nullptr)delete []_p;
}

DData::DData(short type_id, short size):DObject(type_id),_size(size),_p(nullptr){}

short int DData::size()const {return _size;}
const char *DData::ptr() const{return _p;}

DData &DData::operator=(const DData &other) {
    _type_id=other._type_id,_size=other._size;
    delete []_p;
    _p=new char[_size];
    memcpy(_p,other._p,_size);
    return *this;
}

DData DData::shift_type(short to_type,int to_size)const{
    if(ptr()== nullptr)throw SQLError("008","Col is None");
    if(to_type==7) {
        if(_type_id==7){
            if(to_size==-1)return DVarchar(_p);
            else return DVarchar(to_size,_p);
        }
        string res;
        stringstream ss;
        ss<<*this;
        ss>>res;
        return DVarchar(res.c_str());
    }
    if(to_type==_type_id)return *this;
    if(_type_id==1){
        bool pre=*(bool *)_p;
        if(to_type==1)return DBoolean(pre);
        else if(to_type==2)return DSmallInt(pre);
        else if(to_type==3)return DInteger(pre);
        else if(to_type==4)return DBigInt(pre);
        else if(to_type==5)return DFloat(pre);
        else if(to_type==6)return DDouble(pre);
    }else if(_type_id==2) {
        short pre=*(short *)_p;
        if(to_type==1)return DBoolean(pre);
        else if(to_type==2)return DSmallInt(pre);
        else if(to_type==3)return DInteger(pre);
        else if(to_type==4)return DBigInt(pre);
        else if(to_type==5)return DFloat(pre);
        else if(to_type==6)return DDouble(pre);
    }else if(_type_id==3) {
        int pre=*(int *)_p;
        if(to_type==1)return DBoolean(pre);
        else if(to_type==2)return DSmallInt(pre);
        else if(to_type==3)return DInteger(pre);
        else if(to_type==4)return DBigInt(pre);
        else if(to_type==5)return DFloat(pre);
        else if(to_type==6)return DDouble(pre);
    }else if(_type_id==4) {
        long long pre=*(long long *)_p;
        if(to_type==1)return DBoolean(pre);
        else if(to_type==2)return DSmallInt(pre);
        else if(to_type==3)return DInteger(pre);
        else if(to_type==4)return DBigInt(pre);
        else if(to_type==5)return DFloat(pre);
        else if(to_type==6)return DDouble(pre);
    }else if(_type_id==5) {
        float pre=*(float *)_p;
        if(to_type==1)return DBoolean(pre);
        else if(to_type==2)return DSmallInt(pre);
        else if(to_type==3)return DInteger(pre);
        else if(to_type==4)return DBigInt(pre);
        else if(to_type==5)return DFloat(pre);
        else if(to_type==6)return DDouble(pre);
    }else if(_type_id==6) {
        double pre=*(double *)_p;
        if(to_type==1)return DBoolean(pre);
        else if(to_type==2)return DSmallInt(pre);
        else if(to_type==3)return DInteger(pre);
        else if(to_type==4)return DBigInt(pre);
        else if(to_type==5)return DFloat(pre);
        else if(to_type==6)return DDouble(pre);
    }
    throw SQLError("002","Shift type error.");
}
DData DData::operator+(const DData &other)const{
    if(_type_id<other._type_id)return other.operator+(*this);
    if(_type_id==7&&other._type_id==7)return DVarchar(string(string(_p)+other._p).c_str());
    if(_type_id<=7){
        if(other._type_id!=_type_id)return this->operator+(other.shift_type(_type_id));
        if(_type_id==1)return DBoolean(*(bool *)_p+*(bool *)other._p);
        else if(_type_id==2)return DSmallInt(*(short *)_p+*(short *)other._p);
        else if(_type_id==3)return DInteger(*(int *)_p+*(int *)other._p);
        else if(_type_id==4)return DBigInt(*(long long *)_p+*(long long *)other._p);
        else if(_type_id==5)return DFloat(*(float *)_p+*(float *)other._p);
        else if(_type_id==6)return DDouble(*(double *)_p+*(double *)other._p);
        throw SQLError("004","Varchar can't add");
    }
}

DData DData::operator-(const DData &other) const {
    DData pre(*this),last(other);
    if(pre._type_id<last._type_id)pre=pre.shift_type(last._type_id);
    if(pre._type_id>last._type_id)last=last.shift_type(pre._type_id);
    if(pre._type_id<=7){
        if(pre._type_id==1)return DBoolean(*(bool *)pre._p-*(bool *)last._p);
        else if(pre._type_id==2)return DSmallInt(*(short *)pre._p-*(short *)last._p);
        else if(pre._type_id==3)return DInteger(*(int *)pre._p-*(int *)last._p);
        else if(pre._type_id==4)return DBigInt(*(long long *)pre._p-*(long long *)last._p);
        else if(pre._type_id==5)return DFloat(*(float *)pre._p-*(float *)last._p);
        else if(pre._type_id==6)return DDouble(*(double *)pre._p-*(double *)last._p);
        throw SQLError("005","Varchar can't minus");
    }
}

DData DData::operator*(const DData &other) const {
    if(_type_id<other._type_id)return other.operator*(*this);
    if(_type_id<=7){
        if(other._type_id!=_type_id)return this->operator*(other.shift_type(_type_id));
        if(_type_id==1)return DBoolean(*(bool *)_p**(bool *)other._p);
        else if(_type_id==2)return DSmallInt(*(short *)_p**(short *)other._p);
        else if(_type_id==3)return DInteger(*(int *)_p**(int *)other._p);
        else if(_type_id==4)return DBigInt(*(long long *)_p**(long long *)other._p);
        else if(_type_id==5)return DFloat(*(float *)_p**(float *)other._p);
        else if(_type_id==6)return DDouble(*(double *)_p**(double *)other._p);
        throw SQLError("006","Varchar can't multiply");
    }
}

DData DData::operator/(const DData &other) const {
    DData pre(*this),last(other);
    if(pre._type_id<last._type_id)pre=pre.shift_type(last._type_id);
    if(pre._type_id>last._type_id)last=last.shift_type(pre._type_id);
    if(pre._type_id<=7){
        if(pre._type_id==1)return DBoolean(*(bool *)pre._p/(*(bool *)last._p));
        else if(pre._type_id==2)return DSmallInt(*(short *)pre._p/(*(short *)last._p));
        else if(pre._type_id==3)return DInteger(*(int *)pre._p/(*(int *)last._p));
        else if(pre._type_id==4)return DBigInt(*(long long *)pre._p/(*(long long *)last._p));
        else if(pre._type_id==5)return DFloat(*(float *)pre._p/(*(float *)last._p));
        else if(pre._type_id==6)return DDouble(*(double *)pre._p/(*(double *)last._p));
        throw SQLError("007","Varchar can't divide");
    }
}

DData::DData(const DData &other):DObject(other._type_id),_size(other._size){
    _p=new char[_size];
    memcpy(_p,other._p,_size);
}

ostream &operator<<(ostream &os, const DData &dDate) {
    if(dDate.ptr()== nullptr)os<<"";
    else if(dDate._type_id==1)os<<*(bool *)dDate._p;
    else if(dDate._type_id==2)os<<*(short *)dDate._p;
    else if(dDate._type_id==3)os<<*(int *)dDate._p;
    else if(dDate._type_id==4)os<<*(long long *)dDate._p;
    else if(dDate._type_id==5)os<<*(float *)dDate._p;
    else if(dDate._type_id==6)os<<*(double *)dDate._p;
    else if(dDate._type_id==7)os<<dDate._p;
}

DData DData::operator==(const DData &other)const{
    if(_type_id<other._type_id)return other.operator==(*this);
    if(_type_id==7&&other._type_id==7)return DBoolean(strcmp(_p,other._p)==0);
    if(_type_id<=7){
        if(other._type_id!=_type_id)return this->operator==(other.shift_type(_type_id));
        if(_type_id==1)return DBoolean(*(bool *)_p==*(bool *)other._p);
        else if(_type_id==2)return DBoolean(*(short *)_p==*(short *)other._p);
        else if(_type_id==3)return DBoolean(*(int *)_p==*(int *)other._p);
        else if(_type_id==4)return DBoolean(*(long long *)_p==*(long long *)other._p);
        else if(_type_id==5)return DBoolean(*(float *)_p==*(float *)other._p);
        else if(_type_id==6)return DBoolean(*(double *)_p==*(double *)other._p);
        throw SQLError("004","Varchar can't compare");
    }
}

DData DData::operator<(const DData &other)const{
    if(_type_id==7&&other._type_id==7)return DBoolean(strcmp(_p,other._p)<0);
    DData pre(*this),last(other);
    if(pre._type_id<last._type_id)pre=pre.shift_type(last._type_id);
    if(pre._type_id>last._type_id)last=last.shift_type(pre._type_id);
    if(pre._type_id<=7){
        if(pre._type_id==1)return DBoolean(*(bool *)pre._p<(*(bool *)last._p));
        else if(pre._type_id==2)return DBoolean(*(short *)pre._p<(*(short *)last._p));
        else if(pre._type_id==3)return DBoolean(*(int *)pre._p<(*(int *)last._p));
        else if(pre._type_id==4)return DBoolean(*(long long *)pre._p<(*(long long *)last._p));
        else if(pre._type_id==5)return DBoolean(*(float *)pre._p<(*(float *)last._p));
        else if(pre._type_id==6)return DBoolean(*(double *)pre._p<(*(double *)last._p));
        throw SQLError("007","Varchar can't compare");
    }
}

DData DData::operator<=(const DData &other)const{
    if(_type_id==7&&other._type_id==7)return DBoolean(strcmp(_p,other._p)<=0);
    DData pre(*this),last(other);
    if(pre._type_id<last._type_id)pre=pre.shift_type(last._type_id);
    if(pre._type_id>last._type_id)last=last.shift_type(pre._type_id);
    if(pre._type_id<=7){
        if(pre._type_id==1)return DBoolean(*(bool *)pre._p<=(*(bool *)last._p));
        else if(pre._type_id==2)return DBoolean(*(short *)pre._p<=(*(short *)last._p));
        else if(pre._type_id==3)return DBoolean(*(int *)pre._p<=(*(int *)last._p));
        else if(pre._type_id==4)return DBoolean(*(long long *)pre._p<=(*(long long *)last._p));
        else if(pre._type_id==5)return DBoolean(*(float *)pre._p<=(*(float *)last._p));
        else if(pre._type_id==6)return DBoolean(*(double *)pre._p<=(*(double *)last._p));
        throw SQLError("007","Varchar can't compare");
    }
}

DData DData::operator>(const DData &other)const{
    if(_type_id==7&&other._type_id==7)return DBoolean(strcmp(_p,other._p)>0);
    DData pre(*this),last(other);
    if(pre._type_id<last._type_id)pre=pre.shift_type(last._type_id);
    if(pre._type_id>last._type_id)last=last.shift_type(pre._type_id);
    if(pre._type_id<=7){
        if(pre._type_id==1)return DBoolean(*(bool *)pre._p>(*(bool *)last._p));
        else if(pre._type_id==2)return DBoolean(*(short *)pre._p>(*(short *)last._p));
        else if(pre._type_id==3)return DBoolean(*(int *)pre._p>(*(int *)last._p));
        else if(pre._type_id==4)return DBoolean(*(long long *)pre._p>(*(long long *)last._p));
        else if(pre._type_id==5)return DBoolean(*(float *)pre._p>(*(float *)last._p));
        else if(pre._type_id==6)return DBoolean(*(double *)pre._p>(*(double *)last._p));
        throw SQLError("007","Varchar can't compare");
    }
}

DData DData::operator>=(const DData &other)const{
    if(_type_id==7&&other._type_id==7)return DBoolean(strcmp(_p,other._p)>=0);
    DData pre(*this),last(other);
    if(pre._type_id<last._type_id)pre=pre.shift_type(last._type_id);
    if(pre._type_id>last._type_id)last=last.shift_type(pre._type_id);
    if(pre._type_id<=7){
        if(pre._type_id==1)return DBoolean(*(bool *)pre._p>=(*(bool *)last._p));
        else if(pre._type_id==2)return DBoolean(*(short *)pre._p>=(*(short *)last._p));
        else if(pre._type_id==3)return DBoolean(*(int *)pre._p>=(*(int *)last._p));
        else if(pre._type_id==4)return DBoolean(*(long long *)pre._p>=(*(long long *)last._p));
        else if(pre._type_id==5)return DBoolean(*(float *)pre._p>=(*(float *)last._p));
        else if(pre._type_id==6)return DBoolean(*(double *)pre._p>=(*(double *)last._p));
        throw SQLError("007","Varchar can't compare");
    }
}

DData DData::operator!()const{
    return DBoolean(this->isTrue());
}

DData DData::operator&&(const DData &other)const{
    return DBoolean(this->isTrue()&&other.isTrue());
}

DData DData::operator||(const DData &other)const{
    return DBoolean(this->isTrue()||other.isTrue());
}

void DData::write_file(ofstream &ofs){ofs.write(_p,_size);}

DData::DData():DObject(0) {}

bool DData::isTrue()const{
    if(_type_id==7)return strcmp(_p,"")!=0;
    return *(bool *)shift_type(1).ptr();
}

DBoolean::DBoolean(bool n) :DData(1,1){
    char t(n);
    _p=new char[_size];
    memcpy(_p,&t,_size);
}


DSmallInt::DSmallInt(short n) :DData(2,2,(char *)&n){}
DInteger::DInteger(int n) : DData(3,4,(char *)&n){}
DBigInt::DBigInt(long long int n) :DData(4,8,(char *)&n){}
DFloat::DFloat(float n) :DData(5,4,(char *)&n){}
DDouble::DDouble(double n) :DData(6,8,(char *)&n){}
DVarchar::DVarchar(short size, const char *s):DData(7,size) {
    int len=strlen(s);
    if(len+1>size)throw SQLError("003",string("Varchar lenth is out of range.:")+s);
    _p=new char[size];
    strcpy(_p,s);
}

DVarchar::DVarchar(const char *s):DData(7,strlen(s)+1,s) {}

bool DLess::operator()(const DData &a, const DData &b) {
    return (a<b).isTrue();
}
DLess dLess;
