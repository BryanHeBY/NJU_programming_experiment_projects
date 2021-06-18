/********************************************************************************
** Form generated from reading UI file 'adminsearchuser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSEARCHUSER_H
#define UI_ADMINSEARCHUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminSearchUser
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QRadioButton *check_uid;
    QLabel *label_3;
    QRadioButton *check_name;
    QLabel *label;
    QLabel *label_2;
    QPushButton *postBtn;
    QLineEdit *search_content_text;

    void setupUi(QWidget *AdminSearchUser)
    {
        if (AdminSearchUser->objectName().isEmpty())
            AdminSearchUser->setObjectName(QString::fromUtf8("AdminSearchUser"));
        AdminSearchUser->resize(783, 246);
        AdminSearchUser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(AdminSearchUser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(AdminSearchUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        check_uid = new QRadioButton(AdminSearchUser);
        check_uid->setObjectName(QString::fromUtf8("check_uid"));
        check_uid->setChecked(true);

        gridLayout->addWidget(check_uid, 2, 1, 1, 1);

        label_3 = new QLabel(AdminSearchUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        check_name = new QRadioButton(AdminSearchUser);
        check_name->setObjectName(QString::fromUtf8("check_name"));
        check_name->setChecked(false);

        gridLayout->addWidget(check_name, 2, 2, 1, 1);

        label = new QLabel(AdminSearchUser);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 1, 1, 2);

        label_2 = new QLabel(AdminSearchUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        postBtn = new QPushButton(AdminSearchUser);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 4, 1, 1, 1);

        search_content_text = new QLineEdit(AdminSearchUser);
        search_content_text->setObjectName(QString::fromUtf8("search_content_text"));

        gridLayout->addWidget(search_content_text, 3, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(AdminSearchUser);

        QMetaObject::connectSlotsByName(AdminSearchUser);
    } // setupUi

    void retranslateUi(QWidget *AdminSearchUser)
    {
        AdminSearchUser->setWindowTitle(QApplication::translate("AdminSearchUser", "\347\224\234\351\261\274: \347\256\241\347\220\206\345\221\230\346\220\234\347\264\242\347\224\250\346\210\267\347\225\214\351\235\242", nullptr));
        label_4->setText(QApplication::translate("AdminSearchUser", "\346\220\234\347\264\242\345\205\263\351\224\256\345\255\227:", nullptr));
        check_uid->setText(QApplication::translate("AdminSearchUser", "UID", nullptr));
        label_3->setText(QApplication::translate("AdminSearchUser", "\346\220\234\347\264\242\345\206\205\345\256\271:", nullptr));
        check_name->setText(QApplication::translate("AdminSearchUser", "\347\224\250\346\210\267\345\220\215", nullptr));
        label->setText(QApplication::translate("AdminSearchUser", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("AdminSearchUser", "\347\256\241\347\220\206\345\221\230\346\220\234\347\264\242\347\224\250\346\210\267\347\225\214\351\235\242", nullptr));
        postBtn->setText(QApplication::translate("AdminSearchUser", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSearchUser: public Ui_AdminSearchUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSEARCHUSER_H
