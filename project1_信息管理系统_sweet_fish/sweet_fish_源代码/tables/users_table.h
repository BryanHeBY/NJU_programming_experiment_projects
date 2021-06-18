//
// Created by hby on 2021/3/27.
//

#ifndef INF_MAN_USERS_TABLE_H
#define INF_MAN_USERS_TABLE_H
#include "base_table.h"

using namespace std;

class users_table: public base_table{
public:
    const static int len_uid=7,len_name=32,len_pwd=24,len_contact=24,
        len_home=64,len_cash=4,len_rank=4;
    const int var_size[7]={len_uid,len_name,len_pwd,len_contact,
                           len_home,len_cash,len_rank};
    users_table();
    void create_table();
    bool user_exist_name(const string &user);
    bool user_exist_uid(const string &uid);
    void check_user_exist_by_name(const string &user);
    void check_user_not_exist_by_name(const string &user);
    void check_user_exist_by_uid(const string &uid);
    void login(table &user_inf,const string &user_name,const string &user_pwd);
    void logon(const string &name,const string &pwd,const string &contact,
              const string &home,float cash=0,int rank=0);
    void admin_logon(const string &pwd,const string &contact,const string &home);

    void change_cash_by_uid(const string &uid,float money);
    void change_cash(const table &user,float money);
    void change_user_inf_str_by_uid(const string &uid,int td_key,const string &value);
    void change_user_inf_str(const table &user,int td_key,const string &value);
    void delete_user_by_uid(const string &uid);
    void admin_show_users();
};


#endif //INF_MAN_USERS_TABLE_H
