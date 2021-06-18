/********************************************************************************
** Form generated from reading UI file 'removemerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEMERWINDOW_H
#define UI_REMOVEMERWINDOW_H

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

class Ui_RemoveMerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *user_mid_text;
    QLabel *label_2;
    QPushButton *postBtn;

    void setupUi(QWidget *RemoveMerWindow)
    {
        if (RemoveMerWindow->objectName().isEmpty())
            RemoveMerWindow->setObjectName(QString::fromUtf8("RemoveMerWindow"));
        RemoveMerWindow->resize(417, 192);
        RemoveMerWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(RemoveMerWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(RemoveMerWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(RemoveMerWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(14);
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        user_mid_text = new QLineEdit(RemoveMerWindow);
        user_mid_text->setObjectName(QString::fromUtf8("user_mid_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, user_mid_text);


        gridLayout->addLayout(formLayout, 2, 0, 1, 1);

        label_2 = new QLabel(RemoveMerWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        postBtn = new QPushButton(RemoveMerWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(RemoveMerWindow);

        QMetaObject::connectSlotsByName(RemoveMerWindow);
    } // setupUi

    void retranslateUi(QWidget *RemoveMerWindow)
    {
        RemoveMerWindow->setWindowTitle(QApplication::translate("RemoveMerWindow", "\347\224\234\351\261\274: \347\256\241\347\220\206\345\221\230\345\210\240\351\231\244\345\225\206\345\223\201\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("RemoveMerWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_3->setText(QApplication::translate("RemoveMerWindow", "MID:", nullptr));
        label_2->setText(QApplication::translate("RemoveMerWindow", "\347\256\241\347\220\206\345\221\230\345\210\240\351\231\244\345\225\206\345\223\201\347\225\214\351\235\242", nullptr));
        postBtn->setText(QApplication::translate("RemoveMerWindow", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoveMerWindow: public Ui_RemoveMerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEMERWINDOW_H
