//
// Created by hby on 2021/4/22.
//

#ifndef SQL_INTERPRETOR_SQLERROR_H
#define SQL_INTERPRETOR_SQLERROR_H
#include <exception>
#include <string>

using namespace std;

class SQLError: public exception{
private:
    string _code,_inf;
public:
    SQLError(string code,string inf):_code(code),_inf(code+" : "+inf){}
    const char * what()const throw(){
        return _inf.c_str();
    }
    const string code(){return _code;}
};


#endif //SQL_INTERPRETOR_SQLERROR_H
