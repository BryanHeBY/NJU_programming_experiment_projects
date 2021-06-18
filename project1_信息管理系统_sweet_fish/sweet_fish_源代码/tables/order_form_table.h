//
// Created by hby on 2021/3/29.
//

#ifndef INF_MAN_ORDER_FORM_TABLE_H
#define INF_MAN_ORDER_FORM_TABLE_H
#include "base_table.h"


class order_form_table: public base_table {
public:
    const static int len_oid=7,len_mer_mid=7,len_mer_price=4,len_buyer_uid=7,len_seller_uid=7,len_deal_time=20;
    const int var_size[6]={len_oid,len_mer_mid,len_mer_price,len_buyer_uid,len_seller_uid,len_deal_time};
    void create_table();
    order_form_table();
    void post_form(const string &mer_mid,float mer_price,const string &buyer_uid,const string &seller_uid);
    table search_by_buyer_uid(const string &buyer_uid);
    table search_by_seller_uid(const string &seller_uid);
};


#endif //INF_MAN_ORDER_FORM_TABLE_H
