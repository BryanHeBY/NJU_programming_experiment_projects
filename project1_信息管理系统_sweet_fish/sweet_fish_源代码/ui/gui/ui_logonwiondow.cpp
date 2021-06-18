include "ui_logonwiondow.h"
#include "ui_ui_logonwiondow.h"

ui_LogonWiondow::ui_LogonWiondow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ui_LogonWiondow)
{
    ui->setupUi(this);
}

ui_LogonWiondow::~ui_LogonWiondow()
{
    delete ui;
}
