//
// Created by hby on 2021/3/26.
//

#ifndef INF_MAN_DB_TYPE_H
#define INF_MAN_DB_TYPE_H
#include <string>
using namespace std;

//数据库变量类型基类
class db_type{
protected:
    //类型id,类型大小
    int _type_id,_size;
    char *_p; //内存,文件传递指针
public:
    friend bool db_type_str_include(const db_type &td,const db_type &value);
    friend bool db_type_type_set_include(const db_type &td,const db_type &value);
    char *_protected_get_p();
    db_type(int type_id,int size); //一般的指定类型id以及类型大小的构造函数
    db_type(const db_type &other); //拷贝构造函数
    //三种类型直接进行初始化
    db_type(int type_id,int size,int value);
    db_type(int type_id,int size,string value);
    db_type(int type_id,int size,float value);
    ~db_type();

    //载入与获得信息
    int get_type_id() const;
    int get_size() const;
    void load_int(int value);
    void load_string(string &value);
    void load_float(float value);
    int get_int()const;
    const string get_string()const;
    float get_float()const;

    //重载符号
    bool same_type(const db_type &other)const;
    db_type &operator =(const db_type &other);
    db_type &operator +=(const db_type &other);
    bool operator == (const db_type &other)const;
    bool operator < (const db_type &other)const;
    bool operator > (const db_type &other)const;

    //CUI输出模块
    void show()const;
    string show_str()const;
};


//为 SELECT UPDATE DELETE 等操作提供匹配依据
bool db_type_equal(const db_type &a,const db_type &b);//完全匹配
bool db_type_not_equal(const db_type &a,const db_type &b);//不相符则匹配
bool db_type_str_include(const db_type &td,const db_type &value);//字符串包含匹配
bool db_type_type_set_include(const db_type &td,const db_type &value);//进行商品分类匹配


const db_type CounterBase(-1,1,-1);//INSERT时自动转换为相应IO

#endif //INF_MAN_DB_TYPE_H
