#ifndef POSTMERWINDOW_H
#define POSTMERWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class PostMerWindow;
}

class PostMerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PostMerWindow(QWidget *parent,TBSet *TBs,const table &user_inf);
    ~PostMerWindow();
    void clickPost();

private:
    Ui::PostMerWindow *ui;
    TBSet *pTBs;
    table user_inf;
};

#endif // POSTMERWINDOW_H
