#ifndef BUYMERWINDOW_H
#define BUYMERWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class BuyMerWindow;
}

class BuyMerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BuyMerWindow(QWidget *parent,TBSet *TBs,const table &_user_inf);
    ~BuyMerWindow();
    void clickPost();

private:
    Ui::BuyMerWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // BUYMERWINDOW_H
