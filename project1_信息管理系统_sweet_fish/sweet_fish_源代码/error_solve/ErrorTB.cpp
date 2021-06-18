//
// Created by hby on 2021/3/29.
//

#include "ErrorTB.h"


ErrorTB::ErrorTB(string ErrorInf, string Error_code, string message):
    _ErrorInf(ErrorInf),_Error_code(Error_code){
    if(!message.empty()){_message=+"Error_code: "+Error_code+" 错误信息: "+message;return;}
    _message=ErrorInf+" Error_code: "+Error_code;
}

const char *ErrorTB::what() const throw() {
    return _message.c_str();
}

const char *ErrorTB::code() const throw() {
    return _Error_code.c_str();
}

