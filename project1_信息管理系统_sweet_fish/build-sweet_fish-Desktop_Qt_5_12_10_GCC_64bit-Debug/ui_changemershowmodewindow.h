/********************************************************************************
** Form generated from reading UI file 'changemershowmodewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEMERSHOWMODEWINDOW_H
#define UI_CHANGEMERSHOWMODEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeMerShowModeWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *check_lesser;
    QRadioButton *check_more;
    QLabel *label_2;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *check_mid;
    QRadioButton *check_name;
    QRadioButton *check_price;
    QRadioButton *check_on_sale_time;
    QRadioButton *check_seller_uid;
    QPushButton *postBtn;
    QLabel *label_5;
    QLabel *label_6;
    QCheckBox *check_remore_invalid_mer;

    void setupUi(QWidget *ChangeMerShowModeWindow)
    {
        if (ChangeMerShowModeWindow->objectName().isEmpty())
            ChangeMerShowModeWindow->setObjectName(QString::fromUtf8("ChangeMerShowModeWindow"));
        ChangeMerShowModeWindow->resize(772, 306);
        ChangeMerShowModeWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(ChangeMerShowModeWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(ChangeMerShowModeWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        groupBox_2 = new QGroupBox(ChangeMerShowModeWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayoutWidget_2 = new QWidget(groupBox_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 491, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        check_lesser = new QRadioButton(horizontalLayoutWidget_2);
        check_lesser->setObjectName(QString::fromUtf8("check_lesser"));
        check_lesser->setChecked(true);

        horizontalLayout_3->addWidget(check_lesser);

        check_more = new QRadioButton(horizontalLayoutWidget_2);
        check_more->setObjectName(QString::fromUtf8("check_more"));
        check_more->setChecked(false);

        horizontalLayout_3->addWidget(check_more);


        gridLayout->addWidget(groupBox_2, 3, 1, 1, 2);

        label_2 = new QLabel(ChangeMerShowModeWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 1, 1, 2);

        label = new QLabel(ChangeMerShowModeWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 1, 1, 2);

        groupBox = new QGroupBox(ChangeMerShowModeWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 491, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        check_mid = new QRadioButton(horizontalLayoutWidget);
        check_mid->setObjectName(QString::fromUtf8("check_mid"));
        check_mid->setChecked(true);

        horizontalLayout->addWidget(check_mid);

        check_name = new QRadioButton(horizontalLayoutWidget);
        check_name->setObjectName(QString::fromUtf8("check_name"));
        check_name->setChecked(false);

        horizontalLayout->addWidget(check_name);

        check_price = new QRadioButton(horizontalLayoutWidget);
        check_price->setObjectName(QString::fromUtf8("check_price"));
        check_price->setChecked(false);

        horizontalLayout->addWidget(check_price);

        check_on_sale_time = new QRadioButton(horizontalLayoutWidget);
        check_on_sale_time->setObjectName(QString::fromUtf8("check_on_sale_time"));
        check_on_sale_time->setChecked(false);

        horizontalLayout->addWidget(check_on_sale_time);

        check_seller_uid = new QRadioButton(horizontalLayoutWidget);
        check_seller_uid->setObjectName(QString::fromUtf8("check_seller_uid"));
        check_seller_uid->setChecked(false);

        horizontalLayout->addWidget(check_seller_uid);


        gridLayout->addWidget(groupBox, 2, 1, 1, 2);

        postBtn = new QPushButton(ChangeMerShowModeWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 5, 1, 1, 1);

        label_5 = new QLabel(ChangeMerShowModeWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(ChangeMerShowModeWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        check_remore_invalid_mer = new QCheckBox(ChangeMerShowModeWindow);
        check_remore_invalid_mer->setObjectName(QString::fromUtf8("check_remore_invalid_mer"));

        gridLayout->addWidget(check_remore_invalid_mer, 4, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ChangeMerShowModeWindow);

        QMetaObject::connectSlotsByName(ChangeMerShowModeWindow);
    } // setupUi

    void retranslateUi(QWidget *ChangeMerShowModeWindow)
    {
        ChangeMerShowModeWindow->setWindowTitle(QApplication::translate("ChangeMerShowModeWindow", "\347\224\234\351\261\274: \344\277\256\346\224\271\345\225\206\345\223\201\346\237\245\347\234\213\346\235\241\344\273\266\347\225\214\351\235\242", nullptr));
        label_4->setText(QApplication::translate("ChangeMerShowModeWindow", "\346\216\222\345\272\217\345\205\263\351\224\256\345\255\227:", nullptr));
        groupBox_2->setTitle(QString());
        check_lesser->setText(QApplication::translate("ChangeMerShowModeWindow", "\351\241\272\345\272\217", nullptr));
        check_more->setText(QApplication::translate("ChangeMerShowModeWindow", "\345\200\222\345\272\217", nullptr));
        label_2->setText(QApplication::translate("ChangeMerShowModeWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\346\237\245\347\234\213\346\235\241\344\273\266\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("ChangeMerShowModeWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        groupBox->setTitle(QString());
        check_mid->setText(QApplication::translate("ChangeMerShowModeWindow", "MID", nullptr));
        check_name->setText(QApplication::translate("ChangeMerShowModeWindow", "\345\225\206\345\223\201\345\220\215", nullptr));
        check_price->setText(QApplication::translate("ChangeMerShowModeWindow", "\344\273\267\346\240\274", nullptr));
        check_on_sale_time->setText(QApplication::translate("ChangeMerShowModeWindow", "\344\270\212\346\236\266\346\227\266\351\227\264", nullptr));
        check_seller_uid->setText(QApplication::translate("ChangeMerShowModeWindow", "\345\215\226\345\256\266UID", nullptr));
        postBtn->setText(QApplication::translate("ChangeMerShowModeWindow", "\346\237\245\347\234\213", nullptr));
        label_5->setText(QApplication::translate("ChangeMerShowModeWindow", "\346\216\222\345\272\217\351\241\272\345\272\217:", nullptr));
        label_6->setText(QApplication::translate("ChangeMerShowModeWindow", "\346\230\257\345\220\246\346\216\222\351\231\244\344\270\213\346\236\266\345\224\256\345\207\272\345\225\206\345\223\201:", nullptr));
        check_remore_invalid_mer->setText(QApplication::translate("ChangeMerShowModeWindow", "\346\216\222\351\231\244\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeMerShowModeWindow: public Ui_ChangeMerShowModeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEMERSHOWMODEWINDOW_H
