#ifndef ADMINSEARCHUSER_H
#define ADMINSEARCHUSER_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class AdminSearchUser;
}

class AdminSearchUser : public QWidget
{
    Q_OBJECT

public:
    explicit AdminSearchUser(QWidget *paren,TBSet *TBs);
    ~AdminSearchUser();
    void clickPost();

private:
    Ui::AdminSearchUser *ui;
    TBSet *pTBs;
};

#endif // ADMINSEARCHUSER_H

