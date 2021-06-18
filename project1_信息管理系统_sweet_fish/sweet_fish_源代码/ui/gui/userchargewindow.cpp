#include "userchargewindow.h"
#include "ui_userchargewindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>


UserChargeWindow::UserChargeWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::UserChargeWindow),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&UserChargeWindow::clickPost);
}

UserChargeWindow::~UserChargeWindow()
{
    delete ui;
}

void UserChargeWindow::clickPost()
{
    QString charge_code=ui->charge_code_text->text();
    float money=ui->money_text->text().toFloat();
    try {
        if(charge_code=="123456"){
            if(money<=0)throw(ErrorTB("money is not possitive!","900","充值金额必须为正数"));
            pTBs->Users.change_cash(user_inf,money);
            QMessageBox::information(this,"充值成功","充值成功！");
            this->close();
        }
        else QMessageBox::warning(this,"充值失败","充值码错误！");
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"充值失败",e.what());
    }
}

