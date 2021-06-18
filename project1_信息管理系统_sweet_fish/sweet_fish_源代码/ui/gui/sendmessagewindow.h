#ifndef SENDMESSAGEWINDOW_H
#define SENDMESSAGEWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class SendMessageWindow;
}

class SendMessageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SendMessageWindow(QWidget *parent,TBSet *TBs,const table &_user_inf);
    ~SendMessageWindow();
    void clickPost();

private:
    Ui::SendMessageWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // SENDMESSAGEWINDOW_H
