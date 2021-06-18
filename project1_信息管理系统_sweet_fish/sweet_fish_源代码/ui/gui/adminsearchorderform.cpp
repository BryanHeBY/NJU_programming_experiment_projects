#include "adminsearchorderform.h"
#include "ui_adminsearchorderform.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

AdminSearchOrderForm::AdminSearchOrderForm(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::AdminSearchOrderForm),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&AdminSearchOrderForm::clickPost);
}

AdminSearchOrderForm::~AdminSearchOrderForm()
{
    delete ui;
}

void AdminSearchOrderForm::clickPost()
{
    try {
        QString search_content=ui->search_content_text->text();
        table res;
        if(ui->check_oid->isChecked()){
            res=pTBs->OrderForm.get_full_table().select(0,{1,order_form_table::len_oid,search_content.toUtf8().constData()},db_type_equal);
        }else if(ui->check_seller_uid->isChecked()){
            res=pTBs->OrderForm.search_by_seller_uid(search_content.toUtf8().constData());
        }
        else if(ui->check_buyer_uid->isChecked()){
            res=pTBs->OrderForm.search_by_buyer_uid(search_content.toUtf8().constData());
        }
        QTableView *qTableView=new QTableView();
        qTableView->resize(800,400);
        res.show_in_gui(qTableView);
        qTableView->show();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"搜索错误",e.what());
    }
}
