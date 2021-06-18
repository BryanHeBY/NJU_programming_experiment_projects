#include "adminlogonwindow.h"
#include "ui_adminlogonwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

AdminLogonWindow::AdminLogonWindow(QWidget *parent, TBSet *TBs):
    QWidget(parent),
    ui(new Ui::AdminLogonWindow),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&AdminLogonWindow::clickPost);
}

AdminLogonWindow::~AdminLogonWindow()
{
    delete ui;
}

void AdminLogonWindow::clickPost()
{
    QString pwd=ui->user_pwd_text->text(),contact=ui->user_contact_text->text(),home=ui->user_home_text->text();
    try {
        pTBs->Users.admin_logon(pwd.toUtf8().constData(),contact.toUtf8().constData(),home.toUtf8().constData());
        QMessageBox::information(this,"注册成功","注册成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"注册错误",e.what());
    }
}
