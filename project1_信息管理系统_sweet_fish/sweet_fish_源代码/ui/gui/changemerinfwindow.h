#ifndef CHANGEMERINFWINDOW_H
#define CHANGEMERINFWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class ChangeMerInfWindow;
}

class ChangeMerInfWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeMerInfWindow(QWidget *parent,TBSet *TBs,const table &_user_inf,const QString &mid);
    ~ChangeMerInfWindow();
    void clickPost();

private:
    Ui::ChangeMerInfWindow *ui;
    TBSet *pTBs;
    table user_inf;
    QString mid;
};

#endif // CHANGEMERINFWINDOW_H
