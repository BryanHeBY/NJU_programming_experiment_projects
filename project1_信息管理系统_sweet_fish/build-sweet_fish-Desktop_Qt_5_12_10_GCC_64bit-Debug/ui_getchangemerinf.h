/********************************************************************************
** Form generated from reading UI file 'getchangemerinf.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCHANGEMERINF_H
#define UI_GETCHANGEMERINF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GetChangeMerInf
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *mer_mid_text;
    QPushButton *postBtn;

    void setupUi(QWidget *GetChangeMerInf)
    {
        if (GetChangeMerInf->objectName().isEmpty())
            GetChangeMerInf->setObjectName(QString::fromUtf8("GetChangeMerInf"));
        GetChangeMerInf->resize(464, 164);
        GetChangeMerInf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        horizontalLayout = new QHBoxLayout(GetChangeMerInf);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(GetChangeMerInf);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(GetChangeMerInf);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(GetChangeMerInf);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        mer_mid_text = new QLineEdit(GetChangeMerInf);
        mer_mid_text->setObjectName(QString::fromUtf8("mer_mid_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mer_mid_text);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        postBtn = new QPushButton(GetChangeMerInf);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 2, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(GetChangeMerInf);

        QMetaObject::connectSlotsByName(GetChangeMerInf);
    } // setupUi

    void retranslateUi(QWidget *GetChangeMerInf)
    {
        GetChangeMerInf->setWindowTitle(QApplication::translate("GetChangeMerInf", "\347\224\234\351\261\274: \344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("GetChangeMerInf", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("GetChangeMerInf", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("GetChangeMerInf", "\345\225\206\345\223\201MID:", nullptr));
        postBtn->setText(QApplication::translate("GetChangeMerInf", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetChangeMerInf: public Ui_GetChangeMerInf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCHANGEMERINF_H
