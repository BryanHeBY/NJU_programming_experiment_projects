#include "adminuserwindow.h"
#include "loginwindow.h"
#include "ui_adminuserwindow.h"
#include "adminuserinfchange.h"
#include "admindeleteuser.h"
#include "removemerwindow.h"
#include "searchmerwindow.h"
#include "adminsearchuser.h"
#include "adminsearchorderform.h"
#include "adminsearchmessage.h"
#include "changemershowmodewindow.h"
#include <QDebug>

AdminUserWindow::AdminUserWindow(QWidget *parent, TBSet *TBs) :
    QMainWindow(parent),
    ui(new Ui::AdminUserWindow),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->menu_logout,&QAction::triggered,this,&AdminUserWindow::user_logout);
    connect(ui->show_all_mer,&QPushButton::clicked,this,&AdminUserWindow::show_all_mer);
    connect(ui->menu_show_all_mer,&QAction::triggered,this,&AdminUserWindow::show_all_mer);
    connect(ui->change_mer_show_mode,&QPushButton::clicked,this,&AdminUserWindow::change_mer_show_mode);
    connect(ui->menu_change_mer_show_mode,&QAction::triggered,this,&AdminUserWindow::change_mer_show_mode);
    connect(ui->show_all_users,&QPushButton::clicked,this,&AdminUserWindow::show_all_users);
    connect(ui->menu_show_all_users,&QAction::triggered,this,&AdminUserWindow::show_all_users);
    connect(ui->show_all_order_form,&QPushButton::clicked,this,&AdminUserWindow::show_all_order_from);
    connect(ui->menu_show_all_order_form,&QAction::triggered,this,&AdminUserWindow::show_all_order_from);
    connect(ui->show_all_messages,&QPushButton::clicked,this,&AdminUserWindow::show_all_messages);
    connect(ui->menu_show_all_message,&QAction::triggered,this,&AdminUserWindow::show_all_messages);
    connect(ui->admin_user_inf_change,&QPushButton::clicked,this,&AdminUserWindow::admin_user_inf_change_func);
    connect(ui->menu_user_inf_change,&QAction::triggered,this,&AdminUserWindow::admin_user_inf_change_func);
    connect(ui->admin_delete_user,&QPushButton::clicked,this,&AdminUserWindow::admin_delete_user);
    connect(ui->menu_admin_delete_user,&QAction::triggered,this,&AdminUserWindow::admin_delete_user);
    connect(ui->admin_remove_mer,&QPushButton::clicked,this,&AdminUserWindow::admin_remove_mer);
    connect(ui->menu_admin_remove_mer,&QAction::triggered,this,&AdminUserWindow::admin_remove_mer);
    connect(ui->search_mer,&QPushButton::clicked,this,&AdminUserWindow::search_mer);
    connect(ui->menu_search_mer,&QAction::triggered,this,&AdminUserWindow::search_mer);
    connect(ui->admin_search_user,&QPushButton::clicked,this,&AdminUserWindow::admin_search_user);
    connect(ui->menu_admin_search_user,&QAction::triggered,this,&AdminUserWindow::admin_search_user);
    connect(ui->admin_search_order_form,&QPushButton::clicked,this,&AdminUserWindow::admin_search_order_form);
    connect(ui->menu_admin_search_order_form,&QAction::triggered,this,&AdminUserWindow::admin_search_order_form);
    connect(ui->admin_search_message,&QPushButton::clicked,this,&AdminUserWindow::admin_search_message);
    connect(ui->menu_admin_search_message,&QAction::triggered,this,&AdminUserWindow::admin_search_message);
}



AdminUserWindow::~AdminUserWindow()
{
    delete ui;
}

void AdminUserWindow::user_logout()
{
    LoginWindow *loginWindow=new LoginWindow(NULL,pTBs);
    loginWindow->show();
    this->close();
}

void AdminUserWindow::show_all_mer(){pTBs->Merchandises.get_full_table().show_in_gui(ui->uni_table);}
void AdminUserWindow::change_mer_show_mode(){(new ChangeMerShowModeWindow(NULL,pTBs,ui->uni_table))->show();}

void AdminUserWindow::show_all_users()
{
    pTBs->Users.get_full_table().show_in_gui(ui->uni_table);
}

void AdminUserWindow::show_all_order_from()
{
    pTBs->OrderForm.get_full_table().show_in_gui(ui->uni_table);
}

void AdminUserWindow::show_all_messages()
{
    pTBs->Messages.get_full_table().show_in_gui(ui->uni_table);
}

void AdminUserWindow::admin_user_inf_change_func(){(new AdminUserInfChange(NULL,pTBs))->show();}
void AdminUserWindow::admin_delete_user(){(new AdminDeleteUser(NULL,pTBs))->show();}
void AdminUserWindow::admin_remove_mer(){(new RemoveMerWindow(NULL,pTBs))->show();}
void AdminUserWindow::admin_search_user(){(new AdminSearchUser(NULL,pTBs))->show();}
void AdminUserWindow::admin_search_order_form(){(new AdminSearchOrderForm(NULL,pTBs))->show();}
void AdminUserWindow::admin_search_message(){(new AdminSearchMessage(NULL,pTBs))->show();}
void AdminUserWindow::search_mer(){(new SearchMerWindow(NULL,pTBs))->show();}
