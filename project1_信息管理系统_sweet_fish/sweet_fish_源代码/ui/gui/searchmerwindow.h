#ifndef SEARCHMERWINDOW_H
#define SEARCHMERWINDOW_H

#include <QWidget>
#include "../../tables/tbset.h"

namespace Ui {
class SearchMerWindow;
}

class SearchMerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchMerWindow(QWidget *parent,TBSet *TBs);
    ~SearchMerWindow();
    void clickPost();

private:
    Ui::SearchMerWindow *ui;
    TBSet *pTBs;
};

#endif // SEARCHMERWINDOW_H
