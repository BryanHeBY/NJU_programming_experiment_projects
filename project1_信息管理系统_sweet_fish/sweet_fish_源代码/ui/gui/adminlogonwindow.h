#ifndef ADMINLOGONWINDOW_H
#define ADMINLOGONWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class AdminLogonWindow;
}

class AdminLogonWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminLogonWindow(QWidget *parent,TBSet *TBs);
    ~AdminLogonWindow();
    void clickPost();
private:
    Ui::AdminLogonWindow *ui;
    TBSet *pTBs;
};

#endif // ADMINLOGONWINDOW_H
