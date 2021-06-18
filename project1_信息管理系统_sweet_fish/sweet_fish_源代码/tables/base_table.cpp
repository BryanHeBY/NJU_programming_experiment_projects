//
// Created by hby on 2021/3/28.
//

#include "base_table.h"
#include <unistd.h>
#include <utility>
#include <ftw.h>

using namespace std;


string get_now_time() {
    char buff[22];
    const time_t now=time(NULL);
    tm *local_time=localtime(&now);
    strftime(buff,sizeof(buff),"%Y-%m-%d %H:%M:%S",local_time);
    return string(buff);
}

string get_now_date() {
    char buff[20];
    const time_t now=time(NULL);
    tm *local_time=localtime(&now);
    strftime(buff,sizeof(buff),"%Y-%m-%d",local_time);
    return string(buff);
}

bool base_table::isFileExists(const char *src) {
    ifstream f(src);
    return f.good();
}


base_table::base_table(string name, string src):_name(name),_src(src){}

void base_table::show() {
    _table.show();
}

void base_table::reload() {
    _table=table(_src.c_str());
}

void base_table::write_file() {
    _table.write_file(_src.c_str());
}

base_table::~base_table() {
    write_file();
}

const table &base_table::get_full_table() {
    return _table;
}



