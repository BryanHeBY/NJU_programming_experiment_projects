#ifndef CHANGEMERSHOWMODEWINDOW_H
#define CHANGEMERSHOWMODEWINDOW_H

#include <QWidget>
#include <QTableView>
#include "../../tables/tbset.h"

namespace Ui {
class ChangeMerShowModeWindow;
}

class ChangeMerShowModeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeMerShowModeWindow(QWidget *parent,TBSet *pTBs,QTableView *tableview);
    ~ChangeMerShowModeWindow();
    void clickPost();

private:
    Ui::ChangeMerShowModeWindow *ui;
    TBSet *pTBs;
    QTableView *pTableView;
};

#endif // CHANGEMERSHOWMODEWINDOW_H
