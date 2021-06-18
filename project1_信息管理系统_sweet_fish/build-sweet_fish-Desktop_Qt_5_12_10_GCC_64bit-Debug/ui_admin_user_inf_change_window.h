/********************************************************************************
** Form generated from reading UI file 'admin_user_inf_change_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_USER_INF_CHANGE_WINDOW_H
#define UI_ADMIN_USER_INF_CHANGE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin_user_inf_change
{
public:
    QLabel *label_2;
    QLabel *label;
    QPushButton *postBtn;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *user_pwd_text;
    QLabel *label_5;
    QLineEdit *user_contact_text;
    QLabel *label_6;
    QLineEdit *user_home_text;
    QLabel *label_7;

    void setupUi(QWidget *admin_user_inf_change)
    {
        if (admin_user_inf_change->objectName().isEmpty())
            admin_user_inf_change->setObjectName(QString::fromUtf8("admin_user_inf_change"));
        admin_user_inf_change->resize(400, 300);
        admin_user_inf_change->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"    background-color: rgb(54, 125, 221);\n"
"    color: white;\n"
"}\n"
"QLineEdit{\n"
"	border: 1px solid black;\n"
"	border-radius: 4px;\n"
"	padding: 4px;\n"
"}\n"
""));
        label_2 = new QLabel(admin_user_inf_change);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 50, 181, 31));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        label = new QLabel(admin_user_inf_change);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 10, 241, 31));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        postBtn = new QPushButton(admin_user_inf_change);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));
        postBtn->setGeometry(QRect(150, 250, 89, 25));
        formLayoutWidget = new QWidget(admin_user_inf_change);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 90, 311, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        user_pwd_text = new QLineEdit(formLayoutWidget);
        user_pwd_text->setObjectName(QString::fromUtf8("user_pwd_text"));

        formLayout->setWidget(1, QFormLayout::FieldRole, user_pwd_text);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        user_contact_text = new QLineEdit(formLayoutWidget);
        user_contact_text->setObjectName(QString::fromUtf8("user_contact_text"));

        formLayout->setWidget(2, QFormLayout::FieldRole, user_contact_text);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        user_home_text = new QLineEdit(formLayoutWidget);
        user_home_text->setObjectName(QString::fromUtf8("user_home_text"));

        formLayout->setWidget(3, QFormLayout::FieldRole, user_home_text);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_7);


        retranslateUi(admin_user_inf_change);

        QMetaObject::connectSlotsByName(admin_user_inf_change);
    } // setupUi

    void retranslateUi(QWidget *admin_user_inf_change)
    {
        admin_user_inf_change->setWindowTitle(QApplication::translate("admin_user_inf_change", "Form", nullptr));
        label_2->setText(QApplication::translate("admin_user_inf_change", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257\344\277\256\346\224\271\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("admin_user_inf_change", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        postBtn->setText(QApplication::translate("admin_user_inf_change", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("admin_user_inf_change", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_4->setText(QApplication::translate("admin_user_inf_change", "\345\257\206    \347\240\201:", nullptr));
        label_5->setText(QApplication::translate("admin_user_inf_change", "\350\201\224\347\263\273\346\226\271\345\274\217:", nullptr));
        label_6->setText(QApplication::translate("admin_user_inf_change", "\345\234\260    \345\235\200:", nullptr));
        label_7->setText(QApplication::translate("admin_user_inf_change", "admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_user_inf_change: public Ui_admin_user_inf_change {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_USER_INF_CHANGE_WINDOW_H
