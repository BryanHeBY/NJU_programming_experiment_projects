/********************************************************************************
** Form generated from reading UI file 'changemerinfwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEMERINFWINDOW_H
#define UI_CHANGEMERINFWINDOW_H

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

class Ui_ChangeMerInfWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLineEdit *mer_name_text;
    QLabel *label_4;
    QLineEdit *mer_price_text;
    QLabel *label_5;
    QLineEdit *mer_description_text;
    QLabel *label_6;
    QLineEdit *mer_type_set_text;
    QPushButton *postBtn;

    void setupUi(QWidget *ChangeMerInfWindow)
    {
        if (ChangeMerInfWindow->objectName().isEmpty())
            ChangeMerInfWindow->setObjectName(QString::fromUtf8("ChangeMerInfWindow"));
        ChangeMerInfWindow->resize(461, 270);
        ChangeMerInfWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(ChangeMerInfWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ChangeMerInfWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ChangeMerInfWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(ChangeMerInfWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        mer_name_text = new QLineEdit(ChangeMerInfWindow);
        mer_name_text->setObjectName(QString::fromUtf8("mer_name_text"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mer_name_text);

        label_4 = new QLabel(ChangeMerInfWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        mer_price_text = new QLineEdit(ChangeMerInfWindow);
        mer_price_text->setObjectName(QString::fromUtf8("mer_price_text"));

        formLayout->setWidget(1, QFormLayout::FieldRole, mer_price_text);

        label_5 = new QLabel(ChangeMerInfWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        mer_description_text = new QLineEdit(ChangeMerInfWindow);
        mer_description_text->setObjectName(QString::fromUtf8("mer_description_text"));

        formLayout->setWidget(2, QFormLayout::FieldRole, mer_description_text);

        label_6 = new QLabel(ChangeMerInfWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        mer_type_set_text = new QLineEdit(ChangeMerInfWindow);
        mer_type_set_text->setObjectName(QString::fromUtf8("mer_type_set_text"));

        formLayout->setWidget(3, QFormLayout::FieldRole, mer_type_set_text);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        postBtn = new QPushButton(ChangeMerInfWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 2, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ChangeMerInfWindow);

        QMetaObject::connectSlotsByName(ChangeMerInfWindow);
    } // setupUi

    void retranslateUi(QWidget *ChangeMerInfWindow)
    {
        ChangeMerInfWindow->setWindowTitle(QApplication::translate("ChangeMerInfWindow", "\347\224\234\351\261\274: \344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("ChangeMerInfWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        label_2->setText(QApplication::translate("ChangeMerInfWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257\347\225\214\351\235\242", nullptr));
        label_3->setText(QApplication::translate("ChangeMerInfWindow", "\345\225\206\345\223\201\345\220\215:", nullptr));
        label_4->setText(QApplication::translate("ChangeMerInfWindow", "\345\225\206\345\223\201\344\273\267\346\240\274:", nullptr));
        label_5->setText(QApplication::translate("ChangeMerInfWindow", "\345\225\206\345\223\201\346\217\217\350\277\260:", nullptr));
        label_6->setText(QApplication::translate("ChangeMerInfWindow", "\345\225\206\345\223\201\345\210\206\347\261\273\351\233\206:", nullptr));
        postBtn->setText(QApplication::translate("ChangeMerInfWindow", "\346\217\220\344\272\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeMerInfWindow: public Ui_ChangeMerInfWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEMERINFWINDOW_H
