#include "admindeleteuser.h"
#include "ui_admindeleteuser.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

AdminDeleteUser::AdminDeleteUser(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::AdminDeleteUser),
  pTBs(TBs)
{
  ui->setupUi(this);
  connect(ui->postBtn,&QPushButton::clicked,this,&AdminDeleteUser::clickPost);
}


AdminDeleteUser::~AdminDeleteUser()
{
    delete ui;
}

void AdminDeleteUser::clickPost()
{
    QString uid=ui->user_uid_text->text();
    try {
        pTBs->Users.delete_user_by_uid(uid.toUtf8().constData());
        QMessageBox::information(this,"删除成功","删除成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"删除错误",e.what());
    }
}

