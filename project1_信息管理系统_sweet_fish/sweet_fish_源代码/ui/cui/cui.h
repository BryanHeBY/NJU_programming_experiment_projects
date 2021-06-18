//
// Created by hby on 2021/3/27.
//

#ifndef INF_MAN_CUI_H
#define INF_MAN_CUI_H
#include "../../core_module/table.h"
#include "../../tables/users_table.h"
#include "../../tables/merchandises_table.h"
#include "../../tables/order_form_table.h"
#include "../../tables/messages_table.h"
#include <iostream>

class CUI{
private:
    users_table _Users;
    merchandises_table _Merchandises;
    order_form_table _OrderForm;
    messages_table _Messages;
public:
    void save_file();
    bool mainloop();
    bool user_logon_admin();
    void user_logon();
    int user_login(table &user_inf);
    bool default_user_window(const table &user_inf);
    bool admin_user_window(const table &user_inf);

    void show_mer();
    bool search_mer();
    void admin_remove_mer();
    void admin_manage_users();
    void admin_manage_mer();
    void admin_manage_order_form();

    bool seller_mode(const table &user_inf);
    bool buyer_mode(const table &user_inf);
    void user_show_order_form(const table &user_inf);
    void change_user_inf(const table &user_inf);
    void seller_post_mer(const table &user_inf);
    void seller_remove_mer(const table &user_inf);
    void seller_change_mer(const table &user_inf);
    void user_charge(const table &user_inf);

    void messages_manage_mode(const table &user_inf);
};


#endif //INF_MAN_CUI_H
