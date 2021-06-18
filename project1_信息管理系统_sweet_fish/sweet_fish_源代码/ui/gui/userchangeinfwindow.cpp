#include "userchangeinfwindow.h"
#include "ui_userchangeinfwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

UserChangeInfWindow::UserChangeInfWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::UserChangeInfWindow),
    pTBs(TBs),
   user_inf(_user_inf)
{
    ui->setupUi(this);
    table user=pTBs->Users.get_full_table().select(0,{1,users_table::len_uid,user_inf.get_item(0,0).get_string()},db_type_equal);
    ui->user_name_text->setText(user.get_item(0,1).get_string().c_str());
    ui->user_pwd_text->setText(user.get_item(0,2).get_string().c_str());
    ui->user_contact_text->setText(user.get_item(0,3).get_string().c_str());
    ui->user_home_text->setText(user.get_item(0,4).get_string().c_str());
    user_inf=user;
    connect(ui->postBtn,&QPushButton::clicked,this,&UserChangeInfWindow::clickPost);
}

UserChangeInfWindow::~UserChangeInfWindow()
{
    delete ui;
}

void UserChangeInfWindow::clickPost()
{
    QString name=ui->user_name_text->text(),pwd=ui->user_pwd_text->text(),contact=ui->user_contact_text->text(),home=ui->user_home_text->text();
    try {
        if(name.toUtf8().constData()!=user_inf.get_item(0,1).get_string())pTBs->Users.change_user_inf_str(user_inf,1,name.toUtf8().constData());
        pTBs->Users.change_user_inf_str(user_inf,2,pwd.toUtf8().constData());
        pTBs->Users.change_user_inf_str(user_inf,3,contact.toUtf8().constData());
        pTBs->Users.change_user_inf_str(user_inf,4,home.toUtf8().constData());
        QMessageBox::information(this,"修改成功","修改成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"修改错误",e.what());
    }
}
