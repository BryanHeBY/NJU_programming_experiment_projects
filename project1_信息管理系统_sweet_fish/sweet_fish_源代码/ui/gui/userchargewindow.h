#ifndef USERCHARGEWINDOW_H
#define USERCHARGEWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class UserChargeWindow;
}

class UserChargeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserChargeWindow(QWidget *parent,TBSet *TBs,const table &user_inf);
    ~UserChargeWindow();
    void clickPost();

private:
    Ui::UserChargeWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // USERCHARGEWINDOW_H
