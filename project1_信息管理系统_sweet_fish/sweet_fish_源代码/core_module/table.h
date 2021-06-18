//
// Created by hby on 2021/3/26.
//

#ifndef INF_MAN_TABLE_H
#define INF_MAN_TABLE_H
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <QTableView>
#include "db_type.h"

using namespace std;

struct fixed_chars{
    char t[16];
    fixed_chars();
    fixed_chars(string value);
    fixed_chars(const char *value);
};

class table{
protected:
    int _vars_num,_counter;char _pre_token;
    vector<fixed_chars> _vars_name;
    vector<int> _vars_type_id;
    vector<int> _vars_size;
    vector<vector<db_type>> _content;
    //加速模块
    bool _open_map_accelerate;int _second_primary_key;
    map<string,string> _name_uid_map;
    /*存储结构与文件当中的结构相同
     * 1. 数据表表头变量个数, 当前ID自动生成的计数器, 生成的ID的首字母
     * 2. 变量(表头)名, 变量的类型ID, 变量占用内存大小
     * 3. 按照变量格式连续线性存储
     */
public:
    table();//默认构造
    table(const char *src,bool open_map_accelerate=false,int second_primary_key=1);//读取数据表文件构造
    table(int vars_num,const vector<fixed_chars> &vars_name,const vector<int> &vars_type_id,
          const vector<int> &vars_size,int counter=0,char pre_token='A',bool open_map_accelerate= false);//设置参数构造
    virtual void write_file(const char *src)const;//写入数据表文件
    bool empty()const;//判断表_content是否为空
    const db_type get_item(int i,int j)const;//获得表格内容


    //ID生成器
    db_type generate_id();
    //INSERT INTO {table} VALUES ({value for value in values});
    void insert(const vector<db_type> &values);
    //复制其他表的表头
    void cp_head(const table *other);

    //SELECT * FROM {table} WHERE {table[td+key]}(*judge){value};
    table select(int td_key,const db_type &value,bool (*judge)(const db_type&,const db_type&))const;

    //UPDATE {table} SET {table[to_key]}={to_value} WHERE {table[td_key]}(*judge){pre_value};
    void update(int td_key,const db_type &pre_value,int to_key,const db_type &to_value,bool (*judge)(const db_type&,const db_type&));

    //DELETE from {table} WHERE {table[td+key]}(*judge){value};
    void Delete(int td_key,const db_type &value,bool (*judge)(const db_type&,const db_type&));
    //SELECT * FROM {table} ORDER BY {table[td_key]} {sort_lesser?}ASC{:}DESC;
    void tr_sort(int td_key,bool sort_lesser);
    table tr_sorted(int td_key,bool sort_lesser)const;
    //SELECT {table[td_key] for td_key in td_vars} FROM {table};
    table sub_table(const vector<int> &td_vars)const;
    //SELECT * FROM {table} LIMIT {limit_num};
    table limit(int limit_num)const;

    void show()const;//多个表格显示通用CUI接口
    void show_details()const;//表格竖排版CUI展示接口
    void show_in_gui(QTableView *tableView=new QTableView(NULL))const;


};

int get_str_len(string str);
#endif //INF_MAN_TABLE_H
