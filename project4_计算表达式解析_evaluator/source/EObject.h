//
// Created by hby on 2021/5/28.
//

#ifndef EVALUATER_EObject_H
#define EVALUATER_EObject_H

#define ENONE 0
#define EINT 1
#define EFLOAT 2
#define EREF 3

#include <exception>
#include <string>
using namespace std;

class EError: public exception{
private:
    string _code,_inf;
public:
    EError(string code, string inf):_code(code),_inf(code+": "+inf){}
    const char * what()const throw(){
        return _inf.c_str();
    }
    const string code(){return _code;}
};

class EEnv;
class EFunc;
class EData;

class EObject{
protected:
    int _type_id;
public:
    EObject(int type_id);
    int get_type_id()const;
    bool is_instance(int type_id)const;
    virtual ~EObject()=default;
    virtual EData eval(const EEnv &env)const=0;
    friend ostream &operator<<(ostream &os,const EObject &a);
};

class EData: public EObject{
    union DATA{
        int INT;
        float FLOAT;
        EObject *REF;
    }_p;
public:
    EData();
    EData(int int_n);
    EData(float float_n);
    EData(EObject *ref_n);
    bool is_zero()const;
    EData to_float()const;
    EObject *ref()const;
    EData eval(const EEnv &env)const;
    EData operator-()const;
    EData operator+(const EData &b)const;
    EData operator-(const EData &b)const;
    EData operator*(const EData &b)const;
    EData operator/(const EData &b)const;
    EData operator%(const EData &b)const;
    EData operator==(const EData &b)const;
    EData operator!=(const EData &b)const;
    EData operator<(const EData &b)const;
    EData operator<=(const EData &b)const;
    EData operator>(const EData &b)const;
    EData operator>=(const EData &b)const;
    EData operator&&(const EData &b)const;
    EData operator||(const EData &b)const;
    EData epow(const EData &b)const;
    EData abs()const;
    float float_value()const;
    int int_value()const;
    friend ostream &operator<<(ostream &os,const EData &a);
};
#endif //EVALUATER_EEObject_H
