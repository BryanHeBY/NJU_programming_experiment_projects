#ifndef USERCHANGEINFWINDOW_H
#define USERCHANGEINFWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class UserChangeInfWindow;
}

class UserChangeInfWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserChangeInfWindow(QWidget *parent,TBSet *TBs,const table &_user_inf);
    ~UserChangeInfWindow();
    void clickPost();

private:
    Ui::UserChangeInfWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // USERCHANGEINFWINDOW_H
