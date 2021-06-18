/********************************************************************************
** Form generated from reading UI file 'logonwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGONWINDOW_H
#define UI_LOGONWINDOW_H

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

class Ui_LogonWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *user_name_text;
    QLabel *label_4;
    QLineEdit *user_pwd_text;
    QLabel *label_5;
    QLineEdit *user_contact_text;
    QLabel *label_6;
    QLineEdit *user_home_text;
    QPushButton *postBtn;

    void setupUi(QWidget *LogonWindow)
    {
        if (LogonWindow->objectName().isEmpty())
            LogonWindow->setObjectName(QString::fromUtf8("LogonWindow"));
        LogonWindow->resize(400, 274);
        LogonWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(LogonWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(LogonWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(LogonWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(LogonWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        user_name_text = new QLineEdit(LogonWindow);
        user_name_text->setObjectName(QString::fromUtf8("user_name_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, user_name_text);

        label_4 = new QLabel(LogonWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        user_pwd_text = new QLineEdit(LogonWindow);
        user_pwd_text->setObjectName(QString::fromUtf8("user_pwd_text"));

        formLayout->setWidget(1, QFormLayout::FieldRole, user_pwd_text);

        label_5 = new QLabel(LogonWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        user_contact_text = new QLineEdit(LogonWindow);
        user_contact_text->setObjectName(QString::fromUtf8("user_contact_text"));

        formLayout->setWidget(2, QFormLayout::FieldRole, user_contact_text);

        label_6 = new QLabel(LogonWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        user_home_text = new QLineEdit(LogonWindow);
        user_home_text->setObjectName(QString::fromUtf8("user_home_text"));

        formLayout->setWidget(3, QFormLayout::FieldRole, user_home_text);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        postBtn = new QPushButton(LogonWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(LogonWindow);

        QMetaObject::connectSlotsByName(LogonWindow);
    } // setupUi

    void retranslateUi(QWidget *LogonWindow)
    {
        LogonWindow->setWindowTitle(QApplication::translate("LogonWindow", "\347\224\234\351\261\274: \346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("LogonWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("LogonWindow", "\346\263\250\345\206\214\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("LogonWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_4->setText(QApplication::translate("LogonWindow", "\345\257\206    \347\240\201:", nullptr));
        label_5->setText(QApplication::translate("LogonWindow", "\350\201\224\347\263\273\346\226\271\345\274\217:", nullptr));
        label_6->setText(QApplication::translate("LogonWindow", "\345\234\260    \345\235\200:", nullptr));
        postBtn->setText(QApplication::translate("LogonWindow", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogonWindow: public Ui_LogonWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGONWINDOW_H
