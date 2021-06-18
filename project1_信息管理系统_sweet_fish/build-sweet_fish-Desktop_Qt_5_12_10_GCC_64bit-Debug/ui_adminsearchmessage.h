/********************************************************************************
** Form generated from reading UI file 'adminsearchmessage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSEARCHMESSAGE_H
#define UI_ADMINSEARCHMESSAGE_H

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

class Ui_AdminSearchMessage
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QRadioButton *check_lid;
    QRadioButton *check_sender_uid;
    QLabel *label;
    QRadioButton *check_receiver_uid;
    QLineEdit *search_content_text;
    QPushButton *postBtn;

    void setupUi(QWidget *AdminSearchMessage)
    {
        if (AdminSearchMessage->objectName().isEmpty())
            AdminSearchMessage->setObjectName(QString::fromUtf8("AdminSearchMessage"));
        AdminSearchMessage->resize(777, 238);
        AdminSearchMessage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(AdminSearchMessage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(AdminSearchMessage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(AdminSearchMessage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(AdminSearchMessage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        check_lid = new QRadioButton(AdminSearchMessage);
        check_lid->setObjectName(QString::fromUtf8("check_lid"));
        check_lid->setChecked(true);

        gridLayout->addWidget(check_lid, 2, 1, 1, 1);

        check_sender_uid = new QRadioButton(AdminSearchMessage);
        check_sender_uid->setObjectName(QString::fromUtf8("check_sender_uid"));
        check_sender_uid->setChecked(false);

        gridLayout->addWidget(check_sender_uid, 2, 2, 1, 1);

        label = new QLabel(AdminSearchMessage);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 1, 1, 2);

        check_receiver_uid = new QRadioButton(AdminSearchMessage);
        check_receiver_uid->setObjectName(QString::fromUtf8("check_receiver_uid"));
        check_receiver_uid->setChecked(false);

        gridLayout->addWidget(check_receiver_uid, 2, 3, 1, 1);

        search_content_text = new QLineEdit(AdminSearchMessage);
        search_content_text->setObjectName(QString::fromUtf8("search_content_text"));

        gridLayout->addWidget(search_content_text, 3, 1, 1, 3);

        postBtn = new QPushButton(AdminSearchMessage);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 4, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(AdminSearchMessage);

        QMetaObject::connectSlotsByName(AdminSearchMessage);
    } // setupUi

    void retranslateUi(QWidget *AdminSearchMessage)
    {
        AdminSearchMessage->setWindowTitle(QApplication::translate("AdminSearchMessage", "\347\224\234\351\261\274: \347\256\241\347\220\206\345\221\230\346\220\234\347\264\242\347\225\231\350\250\200\347\225\214\351\235\242", nullptr));
        label_4->setText(QApplication::translate("AdminSearchMessage", "\346\220\234\347\264\242\345\205\263\351\224\256\345\255\227:", nullptr));
        label_3->setText(QApplication::translate("AdminSearchMessage", "\346\220\234\347\264\242\345\206\205\345\256\271:", nullptr));
        label_2->setText(QApplication::translate("AdminSearchMessage", "\347\256\241\347\220\206\345\221\230\346\220\234\347\264\242\347\225\231\350\250\200\347\225\214\351\235\242", nullptr));
        check_lid->setText(QApplication::translate("AdminSearchMessage", "LID", nullptr));
        check_sender_uid->setText(QApplication::translate("AdminSearchMessage", "\345\217\221\351\200\201\350\200\205UID", nullptr));
        label->setText(QApplication::translate("AdminSearchMessage", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        check_receiver_uid->setText(QApplication::translate("AdminSearchMessage", "\346\216\245\345\217\227\350\200\205UID", nullptr));
        postBtn->setText(QApplication::translate("AdminSearchMessage", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSearchMessage: public Ui_AdminSearchMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSEARCHMESSAGE_H
