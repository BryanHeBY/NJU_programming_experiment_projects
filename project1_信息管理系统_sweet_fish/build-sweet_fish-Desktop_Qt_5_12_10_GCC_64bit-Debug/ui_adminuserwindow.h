/********************************************************************************
** Form generated from reading UI file 'adminuserwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUSERWINDOW_H
#define UI_ADMINUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminUserWindow
{
public:
    QAction *menu_user_inf_change;
    QAction *menu_logout;
    QAction *menu_show_all_users;
    QAction *menu_show_all_mer;
    QAction *menu_admin_search_user;
    QAction *menu_admin_delete_user;
    QAction *menu_search_mer;
    QAction *menu_change_mer_show_mode;
    QAction *menu_show_all_order_form;
    QAction *menu_admin_search_order_form;
    QAction *menu_show_all_message;
    QAction *menu_admin_search_message;
    QAction *menu_admin_remove_mer;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *show_all_users;
    QPushButton *show_all_mer;
    QPushButton *change_mer_show_mode;
    QPushButton *show_all_order_form;
    QPushButton *show_all_messages;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *admin_user_inf_change;
    QPushButton *admin_delete_user;
    QPushButton *admin_remove_mer;
    QPushButton *admin_search_user;
    QPushButton *search_mer;
    QPushButton *admin_search_order_form;
    QPushButton *admin_search_message;
    QTableView *uni_table;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminUserWindow)
    {
        if (AdminUserWindow->objectName().isEmpty())
            AdminUserWindow->setObjectName(QString::fromUtf8("AdminUserWindow"));
        AdminUserWindow->resize(907, 603);
        AdminUserWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        menu_user_inf_change = new QAction(AdminUserWindow);
        menu_user_inf_change->setObjectName(QString::fromUtf8("menu_user_inf_change"));
        menu_logout = new QAction(AdminUserWindow);
        menu_logout->setObjectName(QString::fromUtf8("menu_logout"));
        menu_show_all_users = new QAction(AdminUserWindow);
        menu_show_all_users->setObjectName(QString::fromUtf8("menu_show_all_users"));
        menu_show_all_mer = new QAction(AdminUserWindow);
        menu_show_all_mer->setObjectName(QString::fromUtf8("menu_show_all_mer"));
        menu_admin_search_user = new QAction(AdminUserWindow);
        menu_admin_search_user->setObjectName(QString::fromUtf8("menu_admin_search_user"));
        menu_admin_delete_user = new QAction(AdminUserWindow);
        menu_admin_delete_user->setObjectName(QString::fromUtf8("menu_admin_delete_user"));
        menu_search_mer = new QAction(AdminUserWindow);
        menu_search_mer->setObjectName(QString::fromUtf8("menu_search_mer"));
        menu_change_mer_show_mode = new QAction(AdminUserWindow);
        menu_change_mer_show_mode->setObjectName(QString::fromUtf8("menu_change_mer_show_mode"));
        menu_show_all_order_form = new QAction(AdminUserWindow);
        menu_show_all_order_form->setObjectName(QString::fromUtf8("menu_show_all_order_form"));
        menu_admin_search_order_form = new QAction(AdminUserWindow);
        menu_admin_search_order_form->setObjectName(QString::fromUtf8("menu_admin_search_order_form"));
        menu_show_all_message = new QAction(AdminUserWindow);
        menu_show_all_message->setObjectName(QString::fromUtf8("menu_show_all_message"));
        menu_admin_search_message = new QAction(AdminUserWindow);
        menu_admin_search_message->setObjectName(QString::fromUtf8("menu_admin_search_message"));
        menu_admin_remove_mer = new QAction(AdminUserWindow);
        menu_admin_remove_mer->setObjectName(QString::fromUtf8("menu_admin_remove_mer"));
        centralwidget = new QWidget(AdminUserWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        show_all_users = new QPushButton(centralwidget);
        show_all_users->setObjectName(QString::fromUtf8("show_all_users"));

        horizontalLayout->addWidget(show_all_users);

        show_all_mer = new QPushButton(centralwidget);
        show_all_mer->setObjectName(QString::fromUtf8("show_all_mer"));

        horizontalLayout->addWidget(show_all_mer);

        change_mer_show_mode = new QPushButton(centralwidget);
        change_mer_show_mode->setObjectName(QString::fromUtf8("change_mer_show_mode"));

        horizontalLayout->addWidget(change_mer_show_mode);

        show_all_order_form = new QPushButton(centralwidget);
        show_all_order_form->setObjectName(QString::fromUtf8("show_all_order_form"));

        horizontalLayout->addWidget(show_all_order_form);

        show_all_messages = new QPushButton(centralwidget);
        show_all_messages->setObjectName(QString::fromUtf8("show_all_messages"));

        horizontalLayout->addWidget(show_all_messages);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        admin_user_inf_change = new QPushButton(centralwidget);
        admin_user_inf_change->setObjectName(QString::fromUtf8("admin_user_inf_change"));

        horizontalLayout_2->addWidget(admin_user_inf_change);

        admin_delete_user = new QPushButton(centralwidget);
        admin_delete_user->setObjectName(QString::fromUtf8("admin_delete_user"));

        horizontalLayout_2->addWidget(admin_delete_user);

        admin_remove_mer = new QPushButton(centralwidget);
        admin_remove_mer->setObjectName(QString::fromUtf8("admin_remove_mer"));

        horizontalLayout_2->addWidget(admin_remove_mer);

        admin_search_user = new QPushButton(centralwidget);
        admin_search_user->setObjectName(QString::fromUtf8("admin_search_user"));

        horizontalLayout_2->addWidget(admin_search_user);

        search_mer = new QPushButton(centralwidget);
        search_mer->setObjectName(QString::fromUtf8("search_mer"));

        horizontalLayout_2->addWidget(search_mer);

        admin_search_order_form = new QPushButton(centralwidget);
        admin_search_order_form->setObjectName(QString::fromUtf8("admin_search_order_form"));

        horizontalLayout_2->addWidget(admin_search_order_form);

        admin_search_message = new QPushButton(centralwidget);
        admin_search_message->setObjectName(QString::fromUtf8("admin_search_message"));

        horizontalLayout_2->addWidget(admin_search_message);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        uni_table = new QTableView(centralwidget);
        uni_table->setObjectName(QString::fromUtf8("uni_table"));

        verticalLayout->addWidget(uni_table);

        AdminUserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminUserWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 907, 28));
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
        AdminUserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminUserWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminUserWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menu_2->addAction(menu_user_inf_change);
        menu_2->addAction(menu_logout);
        menu_2->addSeparator();
        menu_2->addAction(menu_show_all_users);
        menu_2->addAction(menu_admin_search_user);
        menu_2->addAction(menu_admin_delete_user);
        menu_3->addAction(menu_admin_remove_mer);
        menu_3->addAction(menu_show_all_mer);
        menu_3->addAction(menu_change_mer_show_mode);
        menu_3->addAction(menu_search_mer);
        menu_4->addAction(menu_show_all_order_form);
        menu_4->addAction(menu_admin_search_order_form);
        menu_5->addAction(menu_show_all_message);
        menu_5->addAction(menu_admin_search_message);

        retranslateUi(AdminUserWindow);

        QMetaObject::connectSlotsByName(AdminUserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminUserWindow)
    {
        AdminUserWindow->setWindowTitle(QApplication::translate("AdminUserWindow", "\347\224\234\351\261\274: \347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\344\275\277\347\224\250\347\225\214\351\235\242", nullptr));
        menu_user_inf_change->setText(QApplication::translate("AdminUserWindow", "\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        menu_logout->setText(QApplication::translate("AdminUserWindow", "\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267\346\263\250\351\224\200", nullptr));
        menu_show_all_users->setText(QApplication::translate("AdminUserWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        menu_show_all_mer->setText(QApplication::translate("AdminUserWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\345\225\206\345\223\201", nullptr));
        menu_admin_search_user->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        menu_admin_delete_user->setText(QApplication::translate("AdminUserWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        menu_search_mer->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        menu_change_mer_show_mode->setText(QApplication::translate("AdminUserWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\346\237\245\347\234\213\346\235\241\344\273\266", nullptr));
        menu_show_all_order_form->setText(QApplication::translate("AdminUserWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\350\256\242\345\215\225", nullptr));
        menu_admin_search_order_form->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\350\256\242\345\215\225\344\277\241\346\201\257", nullptr));
        menu_show_all_message->setText(QApplication::translate("AdminUserWindow", "\346\237\245\347\234\213\346\211\200\346\234\211\347\225\231\350\250\200", nullptr));
        menu_admin_search_message->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\347\225\231\350\250\200\344\277\241\346\201\257", nullptr));
        menu_admin_remove_mer->setText(QApplication::translate("AdminUserWindow", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        show_all_users->setText(QApplication::translate("AdminUserWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        show_all_mer->setText(QApplication::translate("AdminUserWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\345\225\206\345\223\201", nullptr));
        change_mer_show_mode->setText(QApplication::translate("AdminUserWindow", "\344\277\256\346\224\271\345\225\206\345\223\201\346\237\245\347\234\213\346\235\241\344\273\266", nullptr));
        show_all_order_form->setText(QApplication::translate("AdminUserWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\350\256\242\345\215\225", nullptr));
        show_all_messages->setText(QApplication::translate("AdminUserWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\347\225\231\350\250\200", nullptr));
        admin_user_inf_change->setText(QApplication::translate("AdminUserWindow", "\344\277\256\346\224\271\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        admin_delete_user->setText(QApplication::translate("AdminUserWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        admin_remove_mer->setText(QApplication::translate("AdminUserWindow", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        admin_search_user->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        search_mer->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        admin_search_order_form->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\350\256\242\345\215\225\344\277\241\346\201\257", nullptr));
        admin_search_message->setText(QApplication::translate("AdminUserWindow", "\346\237\245\350\257\242\347\225\231\350\250\200\344\277\241\346\201\257", nullptr));
        menu->setTitle(QApplication::translate("AdminUserWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("AdminUserWindow", "\347\224\250\346\210\267", nullptr));
        menu_3->setTitle(QApplication::translate("AdminUserWindow", "\345\225\206\345\223\201", nullptr));
        menu_4->setTitle(QApplication::translate("AdminUserWindow", "\350\256\242\345\215\225", nullptr));
        menu_5->setTitle(QApplication::translate("AdminUserWindow", "\347\225\231\350\250\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminUserWindow: public Ui_AdminUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUSERWINDOW_H
