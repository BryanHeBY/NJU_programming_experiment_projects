//
// Created by hby on 2021/4/21.
//

#ifndef SQL_INTERPRETOR_DOBJECT_H
#define SQL_INTERPRETOR_DOBJECT_H

#include <string>
#include <fstream>


using namespace std;

class DObject {
protected:
    short int _type_id;
public:
    DObject(short _type_id);
    int get_type_id()const;
    virtual ~DObject()=default;
};

class DData;
class DBoolean;
class DSmallInt;
class DInteger;
class DBigInt;
class DFloat;
class DDouble;
class DVarchar;


class DData: public DObject{
protected:
    short int _size;
    char *_p;
public:
    DData();
    DData(short type_id,short size,const char *p);
    DData(short type_id,short size);
    DData(short type_id,short size,ifstream &ifs);
    DData(const DData &other);
    DData &operator=(const DData &other);
    ~DData();
    short int size()const;
    const char *ptr()const;

    DData shift_type(short to_type,int to_size=-1)const;
    DData operator + (const DData &other)const;
    DData operator - (const DData &other)const;
    DData operator * (const DData &other)const;
    DData operator / (const DData &other)const;
    DData operator == (const DData &other)const;
    DData operator < (const DData &other)const;
    DData operator <= (const DData &other)const;
    DData operator > (const DData &other)const;
    DData operator >= (const DData &other)const;
    DData operator ! ()const;
    DData operator && (const DData &other)const;
    DData operator || (const DData &other)const;
    bool isTrue()const;
    friend ostream &operator<<(ostream &os,const DData &dDate);
    void write_file(ofstream &ofs);
};

struct DLess{bool operator()(const DData &a,const DData &b);};
extern DLess dLess;

class DBoolean: public DData{
public:
    DBoolean(bool n);
};

class DSmallInt: public DData{
public:
    DSmallInt(short int n);
};

class DInteger: public DData{
public:
    DInteger(int n);
};

class DBigInt: public DData{
public:
    DBigInt(long long n);
};

class DFloat: public DData{
public:
    DFloat(float n);
};

class DDouble: public DData{
public:
    DDouble(double n);
};

class DVarchar: public DData{
public:
    DVarchar(short size,const char *s);
    DVarchar(const char *s);
};



#endif //SQL_INTERPRETOR_DOBJECT_H
