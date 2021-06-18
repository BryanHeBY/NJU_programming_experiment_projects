/********************************************************************************
** Form generated from reading UI file 'sendmessagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMESSAGEWINDOW_H
#define UI_SENDMESSAGEWINDOW_H

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

class Ui_SendMessageWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *receiver_uid_text;
    QLabel *label_4;
    QLineEdit *message_text;
    QPushButton *postBtn;

    void setupUi(QWidget *SendMessageWindow)
    {
        if (SendMessageWindow->objectName().isEmpty())
            SendMessageWindow->setObjectName(QString::fromUtf8("SendMessageWindow"));
        SendMessageWindow->resize(400, 207);
        SendMessageWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(SendMessageWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SendMessageWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(SendMessageWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(SendMessageWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        receiver_uid_text = new QLineEdit(SendMessageWindow);
        receiver_uid_text->setObjectName(QString::fromUtf8("receiver_uid_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, receiver_uid_text);

        label_4 = new QLabel(SendMessageWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        message_text = new QLineEdit(SendMessageWindow);
        message_text->setObjectName(QString::fromUtf8("message_text"));

        formLayout->setWidget(1, QFormLayout::FieldRole, message_text);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        postBtn = new QPushButton(SendMessageWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(SendMessageWindow);

        QMetaObject::connectSlotsByName(SendMessageWindow);
    } // setupUi

    void retranslateUi(QWidget *SendMessageWindow)
    {
        SendMessageWindow->setWindowTitle(QApplication::translate("SendMessageWindow", "\347\224\234\351\261\274: \345\217\221\351\200\201\347\225\231\350\250\200\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("SendMessageWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("SendMessageWindow", "\345\217\221\351\200\201\347\225\231\350\250\200\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("SendMessageWindow", "\346\216\245\345\217\227\350\200\205UID:", nullptr));
        label_4->setText(QApplication::translate("SendMessageWindow", "\347\225\231\350\250\200\345\206\205\345\256\271:", nullptr));
        postBtn->setText(QApplication::translate("SendMessageWindow", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendMessageWindow: public Ui_SendMessageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMESSAGEWINDOW_H
