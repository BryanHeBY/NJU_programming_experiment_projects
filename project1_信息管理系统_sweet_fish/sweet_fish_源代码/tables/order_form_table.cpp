//
// Created by hby on 2021/3/29.
//

#include "order_form_table.h"

void order_form_table::create_table() {
    table order_form(
            6,
            {"OID","商品MID","商品价格","买家UID","卖家UID","交易时间"},
            {1,1,2,1,1,1},
            {len_oid,len_mer_mid,len_mer_price,len_buyer_uid,len_seller_uid,len_deal_time},
            0,'O'
            );
    order_form.write_file(_src.c_str());
}

order_form_table::order_form_table():base_table("order_from","order_form.tb"){
    if(!isFileExists(_src.c_str()))create_table();
    _table=table(_src.c_str(),1,3);
}


void order_form_table::post_form(const string &mer_mid, float mer_price,const string &buyer_uid, const string &seller_uid) {
    _table.insert({
              CounterBase,
              {1, len_mer_mid, mer_mid},
              {2, len_mer_price, mer_price},
              {1,len_buyer_uid,buyer_uid},
              {1,len_seller_uid,seller_uid},
              {1,len_deal_time,get_now_time()}
              });
}

table order_form_table::search_by_buyer_uid(const string &buyer_uid) {
    return _table.select(3,{1,len_buyer_uid,buyer_uid},db_type_equal).tr_sorted(3,0);
}

table order_form_table::search_by_seller_uid(const string &seller_uid) {
    return _table.select(4,{1,len_buyer_uid,seller_uid},db_type_equal).tr_sorted(4,0);
}

