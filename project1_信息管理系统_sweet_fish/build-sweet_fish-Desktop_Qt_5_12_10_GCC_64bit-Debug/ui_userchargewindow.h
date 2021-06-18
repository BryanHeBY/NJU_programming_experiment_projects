/********************************************************************************
** Form generated from reading UI file 'userchargewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERCHARGEWINDOW_H
#define UI_USERCHARGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserChargeWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *charge_code_text;
    QLabel *label_4;
    QLineEdit *money_text;
    QPushButton *postBtn;

    void setupUi(QWidget *UserChargeWindow)
    {
        if (UserChargeWindow->objectName().isEmpty())
            UserChargeWindow->setObjectName(QString::fromUtf8("UserChargeWindow"));
        UserChargeWindow->resize(401, 205);
        UserChargeWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"	padding: 4px;\n"
"	margin: 4px; \n"
"    background-color: rgb(54, 125, 221);\n"
"    color: white;\n"
"}\n"
"QLineEdit{\n"
"	border: 1px solid black;\n"
"	border-radius: 4px;\n"
"	padding: 4px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(UserChargeWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(UserChargeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(UserChargeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(UserChargeWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        charge_code_text = new QLineEdit(UserChargeWindow);
        charge_code_text->setObjectName(QString::fromUtf8("charge_code_text"));
        charge_code_text->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, charge_code_text);

        label_4 = new QLabel(UserChargeWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        money_text = new QLineEdit(UserChargeWindow);
        money_text->setObjectName(QString::fromUtf8("money_text"));

        formLayout->setWidget(1, QFormLayout::FieldRole, money_text);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        postBtn = new QPushButton(UserChargeWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(UserChargeWindow);

        QMetaObject::connectSlotsByName(UserChargeWindow);
    } // setupUi

    void retranslateUi(QWidget *UserChargeWindow)
    {
        UserChargeWindow->setWindowTitle(QApplication::translate("UserChargeWindow", "\347\224\234\351\261\274: \347\224\250\346\210\267\345\205\205\345\200\274\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("UserChargeWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("UserChargeWindow", "\347\224\250\346\210\267\345\205\205\345\200\274\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("UserChargeWindow", "\345\205\205\345\200\274\347\240\201:", nullptr));
        label_4->setText(QApplication::translate("UserChargeWindow", "\345\205\205\345\200\274\351\207\221\351\242\235:", nullptr));
        postBtn->setText(QApplication::translate("UserChargeWindow", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserChargeWindow: public Ui_UserChargeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERCHARGEWINDOW_H
