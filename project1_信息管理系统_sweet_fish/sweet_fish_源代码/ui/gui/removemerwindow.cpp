#include "removemerwindow.h"
#include "ui_removemerwindow.h"
#include "../../error_solve/ErrorTB.h"
#include <QDebug>
#include <QMessageBox>

RemoveMerWindow::RemoveMerWindow(QWidget *parent,TBSet *TBs) :
    QWidget(parent),
    ui(new Ui::RemoveMerWindow),
    pTBs(TBs)
{
    ui->setupUi(this);
    connect(ui->postBtn,&QPushButton::clicked,this,&RemoveMerWindow::clickPost);
}

RemoveMerWindow::~RemoveMerWindow()
{
    delete ui;
}

void RemoveMerWindow::clickPost()
{
    QString uid=ui->user_mid_text->text();
    try {
        pTBs->Merchandises.remove_mer_by_mid(uid.toUtf8().constData());
        QMessageBox::information(this,"下架成功","下架成功！");
        this->close();
    }  catch (ErrorTB &e) {
        QMessageBox::warning(this,"删除错误",e.what());
    }
}

