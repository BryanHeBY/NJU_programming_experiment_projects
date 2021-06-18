//
// Created by hby on 2021/3/29.
//

#ifndef INF_MAN_ERRORTB_H
#define INF_MAN_ERRORTB_H

#include <exception>
#include <string>
using namespace std;

class ErrorTB : public exception{
private:
    string _ErrorInf;
    string _Error_code;
    string _message;
public:
    ErrorTB(string ErrorInf,string Error_code,string message="");
    const char *what()const throw();
    const char *code()const throw();
};


#endif //INF_MAN_ERRORTB_H
