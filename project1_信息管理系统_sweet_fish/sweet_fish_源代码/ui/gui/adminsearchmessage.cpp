#include "adminsearchmessage.h"
#include "ui_adminsearchmessage.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>
#include <QTableView>

AdminSearchMessage::AdminSearchMessage(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::AdminSearchMessage),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&AdminSearchMessage::clickPost);
}

AdminSearchMessage::~AdminSearchMessage()
{
    delete ui;
}

void AdminSearchMessage::clickPost()
{
    try {
        QString search_content=ui->search_content_text->text();
        table res;
        if(ui->check_lid->isChecked()){
            res=pTBs->Messages.get_full_table().select(0,{1,messages_table::len_lid,search_content.toUtf8().constData()},db_type_equal);
        }else if(ui->check_sender_uid->isChecked()){
            res=pTBs->Messages.get_full_table().select(1,{1,messages_table::len_sender_uid,search_content.toUtf8().constData()},db_type_equal);
        }
        else if(ui->check_receiver_uid->isChecked()){
            res=pTBs->Messages.get_full_table().select(2,{1,messages_table::len_receiver_uid,search_content.toUtf8().constData()},db_type_equal);
        }
        QTableView *qTableView=new QTableView();
        qTableView->resize(800,400);
        res.show_in_gui(qTableView);
        qTableView->show();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"搜索错误",e.what());
    }
}
