//
// Created by hby on 2021/5/28.
//

#include <iostream>
#include <cmath>
#include "EObject.h"
#include "EEnv.h"

int EObject::get_type_id() const {
    return _type_id;
}

bool EObject::is_instance(int type_id) const {
    return _type_id==type_id;
}

EObject::EObject(int type_id):_type_id(type_id){}

ostream &operator<<(ostream &os, const EObject &a) {
    if(a.is_instance(ECALL))os<<*(ECall*)&a;
    else os<<*(EData*)&a;
    return os;
}


EData::EData():EObject(ENONE) {}
EData::EData(int int_n) :EObject(EINT),_p({.INT=int_n}){}
EData::EData(float float_n):EObject(EFLOAT),_p({.FLOAT=float_n}){}

EData EData::to_float()const{
    if(is_instance(EINT))return EData((float)_p.INT);
    else return *this;
}

EData EData::operator+(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT+b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT+b._p.FLOAT);
    return EData(to_float()._p.FLOAT+b.to_float()._p.FLOAT);
}

EData EData::operator-(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT-b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT-b._p.FLOAT);
    return EData(to_float()._p.FLOAT-b.to_float()._p.FLOAT);
}

EData EData::operator*(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT*b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT*b._p.FLOAT);
    return EData(to_float()._p.FLOAT*b.to_float()._p.FLOAT);
}

EData EData::operator/(const EData &b) const {
    if(b.is_zero())throw EError("101","Divide zero error.");
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT/b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT/b._p.FLOAT);
    return EData(to_float()._p.FLOAT/b.to_float()._p.FLOAT);
}

bool EData::is_zero()const {
    if(is_instance(EINT))return _p.INT==0;
    else return fabs(_p.FLOAT)<1e-6;
}

EData EData::operator%(const EData &b) const {
    if(b.is_zero())throw EError("101","Divide zero error.");
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT%b._p.INT);
    else throw EError("102","Float number remain error.");
}

EData EData::operator&&(const EData &b) const {
    return EData(!(is_zero()||b.is_zero()));
}

EData EData::operator||(const EData &b) const {
    return EData(!(is_zero()&&b.is_zero()));
}

EData EData::operator==(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT==b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT==b._p.FLOAT);
    return EData(to_float()._p.FLOAT==b.to_float()._p.FLOAT);
}

EData EData::operator!=(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT!=b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT!=b._p.FLOAT);
    return EData(to_float()._p.FLOAT!=b.to_float()._p.FLOAT);
}

EData EData::operator<(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT<b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT<b._p.FLOAT);
    return EData(to_float()._p.FLOAT<b.to_float()._p.FLOAT);
}

EData EData::operator<=(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT<=b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT<=b._p.FLOAT);
    return EData(to_float()._p.FLOAT<=b.to_float()._p.FLOAT);
}

EData EData::operator>(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT>b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT>b._p.FLOAT);
    return EData(to_float()._p.FLOAT>b.to_float()._p.FLOAT);
}

EData EData::operator>=(const EData &b) const {
    if(_type_id==EINT&&b._type_id==EINT)return EData(_p.INT>=b._p.INT);
    else if(_type_id==EFLOAT&&b._type_id==EFLOAT)return EData(_p.FLOAT>=b._p.FLOAT);
    return EData(to_float()._p.FLOAT>=b.to_float()._p.FLOAT);
}

EData EData::eval(const EEnv &env) const {
    return *this;
}

ostream &operator<<(ostream &os, const EData &a) {
    if(a.is_instance(ENONE))os<<"NONE";
    else if(a.is_instance(EINT))os<<a._p.INT;
    else if(a.is_instance(EFLOAT))os<<a._p.FLOAT;
    return os;
}

EData::EData(EObject *ref_n):EObject(EREF),_p({.REF=ref_n}){}

EObject *EData::ref()const{
    if(!is_instance(EREF))throw EError("401","Not a ref");
    return _p.REF;
}

EData EData::operator-()const{
    if(is_instance(EINT))return EData(-_p.INT);
    else if(is_instance(EFLOAT))return EData(-_p.FLOAT);
}

EData EData::epow(const EData &b) const {
    return EData(pow(to_float()._p.FLOAT,b.to_float()._p.FLOAT));
}

float EData::float_value() const {
    return to_float()._p.FLOAT;
}

EData EData::abs()const{
    if(is_instance(EINT))return EData(::abs(_p.INT));
    else if(is_instance(EFLOAT))return EData(fabs(_p.FLOAT));
}

int EData::int_value() const {
    return _p.INT;
}


