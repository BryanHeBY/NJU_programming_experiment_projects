#include "mainwindow.h"

#include <QApplication>

#include "ui/cui/cui.h"
#include "ui/gui/loginwindow.h"
#include "ui/gui/adminlogonwindow.h"
#include "tables/tbset.h"


int main(int argc, char *argv[])
{
    if(argc==2&&strcmp(argv[1],"-c")==0){
        CUI window;
        while(window.mainloop());
        return 0;
    }else{
        QApplication a(argc, argv);
        TBSet TBs;
        LoginWindow w(NULL,&TBs);
        w.show();
        if(!TBs.Users.user_exist_name("admin")){
            AdminLogonWindow *adminLogonWindow=new AdminLogonWindow(NULL,&TBs);
            adminLogonWindow->show();
        }
        return a.exec();
    }
}
