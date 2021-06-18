#ifndef REMOVEMERWINDOW_H
#define REMOVEMERWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class RemoveMerWindow;
}

class RemoveMerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveMerWindow(QWidget *parent,TBSet *TBs);
    ~RemoveMerWindow();
    void clickPost();

private:
    Ui::RemoveMerWindow *ui;
    TBSet *pTBs;
};

#endif // REMOVEMERWINDOW_H
