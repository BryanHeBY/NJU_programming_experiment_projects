#ifndef ADMINSEARCHMESSAGE_H
#define ADMINSEARCHMESSAGE_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class AdminSearchMessage;
}

class AdminSearchMessage : public QWidget
{
    Q_OBJECT

public:
    explicit AdminSearchMessage(QWidget *parent,TBSet *TBs);
    ~AdminSearchMessage();
    void clickPost();

private:
    Ui::AdminSearchMessage *ui;
    TBSet *pTBs;
};

#endif // ADMINSEARCHMESSAGE_H
