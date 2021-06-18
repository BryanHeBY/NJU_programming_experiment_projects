/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QAction *menu_show_money;
    QAction *menu_user_charge;
    QAction *menu_user_messages_mode;
    QAction *menu_user_change_inf;
    QAction *menu_post_mer;
    QAction *menu_remove_mer;
    QAction *menu_change_mer_inf;
    QAction *menu_show_my_sell_mer;
    QAction *menu_show_my_sell_order_form;
    QAction *menu_show_all_mer;
    QAction *menu_change_mer_show_mode;
    QAction *menu_search_mer;
    QAction *menu_buy_mer;
    QAction *menu_show_my_buy_order_form;
    QAction *menu_send_messages;
    QAction *menu_show_my_receive_messages;
    QAction *menu_show_my_send_messages;
    QAction *menu_user_logout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *show_money;
    QPushButton *user_charge;
    QPushButton *user_change_inf;
    QPushButton *send_messages;
    QPushButton *show_my_receive_messages;
    QPushButton *show_my_send_messages;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *post_mer;
    QPushButton *remove_mer;
    QPushButton *change_mer_inf;
    QPushButton *show_my_sell_mer;
    QPushButton *show_my_sell_order_form;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPushButton *show_all_mer;
    QPushButton *change_mer_show_mode;
    QPushButton *search_mer;
    QPushButton *buy_mer;
    QPushButton *show_my_buy_order_form;
    QTableView *uni_table;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName(QString::fromUtf8("UserWindow"));
        UserWindow->resize(910, 600);
        UserWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        menu_show_money = new QAction(UserWindow);
        menu_show_money->setObjectName(QString::fromUtf8("menu_show_money"));
        menu_user_charge = new QAction(UserWindow);
        menu_user_charge->setObjectName(QString::fromUtf8("menu_user_charge"));
        menu_user_messages_mode = new QAction(UserWindow);
        menu_user_messages_mode->setObjectName(QString::fromUtf8("menu_user_messages_mode"));
        menu_user_change_inf = new QAction(UserWindow);
        menu_user_change_inf->setObjectName(QString::fromUtf8("menu_user_change_inf"));
        menu_post_mer = new QAction(UserWindow);
        menu_post_mer->setObjectName(QString::fromUtf8("menu_post_mer"));
        menu_remove_mer = new QAction(UserWindow);
        menu_remove_mer->setObjectName(QString::fromUtf8("menu_remove_mer"));
        menu_change_mer_inf = new QAction(UserWindow);
        menu_change_mer_inf->setObjectName(QString::fromUtf8("menu_change_mer_inf"));
        menu_show_my_sell_mer = new QAction(UserWindow);
        menu_show_my_sell_mer->setObjectName(QString::fromUtf8("menu_show_my_sell_mer"));
        menu_show_my_sell_order_form = new QAction(UserWindow);
        menu_show_my_sell_order_form->setObjectName(QString::fromUtf8("menu_show_my_sell_order_form"));
        menu_show_all_mer = new QAction(UserWindow);
        menu_show_all_mer->setObjectName(QString::fromUtf8("menu_show_all_mer"));
        menu_change_mer_show_mode = new QAction(UserWindow);
        menu_change_mer_show_mode->setObjectName(QString::fromUtf8("menu_change_mer_show_mode"));
        menu_search_mer = new QAction(UserWindow);
        menu_search_mer->setObjectName(QString::fromUtf8("menu_search_mer"));
        menu_buy_mer = new QAction(UserWindow);
        menu_buy_mer->setObjectName(QString::fromUtf8("menu_buy_mer"));
        menu_show_my_buy_order_form = new QAction(UserWindow);
        menu_show_my_buy_order_form->setObjectName(QString::fromUtf8("menu_show_my_buy_order_form"));
        menu_send_messages = new QAction(UserWindow);
        menu_send_messages->setObjectName(QString::fromUtf8("menu_send_messages"));
        menu_show_my_receive_messages = new QAction(UserWindow);
        menu_show_my_receive_messages->setObjectName(QString::fromUtf8("menu_show_my_receive_messages"));
        menu_show_my_send_messages = new QAction(UserWindow);
        menu_show_my_send_messages->setObjectName(QString::fromUtf8("menu_show_my_send_messages"));
        menu_user_logout = new QAction(UserWindow);
        menu_user_logout->setObjectName(QString::fromUtf8("menu_user_logout"));
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        show_money = new QPushButton(centralwidget);
        show_money->setObjectName(QString::fromUtf8("show_money"));

        horizontalLayout->addWidget(show_money);

        user_charge = new QPushButton(centralwidget);
        user_charge->setObjectName(QString::fromUtf8("user_charge"));

        horizontalLayout->addWidget(user_charge);

        user_change_inf = new QPushButton(centralwidget);
        user_change_inf->setObjectName(QString::fromUtf8("user_change_inf"));

        horizontalLayout->addWidget(user_change_inf);

        send_messages = new QPushButton(centralwidget);
        send_messages->setObjectName(QString::fromUtf8("send_messages"));

        horizontalLayout->addWidget(send_messages);

        show_my_receive_messages = new QPushButton(centralwidget);
        show_my_receive_messages->setObjectName(QString::fromUtf8("show_my_receive_messages"));

        horizontalLayout->addWidget(show_my_receive_messages);

        show_my_send_messages = new QPushButton(centralwidget);
        show_my_send_messages->setObjectName(QString::fromUtf8("show_my_send_messages"));

        horizontalLayout->addWidget(show_my_send_messages);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        post_mer = new QPushButton(centralwidget);
        post_mer->setObjectName(QString::fromUtf8("post_mer"));

        horizontalLayout_2->addWidget(post_mer);

        remove_mer = new QPushButton(centralwidget);
        remove_mer->setObjectName(QString::fromUtf8("remove_mer"));

        horizontalLayout_2->addWidget(remove_mer);

        change_mer_inf = new QPushButton(centralwidget);
        change_mer_inf->setObjectName(QString::fromUtf8("change_mer_inf"));

        horizontalLayout_2->addWidget(change_mer_inf);

        show_my_sell_mer = new QPushButton(centralwidget);
        show_my_sell_mer->setObjectName(QString::fromUtf8("show_my_sell_mer"));

        horizontalLayout_2->addWidget(show_my_sell_mer);

        show_my_sell_order_form = new QPushButton(centralwidget);
        show_my_sell_order_form->setObjectName(QString::fromUtf8("show_my_sell_order_form"));

        horizontalLayout_2->addWidget(show_my_sell_order_form);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        show_all_mer = new QPushButton(centralwidget);
        show_all_mer->setObjectName(QString::fromUtf8("show_all_mer"));

        horizontalLayout_3->addWidget(show_all_mer);

        change_mer_show_mode = new QPushButton(centralwidget);
        change_mer_show_mode->setObjectName(QString::fromUtf8("change_mer_show_mode"));

        horizontalLayout_3->addWidget(change_mer_show_mode);

        search_mer = new QPushButton(centralwidget);
        search_mer->setObjectName(QString::fromUtf8("search_mer"));

        horizontalLayout_3->addWidget(search_mer);

        buy_mer = new QPushButton(centralwidget);
        buy_mer->setObjectName(QString::fromUtf8("buy_mer"));

        horizontalLayout_3->addWidget(buy_mer);

        show_my_buy_order_form = new QPushButton(centralwidget);
        show_my_buy_order_form->setObjectName(QString::fromUtf8("show_my_buy_order_form"));

        horizontalLayout_3->addWidget(show_my_buy_order_form);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        uni_table = new QTableView(centralwidget);
        uni_table->setObjectName(QString::fromUtf8("uni_table"));

        verticalLayout->addWidget(uni_table);

        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 910, 28));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UserWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu_2->addAction(menu_show_money);
        menu_2->addAction(menu_user_charge);
        menu_2->addAction(menu_user_change_inf);
        menu_2->addSeparator();
        menu_2->addAction(menu_user_logout);
        menu_3->addAction(menu_post_mer);
        menu_3->addAction(menu_remove_mer);
        menu_3->addAction(menu_change_mer_inf);
        menu_3->addAction(menu_show_my_sell_mer);
        menu_3->addAction(menu_show_my_sell_order_form);
        menu_4->addAction(menu_show_all_mer);
        menu_4->addAction(menu_change_mer_show_mode);
        menu_4->addAction(menu_search_mer);
        menu_4->addAction(menu_buy_mer);
        menu_4->addAction(menu_show_my_buy_order_form);
        menu_5->addAction(menu_send_messages);
        menu_5->addAction(menu_show_my_receive_messages);
        menu_5->addAction(menu_show_my_send_messages);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QApplication::translate("UserWindow", "\347\224\234\351\261\274: \347\224\250\346\210\267\344\275\277\347\224\250\347\225\214\351\235\242", nullptr));
        menu_show_money->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\347\224\250\346\210\267\344\275\231\351\242\235", nullptr));
        menu_user_charge->setText(QApplication::translate("UserWindow", "\350\264\246\346\210\267\345\205\205\345\200\274", nullptr));
        menu_user_messages_mode->setText(QApplication::translate("UserWindow", "\347\224\250\346\210\267\347\225\231\350\250\200\346\250\241\345\235\227", nullptr));
        menu_user_change_inf->setText(QApplication::translate("UserWindow", "\344\277\256\346\224\271\346\210\221\347\232\204\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        menu_post_mer->setText(QApplication::translate("UserWindow", "\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        menu_remove_mer->setText(QApplication::translate("UserWindow", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        menu_change_mer_inf->setText(QApplication::translate("UserWindow", "\344\277\256\346\224\271\346\210\221\347\232\204\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        menu_show_my_sell_mer->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\345\217\221\345\270\203\347\232\204\345\225\206\345\223\201", nullptr));
        menu_show_my_sell_order_form->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\345\215\226\345\207\272\347\232\204\350\256\242\345\215\225", nullptr));
        menu_show_all_mer->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\345\225\206\345\223\201", nullptr));
        menu_change_mer_show_mode->setText(QApplication::translate("UserWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\346\237\245\347\234\213\351\200\211\351\241\271", nullptr));
        menu_search_mer->setText(QApplication::translate("UserWindow", "\346\220\234\347\264\242\345\225\206\345\223\201", nullptr));
        menu_buy_mer->setText(QApplication::translate("UserWindow", "\350\264\255\344\271\260\345\225\206\345\223\201", nullptr));
        menu_show_my_buy_order_form->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\344\271\260\345\205\245\347\232\204\350\256\242\345\215\225", nullptr));
        menu_send_messages->setText(QApplication::translate("UserWindow", "\345\217\221\351\200\201\347\225\231\350\250\200", nullptr));
        menu_show_my_receive_messages->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\346\224\266\345\210\260\347\232\204\347\225\231\350\250\200", nullptr));
        menu_show_my_send_messages->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\345\217\221\345\207\272\347\232\204\347\225\231\350\250\200", nullptr));
        menu_user_logout->setText(QApplication::translate("UserWindow", "\347\224\250\346\210\267\346\263\250\351\224\200", nullptr));
        show_money->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\347\232\204\344\275\231\351\242\235", nullptr));
        user_charge->setText(QApplication::translate("UserWindow", "\350\264\246\346\210\267\345\205\205\345\200\274", nullptr));
        user_change_inf->setText(QApplication::translate("UserWindow", "\344\277\256\346\224\271\346\210\221\347\232\204\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        send_messages->setText(QApplication::translate("UserWindow", "\345\217\221\351\200\201\347\225\231\350\250\200", nullptr));
        show_my_receive_messages->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\346\224\266\345\210\260\347\232\204\347\225\231\350\250\200", nullptr));
        show_my_send_messages->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\345\217\221\345\207\272\347\232\204\347\225\231\350\250\200", nullptr));
        label->setText(QApplication::translate("UserWindow", "\345\215\226\345\256\266\346\223\215\344\275\234:", nullptr));
        post_mer->setText(QApplication::translate("UserWindow", "\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        remove_mer->setText(QApplication::translate("UserWindow", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        change_mer_inf->setText(QApplication::translate("UserWindow", "\344\277\256\346\224\271\346\210\221\347\232\204\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        show_my_sell_mer->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\345\217\221\345\270\203\347\232\204\345\225\206\345\223\201", nullptr));
        show_my_sell_order_form->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\345\215\226\345\207\272\347\232\204\350\256\242\345\215\225", nullptr));
        label_2->setText(QApplication::translate("UserWindow", "\344\271\260\345\256\266\346\223\215\344\275\234:", nullptr));
        show_all_mer->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\345\225\206\345\223\201", nullptr));
        change_mer_show_mode->setText(QApplication::translate("UserWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\346\237\245\347\234\213\351\200\211\351\241\271", nullptr));
        search_mer->setText(QApplication::translate("UserWindow", "\346\220\234\347\264\242\345\225\206\345\223\201", nullptr));
        buy_mer->setText(QApplication::translate("UserWindow", "\350\264\255\344\271\260\345\225\206\345\223\201", nullptr));
        show_my_buy_order_form->setText(QApplication::translate("UserWindow", "\346\237\245\347\234\213\346\210\221\344\271\260\345\205\245\347\232\204\350\256\242\345\215\225", nullptr));
        menu->setTitle(QApplication::translate("UserWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("UserWindow", "\347\224\250\346\210\267\346\223\215\344\275\234", nullptr));
        menu_3->setTitle(QApplication::translate("UserWindow", "\345\215\226\345\256\266\346\223\215\344\275\234", nullptr));
        menu_4->setTitle(QApplication::translate("UserWindow", "\344\271\260\345\256\266\346\223\215\344\275\234", nullptr));
        menu_5->setTitle(QApplication::translate("UserWindow", "\347\225\231\350\250\200\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
