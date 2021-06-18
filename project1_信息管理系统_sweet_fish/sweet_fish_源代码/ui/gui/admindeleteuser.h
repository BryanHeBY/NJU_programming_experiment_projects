#ifndef ADMINDELETEUSER_H
#define ADMINDELETEUSER_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class AdminDeleteUser;
}

class AdminDeleteUser : public QWidget
{
    Q_OBJECT

public:
    explicit AdminDeleteUser(QWidget *parent,TBSet *TBs);
    ~AdminDeleteUser();
    void clickPost();

private:
    Ui::AdminDeleteUser *ui;
    TBSet *pTBs;
};

#endif // ADMINDELETEUSER_H
