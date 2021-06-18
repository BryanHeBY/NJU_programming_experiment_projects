/********************************************************************************
** Form generated from reading UI file 'userremovemerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERREMOVEMERWINDOW_H
#define UI_USERREMOVEMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserRemoveMerWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *mer_mid_text;
    QPushButton *postBtn;

    void setupUi(QWidget *UserRemoveMerWindow)
    {
        if (UserRemoveMerWindow->objectName().isEmpty())
            UserRemoveMerWindow->setObjectName(QString::fromUtf8("UserRemoveMerWindow"));
        UserRemoveMerWindow->resize(467, 183);
        UserRemoveMerWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        gridLayoutWidget = new QWidget(UserRemoveMerWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 441, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        mer_mid_text = new QLineEdit(gridLayoutWidget);
        mer_mid_text->setObjectName(QString::fromUtf8("mer_mid_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mer_mid_text);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        postBtn = new QPushButton(gridLayoutWidget);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 2, 0, 1, 2);


        retranslateUi(UserRemoveMerWindow);

        QMetaObject::connectSlotsByName(UserRemoveMerWindow);
    } // setupUi

    void retranslateUi(QWidget *UserRemoveMerWindow)
    {
        UserRemoveMerWindow->setWindowTitle(QApplication::translate("UserRemoveMerWindow", "\347\224\234\351\261\274: \344\270\213\346\236\266\345\225\206\345\223\201\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("UserRemoveMerWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("UserRemoveMerWindow", "\344\270\213\346\236\266\345\225\206\345\223\201\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("UserRemoveMerWindow", "\345\225\206\345\223\201MID:", nullptr));
        postBtn->setText(QApplication::translate("UserRemoveMerWindow", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserRemoveMerWindow: public Ui_UserRemoveMerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERREMOVEMERWINDOW_H
