#ifndef ADMINSEARCHORDERFORM_H
#define ADMINSEARCHORDERFORM_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class AdminSearchOrderForm;
}

class AdminSearchOrderForm : public QWidget
{
    Q_OBJECT

public:
    explicit AdminSearchOrderForm(QWidget *parent,TBSet *TBs);
    ~AdminSearchOrderForm();
    void clickPost();

private:
    Ui::AdminSearchOrderForm *ui;
    TBSet *pTBs;
};

#endif // ADMINSEARCHORDERFORM_H
