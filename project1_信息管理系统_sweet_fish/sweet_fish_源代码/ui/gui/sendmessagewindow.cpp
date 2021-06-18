#include "sendmessagewindow.h"
#include "ui_sendmessagewindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

SendMessageWindow::SendMessageWindow(QWidget *parent,TBSet *TBs,const table &_user_inf) :
    QWidget(parent),
    ui(new Ui::SendMessageWindow),
    pTBs(TBs),
    user_inf(_user_inf)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&SendMessageWindow::clickPost);
}

SendMessageWindow::~SendMessageWindow()
{
    delete ui;
}

void SendMessageWindow::clickPost()
{
    QString receiver_uid=ui->receiver_uid_text->text(),message=ui->message_text->text();
    try {
        pTBs->Messages.send_message(pTBs->Users,user_inf,receiver_uid.toUtf8().constData(),message.toUtf8().constData());
        QMessageBox::information(this,"发送成功","发送成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"注册错误",e.what());
    }
}
