#include "searchmerwindow.h"
#include "ui_searchmerwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

SearchMerWindow::SearchMerWindow(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::SearchMerWindow),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&SearchMerWindow::clickPost);
}

SearchMerWindow::~SearchMerWindow()
{
    delete ui;
}

void SearchMerWindow::clickPost()
{
    try {
        QString search_content=ui->search_content_text->text();
        table res;
        if(ui->check_mid->isChecked()){
            res=pTBs->Merchandises.search_mer_by_mid(search_content.toUtf8().constData());
        }else if(ui->check_name_equal->isChecked()){
            res=pTBs->Merchandises.search_mer_by_name_equal(search_content.toUtf8().constData());
        }else if(ui->check_name_include->isChecked()){
            res=pTBs->Merchandises.search_mer_by_name_include(search_content.toUtf8().constData());
        }else if(ui->check_seller_uid->isChecked()){
            res=pTBs->Merchandises.search_mer_by_seller_uid(search_content.toUtf8().constData());
        }
        else if(ui->check_type->isChecked()){
                res=pTBs->Merchandises.search_mer_by_type(search_content.toUtf8().constData());
            }
        QTableView *qTableView=new QTableView();
        qTableView->resize(800,400);
        res.show_in_gui(qTableView);
        qTableView->show();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"搜索错误",e.what());
    }
}
