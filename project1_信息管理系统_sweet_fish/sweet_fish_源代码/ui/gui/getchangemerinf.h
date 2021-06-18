#ifndef GETCHANGEMERINF_H
#define GETCHANGEMERINF_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class GetChangeMerInf;
}

class GetChangeMerInf : public QWidget
{
    Q_OBJECT

public:
    explicit GetChangeMerInf(QWidget *parent,TBSet *TBs,const table &_user_inf);
    ~GetChangeMerInf();
    void clickPost();

private:
    Ui::GetChangeMerInf *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // GETCHANGEMERINF_H
