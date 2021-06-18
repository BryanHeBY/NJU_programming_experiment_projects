#include "changemershowmodewindow.h"
#include "ui_changemershowmodewindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

ChangeMerShowModeWindow::ChangeMerShowModeWindow(QWidget *parent,TBSet *TBs,QTableView *tableView) :
    QWidget(parent),
    ui(new Ui::ChangeMerShowModeWindow),
    pTBs(TBs),
    pTableView(tableView)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&ChangeMerShowModeWindow::clickPost);
}

ChangeMerShowModeWindow::~ChangeMerShowModeWindow()
{
    delete ui;
}

void ChangeMerShowModeWindow::clickPost()
{
    try {
        table res;
        bool lesser;
        if(ui->check_lesser->isChecked())lesser=1;
        else lesser=0;
        if(ui->check_mid->isChecked()){
            res=pTBs->Merchandises.get_full_table().tr_sorted(0,lesser);
        }else if(ui->check_name->isChecked()){
            res=pTBs->Merchandises.get_full_table().tr_sorted(1,lesser);
        }else if(ui->check_price->isChecked()){
            res=pTBs->Merchandises.get_full_table().tr_sorted(2,lesser);
        }else if(ui->check_on_sale_time->isChecked()){
            res=pTBs->Merchandises.get_full_table().tr_sorted(5,lesser);
        }else if(ui->check_seller_uid->isChecked()){
            res=pTBs->Merchandises.get_full_table().tr_sorted(4,lesser);
        }
        if(ui->check_remore_invalid_mer->isChecked())res.Delete(6,{1,merchandises_table::len_state,"销售中"},db_type_not_equal);
        res.show_in_gui(pTableView);
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"搜索错误",e.what());
    }
}
