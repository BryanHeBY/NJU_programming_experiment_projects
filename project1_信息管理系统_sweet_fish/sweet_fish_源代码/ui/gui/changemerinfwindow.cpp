#include "changemerinfwindow.h"
#include "ui_changemerinfwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

ChangeMerInfWindow::ChangeMerInfWindow(QWidget *parent,TBSet *TBs,const table &_user_inf,const QString &_mid) :
    QWidget(parent),
    ui(new Ui::ChangeMerInfWindow),
    pTBs(TBs),
    user_inf(_user_inf),
    mid(_mid)
{
    ui->setupUi(this);
    table this_mer=pTBs->Merchandises.get_full_table().select(0,{1,merchandises_table::len_mid,mid.toUtf8().constData()},db_type_equal);
    ui->mer_name_text->setText(this_mer.get_item(0,1).get_string().c_str());
    ui->mer_price_text->setText(this_mer.get_item(0,2).show_str().c_str());
    ui->mer_description_text->setText(this_mer.get_item(0,3).get_string().c_str());
    ui->mer_type_set_text->setText(this_mer.get_item(0,7).get_string().c_str());
    connect(ui->postBtn,&QPushButton::clicked,this,&ChangeMerInfWindow::clickPost);
}

ChangeMerInfWindow::~ChangeMerInfWindow()
{
    delete ui;
}

void ChangeMerInfWindow::clickPost()
{
    QString name=ui->mer_name_text->text(),description=ui->mer_description_text->text(),type_set=ui->mer_type_set_text->text();
    float price=ui->mer_price_text->text().toFloat();
    try {
        pTBs->Merchandises.change_mer_inf_str_by_mid_by_user(mid.toUtf8().constData(),user_inf,1,name.toUtf8().constData());
        pTBs->Merchandises.change_mer_price_by_mid_by_user(mid.toUtf8().constData(),user_inf,price);
        pTBs->Merchandises.change_mer_inf_str_by_mid_by_user(mid.toUtf8().constData(),user_inf,3,description.toUtf8().constData());
        pTBs->Merchandises.change_mer_inf_str_by_mid_by_user(mid.toUtf8().constData(),user_inf,7,type_set.toUtf8().constData());
        QMessageBox::information(this,"修改成功","修改成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"修改错误",e.what());
    }
}
