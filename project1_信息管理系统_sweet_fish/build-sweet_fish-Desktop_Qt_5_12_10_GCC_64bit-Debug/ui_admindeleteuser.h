/********************************************************************************
** Form generated from reading UI file 'admindeleteuser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDELETEUSER_H
#define UI_ADMINDELETEUSER_H

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

class Ui_AdminDeleteUser
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *user_uid_text;
    QLabel *label_2;
    QPushButton *postBtn;

    void setupUi(QWidget *AdminDeleteUser)
    {
        if (AdminDeleteUser->objectName().isEmpty())
            AdminDeleteUser->setObjectName(QString::fromUtf8("AdminDeleteUser"));
        AdminDeleteUser->resize(465, 165);
        AdminDeleteUser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(AdminDeleteUser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(AdminDeleteUser);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(AdminDeleteUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(14);
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        user_uid_text = new QLineEdit(AdminDeleteUser);
        user_uid_text->setObjectName(QString::fromUtf8("user_uid_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, user_uid_text);


        gridLayout->addLayout(formLayout, 2, 0, 1, 1);

        label_2 = new QLabel(AdminDeleteUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        postBtn = new QPushButton(AdminDeleteUser);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(AdminDeleteUser);

        QMetaObject::connectSlotsByName(AdminDeleteUser);
    } // setupUi

    void retranslateUi(QWidget *AdminDeleteUser)
    {
        AdminDeleteUser->setWindowTitle(QApplication::translate("AdminDeleteUser", "\347\224\234\351\261\274: \347\256\241\347\220\206\345\221\230\345\210\240\351\231\244\347\224\250\346\210\267\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("AdminDeleteUser", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_3->setText(QApplication::translate("AdminDeleteUser", "UID:", nullptr));
        label_2->setText(QApplication::translate("AdminDeleteUser", "\347\256\241\347\220\206\345\221\230\345\210\240\351\231\244\347\224\250\346\210\267\347\225\214\351\235\242", nullptr));
        postBtn->setText(QApplication::translate("AdminDeleteUser", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminDeleteUser: public Ui_AdminDeleteUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDELETEUSER_H
