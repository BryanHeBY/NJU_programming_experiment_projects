QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core_module/db_type.cpp \
    core_module/table.cpp \
    error_solve/ErrorTB.cpp \
    main.cpp \
    tables/base_table.cpp \
    tables/merchandises_table.cpp \
    tables/messages_table.cpp \
    tables/order_form_table.cpp \
    tables/tbset.cpp \
    tables/users_table.cpp \
    ui/cui/cui.cpp \
    ui/gui/admindeleteuser.cpp \
    ui/gui/adminlogonwindow.cpp \
    ui/gui/adminsearchmessage.cpp \
    ui/gui/adminsearchorderform.cpp \
    ui/gui/adminsearchuser.cpp \
    ui/gui/adminuserinfchange.cpp \
    ui/gui/adminuserwindow.cpp \
    ui/gui/buymerwindow.cpp \
    ui/gui/changemerinfwindow.cpp \
    ui/gui/changemershowmodewindow.cpp \
    ui/gui/getchangemerinf.cpp \
    ui/gui/loginwindow.cpp \
    ui/gui/logonwindow.cpp \
    ui/gui/postmerwindow.cpp \
    ui/gui/removemerwindow.cpp \
    ui/gui/searchmerwindow.cpp \
    ui/gui/sendmessagewindow.cpp \
    ui/gui/userchangeinfwindow.cpp \
    ui/gui/userchargewindow.cpp \
    ui/gui/userremovemerwindow.cpp \
    ui/gui/userwindow.cpp

HEADERS += \
    core_module/db_type.h \
    core_module/table.h \
    error_solve/ErrorTB.h \
    tables/base_table.h \
    tables/merchandises_table.h \
    tables/messages_table.h \
    tables/order_form_table.h \
    tables/tbset.h \
    tables/users_table.h \
    ui/cui/cui.h \
    ui/gui/admindeleteuser.h \
    ui/gui/adminlogonwindow.h \
    ui/gui/adminsearchmessage.h \
    ui/gui/adminsearchorderform.h \
    ui/gui/adminsearchuser.h \
    ui/gui/adminuserinfchange.h \
    ui/gui/adminuserwindow.h \
    ui/gui/buymerwindow.h \
    ui/gui/changemerinfwindow.h \
    ui/gui/changemershowmodewindow.h \
    ui/gui/getchangemerinf.h \
    ui/gui/loginwindow.h \
    ui/gui/logonwindow.h \
    ui/gui/postmerwindow.h \
    ui/gui/removemerwindow.h \
    ui/gui/searchmerwindow.h \
    ui/gui/sendmessagewindow.h \
    ui/gui/userchangeinfwindow.h \
    ui/gui/userchargewindow.h \
    ui/gui/userremovemerwindow.h \
    ui/gui/userwindow.h

FORMS += \
    ui/gui/admindeleteuser.ui \
    ui/gui/adminlogonwindow.ui \
    ui/gui/adminsearchmessage.ui \
    ui/gui/adminsearchorderform.ui \
    ui/gui/adminsearchuser.ui \
    ui/gui/adminuserinfchange.ui \
    ui/gui/adminuserwindow.ui \
    ui/gui/buymerwindow.ui \
    ui/gui/changemerinfwindow.ui \
    ui/gui/changemershowmodewindow.ui \
    ui/gui/getchangemerinf.ui \
    ui/gui/loginwindow.ui \
    ui/gui/logonwindow.ui \
    ui/gui/postmerwindow.ui \
    ui/gui/removemerwindow.ui \
    ui/gui/searchmerwindow.ui \
    ui/gui/sendmessagewindow.ui \
    ui/gui/userchangeinfwindow.ui \
    ui/gui/userchargewindow.ui \
    ui/gui/userremovemerwindow.ui \
    ui/gui/userwindow.ui

TRANSLATIONS += \
    sweet_fish_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
