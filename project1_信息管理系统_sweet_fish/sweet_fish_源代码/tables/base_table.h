//
// Created by hby on 2021/3/28.
//

#ifndef INF_MAN_BASE_TABLE_H
#define INF_MAN_BASE_TABLE_H
#include <string>
#include "../core_module/table.h"

using namespace std;
string get_now_time();
string get_now_date();

class base_table{
protected:
    string _name,_src;
    table _table;
public:
    static bool isFileExists(const char *src);
    base_table(string name,string src);
    ~base_table();
    void show();
    void reload();
    void write_file();
    const table &get_full_table();
};


#endif //INF_MAN_BASE_TABLE_H
