#ifndef LOGONWINDOW_H
#define LOGONWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class LogonWindow;
}

class LogonWindow : public QWidget
{
    Q_OBJECT

public:

    explicit LogonWindow(QWidget *parent,TBSet *TBs);
    ~LogonWindow();

    void clickPost();
private:
    Ui::LogonWindow *ui;
    TBSet *pTBs;
};

#endif // LOGONWINDOW_H
