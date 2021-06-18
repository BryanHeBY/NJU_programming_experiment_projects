#include "loginwindow.h"
#include "logonwindow.h"
#include "adminuserwindow.h"
#include "ui_loginwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include "userwindow.h"

LoginWindow::LoginWindow(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::LoginWindow),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->loginBtn,&QPushButton::clicked,this,&LoginWindow::clickLogin);
    connect(ui->logonBtn,&QPushButton::clicked,this,&LoginWindow::clickLogon);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::clickLogin()
{
    QString user_name=ui->user_name_text->text();
    QString user_pwd=ui->user_pwd_text->text();
    table user_inf;
    try {
        pTBs->Users.login(user_inf,user_name.toUtf8().constData(),user_pwd.toUtf8().constData());
        if(user_inf.get_item(0,6).get_int()>=2){
            AdminUserWindow *adminUserWindow=new AdminUserWindow(NULL,pTBs);
            adminUserWindow->show();
            this->close();
        }else{
            UserWindow *userWindow=new UserWindow(NULL,pTBs,user_inf);
            userWindow->show();
            this->close();
        }
        QMessageBox::information(this,"登录成功","登录成功！");

    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"登录错误",e.what());
    }
}

void LoginWindow::clickLogon()
{
    LogonWindow *logonWindow=new LogonWindow(NULL,pTBs);
    logonWindow->show();
}
