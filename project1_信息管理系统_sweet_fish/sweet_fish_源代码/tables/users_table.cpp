//
// Created by hby on 2021/3/27.
//
#include "users_table.h"
#include "../error_solve/ErrorTB.h"

using namespace std;


users_table::users_table():base_table("users_table","users.tb") {
    if(!isFileExists(_src.c_str()))create_table();
    _table=table(_src.c_str(),0);
}


bool users_table::user_exist_uid(const string &uid) {
    return !_table.select(0,{1,len_uid,uid},db_type_equal).empty();
}

bool users_table::user_exist_name(const string &user) {
    return !_table.select(1,{1,len_name,user},db_type_equal).empty();
}

void users_table::create_table() {
    table users(7,
                {"UID","用户名","密码","联系方式","地址","钱包余额","用户权限"},
                {1,1,1,1,1,2,0},
                {len_uid,len_name,len_pwd,len_contact,len_home,len_cash,len_rank},
                0,'U');
    users.write_file(_src.c_str());
}

void users_table::login(table &user_inf,const string &user_name,const string &user_pwd) {
    table res=_table.select(1,{1,len_name,user_name},db_type_equal);
    if(res.empty())throw(ErrorTB("User_name doesn't exist.\n","403","登录失败: 用户不存在.\n"));
    if(res.select(2,{1,len_pwd,user_pwd},db_type_equal).empty())
        throw(ErrorTB("Pwd doesn't match.\n","404","登录失败: 密码错误.\n"));
    user_inf=res;
}

void users_table::logon(const string &name, const string &pwd, const string &contact,
                       const string &home, float cash, int rank) {
    if(name.empty())throw(ErrorTB("name is empty.","408","注册失败: 用户名为空!\n"));
    check_user_not_exist_by_name(name);
    if(pwd.empty())throw(ErrorTB("Pwd is empty.","409","注册失败: 密码为空!\n"));
    _table.insert({
                         CounterBase,
                         {1,len_name,name},
                         {1,len_pwd,pwd},
                         {1,len_contact,contact},
                         {1,len_home,home},
                         {2,len_cash,cash},
                         {0,len_rank,rank}
                 });
}

void users_table::admin_logon(const string &pwd,const string &contact,const string &home) {
    logon("admin",pwd,contact,home,1e4,2);
}

void users_table::change_cash_by_uid(const string &uid,float money) {
    //if(!user_exist_uid(uid))return 0;//用户不存在
    table user_inf(_table.select(0,{1,len_uid,uid},db_type_equal));
    if(user_inf.empty())throw(ErrorTB("User_uid doesn't exist","405","金钱操作失败: 您输入的用户不存在!\n"));
    float left_money=user_inf.get_item(0,5).get_float();
    if(left_money+money<0)
        throw(ErrorTB("Money is limited.","406","购买失败: 您的余额不足!\n"));
    _table.update(0,{1,len_uid,uid},5,{7,len_cash,money},db_type_equal);
}

void users_table::change_cash(const table &user, float money) {
    change_cash_by_uid(user.get_item(0,0).get_string(),money);
}

void users_table::change_user_inf_str_by_uid(const string &uid, int td_key, const string &value) {
    check_user_exist_by_uid(uid);
    if(td_key<=0||td_key>=5)throw(ErrorTB("This key can't be changed.","407","修改失败: 该值不可修改!\n"));
    if(td_key==1)check_user_not_exist_by_name(value);
    _table.update(0,{1,len_uid,uid},td_key,{1,var_size[td_key],value},db_type_equal);
}

void users_table::change_user_inf_str(const table &user, int td_key, const string &value) {
    string user_uid=user.get_item(0,0).get_string();
    change_user_inf_str_by_uid(user_uid,td_key,value);
}

void users_table::delete_user_by_uid(const string &uid) {
    check_user_exist_by_uid(uid);
    _table.Delete(0,{1,len_uid,uid},db_type_equal);
}

void users_table::admin_show_users() {
    _table.sub_table({0,1,3,6}).show();
}

void users_table::check_user_exist_by_name(const string &user) {
    if(!user_exist_name(user))throw(ErrorTB("User_name doesn't exist","401","您输入的用户不存在!\n"));
}

void users_table::check_user_exist_by_uid(const string &uid) {
    if(!user_exist_uid(uid))throw(ErrorTB("User_uid doesn't exist","402","您输入的用户不存在!\n"));
}

void users_table::check_user_not_exist_by_name(const string &user) {
    if(user_exist_name(user))throw(ErrorTB("User_name exist","401","您输入的用户已经存在!\n"));
}

