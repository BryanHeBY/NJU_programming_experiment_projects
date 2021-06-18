//
// Created by hby on 2021/5/30.
//

#ifndef EVALUATER_PARSER_H
#define EVALUATER_PARSER_H

#include <regex>
#include "EFunc.h"
#include<queue>

#define TEND 0
#define TENDP 1
#define TENDC 2

using namespace std;

void split_without_none(const string& s,queue<string>& sv,const char flag);

EObject *get_expr(string str);
void init_parser();

bool senctence_with_end(const string &sentence,EEnv &env, bool interpreter_mode);

#endif //EVALUATER_PARSER_H
