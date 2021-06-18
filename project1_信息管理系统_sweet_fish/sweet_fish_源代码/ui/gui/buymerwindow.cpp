#include "buymerwindow.h"
#include "ui_buymerwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

BuyMerWindow::BuyMerWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::BuyMerWindow),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&BuyMerWindow::clickPost);
}

BuyMerWindow::~BuyMerWindow()
{
    delete ui;
}

void BuyMerWindow::clickPost()
{
    QString mid=ui->mer_mid_text->text();
    try {
        pTBs->Merchandises.buy_mer_by_mid(pTBs->Users,pTBs->OrderForm,user_inf,mid.toUtf8().constData());
        QMessageBox::information(this,"购买成功","购买成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"修改错误",e.what());
    }
}
