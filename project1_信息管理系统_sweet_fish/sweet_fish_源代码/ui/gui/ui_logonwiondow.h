#ifndef UI_LOGONWIONDOW_H
#define UI_LOGONWIONDOW_H

#include <QWidget>

namespace Ui {
class ui_LogonWiondow;
}

class ui_LogonWiondow : public QWidget
{
    Q_OBJECT

public:
    explicit ui_LogonWiondow(QWidget *parent = nullptr);
    ~ui_LogonWiondow();

private:
    Ui::ui_LogonWiondow *ui;
};

#endif // UI_LOGONWIONDOW_H
