#include "getchangemerinf.h"
#include "ui_getchangemerinf.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include "changemerinfwindow.h"

GetChangeMerInf::GetChangeMerInf(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::GetChangeMerInf),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&GetChangeMerInf::clickPost);
}

GetChangeMerInf::~GetChangeMerInf()
{
    delete ui;
}

void GetChangeMerInf::clickPost()
{
    QString mid=ui->mer_mid_text->text();
    try {
        pTBs->Merchandises.check_mer_exist_by_mid(mid.toUtf8().constData());
        pTBs->Merchandises.check_mid_match_with_users(mid.toUtf8().constData(),user_inf);
        (new ChangeMerInfWindow(NULL,pTBs,user_inf,mid))->show();
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"修改错误",e.what());
    }
}
