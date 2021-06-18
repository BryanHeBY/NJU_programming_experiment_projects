#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent,TBSet *TBs,const table &user_inf);
    ~UserWindow();
    void show_money();
    void user_charge();
    void send_messages();
    void show_my_send_messages();
    void show_my_receive_messages();
    void user_change_inf();
    void post_mer();
    void remove_mer();
    void change_mer_inf();
    void show_my_sell_mer();
    void show_my_sell_order_form();
    void show_all_mer();
    void change_mer_show_mode();
    void search_mer();
    void buy_mer();
    void show_my_buy_order_form();
    void logout();

private:
    Ui::UserWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // USERWINDOW_H
