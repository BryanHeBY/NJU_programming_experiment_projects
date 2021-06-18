#ifndef USERREMOVEMERWINDOW_H
#define USERREMOVEMERWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class UserRemoveMerWindow;
}

class UserRemoveMerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserRemoveMerWindow(QWidget *parent,TBSet *TBs,const table &_user_inf);
    ~UserRemoveMerWindow();
    void clickPost();

private:
    Ui::UserRemoveMerWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // USERREMOVEMERWINDOW_H
