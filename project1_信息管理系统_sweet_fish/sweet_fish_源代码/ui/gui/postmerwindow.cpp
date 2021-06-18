#include "postmerwindow.h"
#include "ui_postmerwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

PostMerWindow::PostMerWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::PostMerWindow),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&PostMerWindow::clickPost);
}

PostMerWindow::~PostMerWindow()
{
    delete ui;
}

void PostMerWindow::clickPost()
{
    QString name=ui->mer_name_text->text(),description=ui->mer_description_text->text(),type_set=ui->mer_type_set_text->text();
    float price=ui->mer_price_text->text().toFloat();
    try {
        pTBs->Merchandises.post_mer(user_inf,name.toUtf8().constData(),price,description.toUtf8().constData(),type_set.toUtf8().constData());
        QMessageBox::information(this,"发布成功","发布成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"注册错误",e.what());
    }
}
