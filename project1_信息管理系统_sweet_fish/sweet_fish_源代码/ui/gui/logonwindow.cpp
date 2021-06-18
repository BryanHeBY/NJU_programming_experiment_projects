#include "logonwindow.h"
#include "ui_logonwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

LogonWindow::LogonWindow(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::LogonWindow),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&LogonWindow::clickPost);
}

LogonWindow::~LogonWindow()
{
    delete ui;
}

void LogonWindow::clickPost()
{
    QString name=ui->user_name_text->text(),pwd=ui->user_pwd_text->text(),contact=ui->user_contact_text->text(),home=ui->user_home_text->text();
    try {
        pTBs->Users.logon(name.toUtf8().constData(),pwd.toUtf8().constData(),contact.toUtf8().constData(),home.toUtf8().constData());
        QMessageBox::information(this,"注册成功","注册成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"注册错误",e.what());
    }
}
