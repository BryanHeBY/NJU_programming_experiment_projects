#ifndef ADMINUSERINFCHANGE_H
#define ADMINUSERINFCHANGE_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class AdminUserInfChange;
}

class AdminUserInfChange : public QWidget
{
    Q_OBJECT

public:
    explicit AdminUserInfChange(QWidget *parent,TBSet *TBs);
    ~AdminUserInfChange();
    void clickPost();

private:
    Ui::AdminUserInfChange *ui;
    TBSet *pTBs;
    table _user_inf;
};

#endif // ADMINUSERINFCHANGE_H
