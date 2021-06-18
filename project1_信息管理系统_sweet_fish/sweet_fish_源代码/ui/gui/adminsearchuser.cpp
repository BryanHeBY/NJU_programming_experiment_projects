#include "adminsearchuser.h"
#include "ui_adminsearchuser.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

AdminSearchUser::AdminSearchUser(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::AdminSearchUser),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&AdminSearchUser::clickPost);
}

AdminSearchUser::~AdminSearchUser()
{
    delete ui;
}

void AdminSearchUser::clickPost()
{
    try {
        QString search_content=ui->search_content_text->text();
        table res;
        if(ui->check_uid->isChecked()){
            res=pTBs->Users.get_full_table().select(0,{1,users_table::len_uid,search_content.toUtf8().constData()},db_type_equal);
        }else if(ui->check_name->isChecked()){
            res=pTBs->Users.get_full_table().select(1,{1,users_table::len_name,search_content.toUtf8().constData()},db_type_equal);
        }
        QTableView *qTableView=new QTableView();
        qTableView->resize(800,400);
        res.show_in_gui(qTableView);
        qTableView->show();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"搜索错误",e.what());
    }
}
