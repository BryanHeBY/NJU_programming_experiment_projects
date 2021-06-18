//
// Created by hby on 2021/3/28.
//

#ifndef INF_MAN_MERCHANDISES_TABLE_H
#define INF_MAN_MERCHANDISES_TABLE_H
#include "base_table.h"
#include "users_table.h"
#include "order_form_table.h"


class merchandises_table: public  base_table{
public:
    const static int len_mid=7,len_name=32,len_price=4,len_description=304,
            len_seller_uid=7,len_on_sale_date=11,len_state=10,len_type_set=100;
    const int var_size[8]={len_mid,len_name,len_price,len_description,len_seller_uid,
                           len_on_sale_date,len_state,len_type_set};
    merchandises_table();
    void create_table();
    bool mer_exist_mid(const string &mid);
    void check_mer_exist_by_mid(const string &mid);
    void check_mer_state_is_valid_by_mid(const string &mid);
    void check_mid_match_with_users(const string &mid,const table &user_inf);
    void post_mer(const table &seller_user,const string &name,float price,
                 const string &description,const string &type_set);
    void remove_mer_by_mid(const string &mid);
    void remove_mer_by_mid_by_user(const table &user_inf,const string &mid);
    void change_mer_inf_str_by_mid_by_user(const string &mid,const table &user_inf,int td_key,const string &to_value);
    void change_mer_price_by_mid_by_user(const string &mid,const table &user_inf,float price);
    table search_mer_by_mid(const string &mid);
    table search_mer_by_seller_uid(const string &seller_uid);
    table search_mer_by_name_equal(const string &name);
    table search_mer_by_name_include(const string &name);
    table search_mer_by_type(const string &type);
    void buy_mer_by_mid(users_table &Users,order_form_table &OrderForm,
                        const table &user_inf,const string &mid);

};


#endif //INF_MAN_MERCHANDISES_TABLE_H
