//
// Created by hby on 2021/3/28.
//

#include "merchandises_table.h"
#include "../error_solve/ErrorTB.h"


merchandises_table::merchandises_table():base_table("merchandises","merchandises.tb") {
    if(!isFileExists(_src.c_str()))create_table();
    _table=table(_src.c_str(),0);
}

void merchandises_table::create_table() {
    table merchandises(8,
                       {"MID","商品名称","商品价格","商品描述","卖家UID","上架日期","商品状态","商品分类"},
                       {1,1,2,1,1,1,1,1},
                       {len_mid,len_name,len_price,len_description,len_seller_uid,len_on_sale_date,len_state,len_type_set},
                        0,'M');
    merchandises.write_file(_src.c_str());
}

bool merchandises_table::mer_exist_mid(const string &mid) {
    return !_table.select(0,{1,len_mid,mid},db_type_equal).empty();
}

void merchandises_table::check_mer_exist_by_mid(const string &mid) {
    if(!mer_exist_mid(mid))
        throw(ErrorTB("Mer_mid doesn't exist","501","您输入的商品不存在!\n"));
}

void merchandises_table::check_mer_state_is_valid_by_mid(const string &mid){
    string mer_state=_table.select(0,{1,len_mid,mid},db_type_equal).get_item(0,6).get_string();
    if(mer_state!="销售中")
        throw(ErrorTB("Mer_mid is not valid","504","您输入的商品无法操作!\n"));
}

void merchandises_table::check_mid_match_with_users(const string &mid, const table &user_inf) {
    if(_table.select(0,{1,len_mid,mid},db_type_equal).get_item(0,4).get_string()!=user_inf.get_item(0,0).get_string())
        throw(ErrorTB("With no right to remove","506","该商品不是您发布的，您无法操作!\n"));

}


void merchandises_table::post_mer(const table &seller_user,const string &name, float price,
                                  const string &description, const string &type_set) {
    if(name.empty())throw(ErrorTB("Mer_name is empty.","502","商品名不能为空!\n"));
    if(price<=0)throw(ErrorTB("Mer_price is not positive.","503","价格必须为正数!\n"));
    _table.insert({
        CounterBase,
        {1,len_name,name},
        {2,len_price,price},
        {1,len_description,description},
        {1,len_seller_uid,seller_user.get_item(0,0).get_string()},
        {1,len_on_sale_date,get_now_date()},
        {1,len_state,"销售中"},
        {1,len_type_set,type_set}
    });
}

void merchandises_table::remove_mer_by_mid(const string &mid) {
    check_mer_exist_by_mid(mid);
    check_mer_state_is_valid_by_mid(mid);
    _table.update(0,{1,len_mid,mid},6,{1,len_state,"已下架"},db_type_equal);
}

void merchandises_table::change_mer_inf_str_by_mid_by_user(const string &mid, const table &user_inf,int td_key, const string &to_value) {
    check_mer_exist_by_mid(mid);
    check_mid_match_with_users(mid,user_inf);
    if(td_key!=1&&td_key!=3&&td_key!=7)
        throw(ErrorTB("Mer_td_key is not changeable.","505","该属性值无法修改!\n"));
    if(td_key==1&&to_value.empty())
        throw(ErrorTB("Mer_name is empty.","502","商品名不能为空!\n"));
    _table.update(0,{1,len_mid,mid},td_key,{1,var_size[td_key],to_value},db_type_equal);
}

void merchandises_table::change_mer_price_by_mid_by_user(const string &mid, const table &user_inf,float price) {
    check_mer_exist_by_mid(mid);
    check_mid_match_with_users(mid,user_inf);
    if(price<=0)throw(ErrorTB("Mer_price is not positive.","503","价格必须为正数!\n"));
    _table.update(0,{1,len_mid,mid},2,{2,len_price,price},db_type_equal);
}

table merchandises_table::search_mer_by_seller_uid(const string &seller_uid) {
    return _table.select(4,{1,len_seller_uid,seller_uid},db_type_equal);
}

table merchandises_table::search_mer_by_name_equal(const string &name) {
    return _table.select(1,{1,len_name,name},db_type_equal);
}

table merchandises_table::search_mer_by_name_include(const string &name) {
    return _table.select(1,{1,len_name,name},db_type_str_include);
}


table merchandises_table::search_mer_by_type(const string &type) {
    return _table.select(7,{1,len_type_set,type},db_type_type_set_include);
}

void merchandises_table::buy_mer_by_mid(users_table &Users,order_form_table &OrderFrom,
                                        const table &user_inf, const string &mid) {
    check_mer_exist_by_mid(mid);
    check_mer_state_is_valid_by_mid(mid);
    string buyer_uid=user_inf.get_item(0,0).get_string();
    string seller_uid=_table.select(0,{1,len_mid,mid},db_type_equal).get_item(0,4).get_string();
    if(buyer_uid==seller_uid)throw (ErrorTB("Buyer and seller is the same!","506","您不能购买自己的商品!\n"));
    float cost=_table.select(0,{1,len_mid,mid},db_type_equal).get_item(0,2).get_float();
    Users.change_cash(user_inf,-cost);
    Users.change_cash_by_uid(seller_uid,cost);
    OrderFrom.post_form(mid,cost,buyer_uid,seller_uid);
    _table.update(0,{1,len_mid,mid},6,{1,len_state,"已出售"},db_type_equal);
}

table merchandises_table::search_mer_by_mid(const string &mid) {
    check_mer_exist_by_mid(mid);
    return _table.select(0,{1,len_mid,mid},db_type_equal);
}

void merchandises_table::remove_mer_by_mid_by_user(const table &user_inf, const string &mid) {
    check_mer_exist_by_mid(mid);
    check_mer_state_is_valid_by_mid(mid);
    check_mid_match_with_users(mid,user_inf);
    _table.update(0,{1,len_mid,mid},6,{1,len_state,"已下架"},db_type_equal);
}




