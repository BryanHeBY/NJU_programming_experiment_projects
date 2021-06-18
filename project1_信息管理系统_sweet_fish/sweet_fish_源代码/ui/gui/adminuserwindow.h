#ifndef ADMINUSERWINDOW_H
#define ADMINUSERWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"

namespace Ui {
class AdminUserWindow;
}

class AdminUserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminUserWindow(QWidget *parent,TBSet *TBs);
    ~AdminUserWindow();
    void user_logout();
    void show_all_mer();
    void change_mer_show_mode();
    void show_all_users();
    void show_all_order_from();
    void show_all_messages();
    void admin_user_inf_change_func();
    void admin_delete_user();
    void admin_remove_mer();
    void admin_search_user();
    void admin_search_order_form();
    void admin_search_message();
    void search_mer();
private:
    Ui::AdminUserWindow *ui;
    TBSet *pTBs;
};

#endif // ADMINUSERWINDOW_H
