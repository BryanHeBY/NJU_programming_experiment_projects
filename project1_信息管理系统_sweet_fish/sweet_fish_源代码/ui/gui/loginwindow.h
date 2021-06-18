#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

#include "logonwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent,TBSet *TBs);
    ~LoginWindow();

    void clickLogin();
    void clickLogon();


private:
    Ui::LoginWindow *ui;
    TBSet *pTBs;
};

#endif // LOGINWINDOW_H
