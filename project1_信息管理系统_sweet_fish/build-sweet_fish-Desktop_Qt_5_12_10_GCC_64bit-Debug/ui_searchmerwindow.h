/********************************************************************************
** Form generated from reading UI file 'searchmerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHMERWINDOW_H
#define UI_SEARCHMERWINDOW_H

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

class Ui_SearchMerWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *search_content_text;
    QLabel *label_4;
    QRadioButton *check_type;
    QRadioButton *check_seller_uid;
    QLabel *label;
    QRadioButton *check_name_include;
    QRadioButton *check_mid;
    QLabel *label_3;
    QRadioButton *check_name_equal;
    QPushButton *postBtn;
    QLabel *label_2;

    void setupUi(QWidget *SearchMerWindow)
    {
        if (SearchMerWindow->objectName().isEmpty())
            SearchMerWindow->setObjectName(QString::fromUtf8("SearchMerWindow"));
        SearchMerWindow->resize(765, 237);
        SearchMerWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        verticalLayout = new QVBoxLayout(SearchMerWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        search_content_text = new QLineEdit(SearchMerWindow);
        search_content_text->setObjectName(QString::fromUtf8("search_content_text"));

        gridLayout->addWidget(search_content_text, 3, 1, 1, 5);

        label_4 = new QLabel(SearchMerWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        check_type = new QRadioButton(SearchMerWindow);
        check_type->setObjectName(QString::fromUtf8("check_type"));

        gridLayout->addWidget(check_type, 2, 5, 1, 1);

        check_seller_uid = new QRadioButton(SearchMerWindow);
        check_seller_uid->setObjectName(QString::fromUtf8("check_seller_uid"));

        gridLayout->addWidget(check_seller_uid, 2, 4, 1, 1);

        label = new QLabel(SearchMerWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 1, 1, 4);

        check_name_include = new QRadioButton(SearchMerWindow);
        check_name_include->setObjectName(QString::fromUtf8("check_name_include"));

        gridLayout->addWidget(check_name_include, 2, 3, 1, 1);

        check_mid = new QRadioButton(SearchMerWindow);
        check_mid->setObjectName(QString::fromUtf8("check_mid"));
        check_mid->setChecked(true);

        gridLayout->addWidget(check_mid, 2, 1, 1, 1);

        label_3 = new QLabel(SearchMerWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(14);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        check_name_equal = new QRadioButton(SearchMerWindow);
        check_name_equal->setObjectName(QString::fromUtf8("check_name_equal"));
        check_name_equal->setChecked(false);

        gridLayout->addWidget(check_name_equal, 2, 2, 1, 1);

        postBtn = new QPushButton(SearchMerWindow);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));

        gridLayout->addWidget(postBtn, 4, 2, 1, 2);

        label_2 = new QLabel(SearchMerWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 1, 1, 4);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(SearchMerWindow);

        QMetaObject::connectSlotsByName(SearchMerWindow);
    } // setupUi

    void retranslateUi(QWidget *SearchMerWindow)
    {
        SearchMerWindow->setWindowTitle(QApplication::translate("SearchMerWindow", "\347\224\234\351\261\274: \346\220\234\347\264\242\345\225\206\345\223\201\347\225\214\351\235\242", nullptr));
        label_4->setText(QApplication::translate("SearchMerWindow", "\346\220\234\347\264\242\345\205\263\351\224\256\345\255\227:", nullptr));
        check_type->setText(QApplication::translate("SearchMerWindow", "\345\225\206\345\223\201\347\261\273\345\210\253", nullptr));
        check_seller_uid->setText(QApplication::translate("SearchMerWindow", "\345\215\226\345\256\266UID", nullptr));
        label->setText(QApplication::translate("SearchMerWindow", "\347\224\234\351\261\274\344\272\214\346\211\213\344\272\244\346\230\223\345\271\263\345\217\260", nullptr));
        check_name_include->setText(QApplication::translate("SearchMerWindow", "\345\225\206\345\223\201\345\220\215(\345\214\205\345\220\253\345\214\271\351\205\215)", nullptr));
        check_mid->setText(QApplication::translate("SearchMerWindow", "MID", nullptr));
        label_3->setText(QApplication::translate("SearchMerWindow", "\346\220\234\347\264\242\345\206\205\345\256\271:", nullptr));
        check_name_equal->setText(QApplication::translate("SearchMerWindow", "\345\225\206\345\223\201\345\220\215(\345\256\214\345\205\250\345\214\271\351\205\215)", nullptr));
        postBtn->setText(QApplication::translate("SearchMerWindow", "\346\220\234\347\264\242", nullptr));
        label_2->setText(QApplication::translate("SearchMerWindow", "\346\220\234\347\264\242\345\225\206\345\223\201\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchMerWindow: public Ui_SearchMerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHMERWINDOW_H
