/********************************************************************************
** Form generated from reading UI file 'adminsearchorderform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSEARCHORDERFORM_H
#define UI_ADMINSEARCHORDERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminSearchOrderForm
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *check_buyer_uid;
    QRadioButton *check_oid;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QRadioButton *check_seller_uid;
    QLineEdit *search_content_text;
    QPushButton *postBtn;

    void setupUi(QWidget *AdminSearchOrderForm)
    {
        if (AdminSearchOrderForm->objectName().isEmpty())
            AdminSearchOrderForm->setObjectName(QString::fromUtf8("AdminSearchOrderForm"));
        AdminSearchOrderForm->resize(769, 234);
        AdminSearchOrderForm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        gridLayoutWidget = new QWidget(AdminSearchOrderForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 747, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        check_buyer_uid = new QRadioButton(gridLayoutWidget);
        check_buyer_uid->setObjectName(QString::fromUtf8("check_buyer_uid"));
        check_buyer_uid->setChecked(false);

        gridLayout->addWidget(check_buyer_uid, 2, 2, 1, 1);

        check_oid = new QRadioButton(gridLayoutWidget);
        check_oid->setObjectName(QString::fromUtf8("check_oid"));
        check_oid->setChecked(true);

        gridLayout->addWidget(check_oid, 2, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 1, 1, 2);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        check_seller_uid = new QRadioButton(gridLayoutWidget);
        check_seller_uid->setObjectName(QString::fromUtf8("check_seller_uid"));
        check_seller_uid->setChecked(false);

        gridLayout->addWidget(check_seller_uid, 2, 3, 1, 1);

        search_content_text = new QLineEdit(gridLayoutWidget);
        search_content_text->setObjectName(QString::fromUtf8("search_content_text"));

        gridLayout->addWidget(search_content_text, 3, 1, 1, 3);

        postBtn = new QPushButton(gridLayoutWidget);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 4, 1, 1, 2);


        retranslateUi(AdminSearchOrderForm);

        QMetaObject::connectSlotsByName(AdminSearchOrderForm);
    } // setupUi

    void retranslateUi(QWidget *AdminSearchOrderForm)
    {
        AdminSearchOrderForm->setWindowTitle(QApplication::translate("AdminSearchOrderForm", "\347\224\234\351\261\274: \347\256\241\347\220\206\345\221\230\346\220\234\347\264\242\350\256\242\345\215\225\347\225\214\351\235\242", nullptr));
        check_buyer_uid->setText(QApplication::translate("AdminSearchOrderForm", "\344\271\260\345\256\266UID", nullptr));
        check_oid->setText(QApplication::translate("AdminSearchOrderForm", "OID", nullptr));
        label_3->setText(QApplication::translate("AdminSearchOrderForm", "\346\220\234\347\264\242\345\206\205\345\256\271:", nullptr));
        label->setText(QApplication::translate("AdminSearchOrderForm", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_4->setText(QApplication::translate("AdminSearchOrderForm", "\346\220\234\347\264\242\345\205\263\351\224\256\345\255\227:", nullptr));
        label_2->setText(QApplication::translate("AdminSearchOrderForm", "\347\256\241\347\220\206\345\221\230\346\220\234\347\264\242\350\256\242\345\215\225\347\225\214\351\235\242", nullptr));
        check_seller_uid->setText(QApplication::translate("AdminSearchOrderForm", "\345\215\226\345\256\266UID", nullptr));
        postBtn->setText(QApplication::translate("AdminSearchOrderForm", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSearchOrderForm: public Ui_AdminSearchOrderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSEARCHORDERFORM_H
