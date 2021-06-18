#include "userwindow.h"
#include "ui_userwindow.h"
#include "loginwindow.h"
#include "searchmerwindow.h"
#include "changemershowmodewindow.h"
#include <QDebug>
#include <QMessageBox>
#include "userchargewindow.h"
#include "sendmessagewindow.h"
#include "userchangeinfwindow.h"
#include "postmerwindow.h"
#include "getchangemerinf.h"
#include "userremovemerwindow.h"
#include "buymerwindow.h"

UserWindow::UserWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QMainWindow(parent),
    ui(new Ui::UserWindow),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->show_money,&QPushButton::clicked,this,&UserWindow::show_money);
    connect(ui->menu_show_money,&QAction::triggered,this,&UserWindow::show_money);
    connect(ui->user_charge,&QPushButton::clicked,this,&UserWindow::user_charge);
    connect(ui->menu_user_charge,&QAction::triggered,this,&UserWindow::user_charge);
    connect(ui->send_messages,&QPushButton::clicked,this,&UserWindow::send_messages);
    connect(ui->menu_send_messages,&QAction::triggered,this,&UserWindow::send_messages);
    connect(ui->show_my_receive_messages,&QPushButton::clicked,this,&UserWindow::show_my_receive_messages);
    connect(ui->menu_show_my_receive_messages,&QAction::triggered,this,&UserWindow::show_my_receive_messages);
    connect(ui->show_my_send_messages,&QPushButton::clicked,this,&UserWindow::show_my_send_messages);
    connect(ui->menu_show_my_send_messages,&QAction::triggered,this,&UserWindow::show_my_send_messages);
    connect(ui->user_change_inf,&QPushButton::clicked,this,&UserWindow::user_change_inf);
    connect(ui->menu_user_change_inf,&QAction::triggered,this,&UserWindow::user_change_inf);
    connect(ui->post_mer,&QPushButton::clicked,this,&UserWindow::post_mer);
    connect(ui->menu_post_mer,&QAction::triggered,this,&UserWindow::post_mer);
    connect(ui->remove_mer,&QPushButton::clicked,this,&UserWindow::remove_mer);
    connect(ui->menu_remove_mer,&QAction::triggered,this,&UserWindow::remove_mer);
    connect(ui->change_mer_inf,&QPushButton::clicked,this,&UserWindow::change_mer_inf);
    connect(ui->menu_change_mer_inf,&QAction::triggered,this,&UserWindow::change_mer_inf);
    connect(ui->show_my_sell_mer,&QPushButton::clicked,this,&UserWindow::show_my_sell_mer);
    connect(ui->menu_show_my_sell_mer,&QAction::triggered,this,&UserWindow::show_my_sell_mer);
    connect(ui->show_my_sell_order_form,&QPushButton::clicked,this,&UserWindow::show_my_sell_order_form);
    connect(ui->menu_show_my_sell_order_form,&QAction::triggered,this,&UserWindow::show_my_sell_order_form);
    connect(ui->show_all_mer,&QPushButton::clicked,this,&UserWindow::show_all_mer);
    connect(ui->menu_show_all_mer,&QAction::triggered,this,&UserWindow::show_all_mer);
    connect(ui->change_mer_show_mode,&QPushButton::clicked,this,&UserWindow::change_mer_show_mode);
    connect(ui->menu_change_mer_show_mode,&QAction::triggered,this,&UserWindow::change_mer_show_mode);
    connect(ui->search_mer,&QPushButton::clicked,this,&UserWindow::search_mer);
    connect(ui->menu_search_mer,&QAction::triggered,this,&UserWindow::search_mer);
    connect(ui->buy_mer,&QPushButton::clicked,this,&UserWindow::buy_mer);
    connect(ui->menu_buy_mer,&QAction::triggered,this,&UserWindow::buy_mer);
    connect(ui->show_my_buy_order_form,&QPushButton::clicked,this,&UserWindow::show_my_buy_order_form);
    connect(ui->menu_show_my_buy_order_form,&QAction::triggered,this,&UserWindow::show_my_buy_order_form);
    connect(ui->menu_user_logout,&QAction::triggered,this,&UserWindow::logout);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::show_money(){
    QMessageBox::information(this,"显示余额",QString("您的余额为: ")+pTBs->Users.get_full_table().select(0,{1,users_table::len_uid,user_inf.get_item(0,0).get_string()},db_type_equal).get_item(0,5).show_str().c_str()+"元");
}
void UserWindow::user_charge(){(new UserChargeWindow(NULL,pTBs,user_inf))->show();}
void UserWindow::show_my_send_messages(){pTBs->Messages.search_by_sender(user_inf).show_in_gui(ui->uni_table);}
void UserWindow::show_my_receive_messages(){pTBs->Messages.search_by_receiver(user_inf).show_in_gui(ui->uni_table);}
void UserWindow::send_messages(){(new SendMessageWindow(NULL,pTBs,user_inf))->show();}
void UserWindow::user_change_inf(){(new UserChangeInfWindow(NULL,pTBs,user_inf))->show();}
void UserWindow::post_mer(){(new PostMerWindow(NULL,pTBs,user_inf))->show();}
void UserWindow::remove_mer(){(new UserRemoveMerWindow(NULL,pTBs,user_inf))->show();}
void UserWindow::change_mer_inf(){(new GetChangeMerInf(NULL,pTBs,user_inf))->show();}
void UserWindow::show_my_sell_mer(){pTBs->Merchandises.search_mer_by_seller_uid(user_inf.get_item(0,0).get_string()).show_in_gui(ui->uni_table);}
void UserWindow::show_my_sell_order_form(){pTBs->OrderForm.search_by_seller_uid(user_inf.get_item(0,0).get_string()).show_in_gui(ui->uni_table);}
void UserWindow::show_all_mer(){pTBs->Merchandises.get_full_table().show_in_gui(ui->uni_table);}
void UserWindow::change_mer_show_mode(){(new ChangeMerShowModeWindow(NULL,pTBs,ui->uni_table))->show();}
void UserWindow::search_mer(){(new SearchMerWindow(NULL,pTBs))->show();}
void UserWindow::buy_mer(){(new BuyMerWindow(NULL,pTBs,user_inf))->show();}
void UserWindow::show_my_buy_order_form(){pTBs->OrderForm.search_by_buyer_uid(user_inf.get_item(0,0).get_string()).show_in_gui(ui->uni_table);}
void UserWindow::logout()
{
    (new LoginWindow(NULL,pTBs))->show();
    this->close();
}
