#include "adminuserinfchange.h"
#include "ui_adminuserinfchange.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

AdminUserInfChange::AdminUserInfChange(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::AdminUserInfChange),
    pTBs(TBs)
{
    ui->setupUi(this);
    _user_inf=pTBs->Users.get_full_table().select(1,{1,users_table::len_name,"admin"},db_type_equal);
    ui->user_pwd_text->setText(_user_inf.get_item(0,2).get_string().c_str());
    ui->user_contact_text->setText(_user_inf.get_item(0,3).get_string().c_str());
    ui->user_home_text->setText(_user_inf.get_item(0,4).get_string().c_str());
    connect(ui->postBtn,&QPushButton::clicked,this,&AdminUserInfChange::clickPost);
}

AdminUserInfChange::~AdminUserInfChange()
{
    delete ui;
}

void AdminUserInfChange::clickPost()
{
    QString pwd=ui->user_pwd_text->text(),contact=ui->user_contact_text->text(),home=ui->user_home_text->text();
    try {
        pTBs->Users.change_user_inf_str(_user_inf,2,pwd.toUtf8().constData());
        pTBs->Users.change_user_inf_str(_user_inf,3,contact.toUtf8().constData());
        pTBs->Users.change_user_inf_str(_user_inf,4,home.toUtf8().constData());
        QMessageBox::information(this,"修改成功","修改成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"修改错误",e.what());
    }
}

