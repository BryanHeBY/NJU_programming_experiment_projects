#include "userremovemerwindow.h"
#include "ui_userremovemerwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

UserRemoveMerWindow::UserRemoveMerWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::UserRemoveMerWindow),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&UserRemoveMerWindow::clickPost);
}

UserRemoveMerWindow::~UserRemoveMerWindow()
{
    delete ui;
}

void UserRemoveMerWindow::clickPost()
{
    QString mid=ui->mer_mid_text->text();
    try {
        pTBs->Merchandises.remove_mer_by_mid_by_user(user_inf,mid.toUtf8().constData());
        QMessageBox::information(this,"下架成功","下架成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"修改错误",e.what());
    }
}
