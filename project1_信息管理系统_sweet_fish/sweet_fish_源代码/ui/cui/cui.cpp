//
// Created by hby on 2021/3/27.
//

#include "cui.h"
#include "../../error_solve/ErrorTB.h"

void CUI::save_file() {
    _Users.write_file();
    _Merchandises.write_file();
    _OrderForm.write_file();
}

bool CUI::mainloop(){
    while(!_Users.user_exist_name("admin"))user_logon_admin();
    cout<<"****************************************************\n";
    cout<<"*           欢迎使用甜鱼二手商品交易平台！         *\n";
    cout<<"* 1.用户登录 2.用户注册 3.保存数据文件 4.退出程序  *\n";
    cout<<"****************************************************\n";
    cout<<"请输入使用模块: ";
    char op;cin>>op;
    if(op=='1'){
        table user_inf;
        int user_rank=user_login(user_inf);
        if(user_rank==2)while(admin_user_window(user_inf));
        else if(user_rank==0)while(default_user_window(user_inf));
    }
    else if(op=='2')user_logon();
    else if(op=='3'){
        save_file();
        cout<<"             数据文件保存成功!\n";
        cout<<"--------------------------------------------\n";
    }
    else if(op=='4'){
        cout<<"欢迎您下次使用！\n";
        return 0;
    }
    else cout<<"输入有误！\n";
    return 1;
}

bool CUI::user_logon_admin(){
    cout<<"您还未注册管理员(admin)账号，现在需要注册。\n";
    cout<<"管理员账号用户名: admin\n";
    cout<<"请输入管理员账号密码: \n";
    string pwd;
    cin>>pwd;
    try {_Users.admin_logon(pwd,"admin","南京大学计算机系");}
    catch(ErrorTB &e){
        cout<<e.what()<<endl;
        return 0;
    }
    cout<<"注册成功！\n\n";
    cout<<"------------------------------------\n";
    return 1;
}

void CUI::user_logon(){
    cout<<"\n---------------------------------------\n";
    cout<<"              用户注册模式\n";
    cout<<"请输入用户名: ";string user_name;cin>>user_name;
    cout<<"请输入密码: ";string user_pwd;cin>>user_pwd;
    cout<<"请输入联系方式: ";string user_contact;cin>>user_contact;
    cout<<"请输入地址: ";string user_home;cin>>user_home;
    bool has_error=0;
    try{_Users.logon(user_name,user_pwd,user_contact,user_home);}
    catch(ErrorTB &e){
        has_error=1;
        cout<<e.what()<<endl;
    }
    if(!has_error)cout<<"注册成功！\n\n";
    cout<<"---------------------------------------\n";
}

int CUI::user_login(table &user_inf){
    cout<<"\n---------------------------------------\n";
    cout<<"                登录界面\n";
    cout<<"请输入用户名: ";string user_name;cin>>user_name;
    cout<<"请输入密码: ";string user_pwd;cin>>user_pwd;
    bool has_error=0;
    try{_Users.login(user_inf,user_name,user_pwd);}
    catch(ErrorTB &e){
        has_error=1;
        cout<<e.what()<<endl;
    }
    if(!has_error){
        int user_rank=user_inf.get_item(0,6).get_int();
        if(user_rank==0){
            cout<<"          用户账号登录成功！\n";
            cout<<"---------------------------------------\n";
        }
        else if(user_rank==2){
            cout<<"          管理员账号登录成功！\n";
            cout<<"---------------------------------------\n";
        }
        return user_rank;
    }
    return -1;
}

bool CUI::admin_user_window(const table &user_inf) {
    cout<<"******************************************************************************************\n";
    cout<<"*                                 正在使用管理员模式                                     *\n";
    cout<<"* 1.查看、搜索、下架商品 2.查看、删除用户 3.查看所有订单 4.查看所有留言 5.注销管理员用户 *\n";
    cout<<"******************************************************************************************\n";
    cout<<"请输入使用模块: ";
    char op;cin>>op;
    if(op=='1')admin_manage_mer();
    else if(op=='2')admin_manage_users();
    else if(op=='3')admin_manage_order_form();
    else if(op=='4')_Messages.show();
    else if(op=='5'){cout<<"注销成功!\n";return 0;}
    else cout<<"输入有误！\n";
    return 1;
}

void CUI::admin_manage_mer() {
    cout<<"*************************************\n";
    cout<<"*     正在使用管理员管理商品模式    *\n";
    cout<<"*  1.查看商品 2.搜索商品 3.下架商品 *\n";
    cout<<"*************************************\n";
    cout<<"请输入使用模块: ";
    char op;cin>>op;
    try{
        if(op=='1')show_mer();
        else if(op=='2')while(search_mer());
        else if(op=='3')admin_remove_mer();
        else cout<<"输入有误！\n";
    }
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
}

bool CUI::search_mer() {
    cout<<"**************************************************************\n";
    cout<<"*                     进入商品搜索模式                       *\n";
    cout<<"* 搜索模式: 不排除下架售出商品 不显示详细信息 排序关键字:MID *\n";
    cout<<"*               请输入是否修改默认商品搜索模式               *\n";
    cout<<"**************************************************************\n";
    cout<<"是否要修改查看模式(y/default:n):";char change_mode;cin>>change_mode;
    char ex_not_valid='n',show_details='n',search_key='1';
    if(change_mode=='y'){
        cout<<"是否排除下架售出商品(y/default:n):";
        cin>>ex_not_valid;
        cout<<"是否显示详细信息(default:y/n):";
        cin>>show_details;
        cout<<"请输入搜索关键字: (default)1.MID 2.商品名(完全匹配) 3.商品名(包含匹配) 4.卖家UID 5.商品分类标签\n";
        cin>>search_key;
    }
    cout<<"搜索内容: ";string content;cin>>content;
    table res;
    try{
        if(search_key=='2')res=_Merchandises.search_mer_by_name_equal(content);
        else if(search_key=='3')res=_Merchandises.search_mer_by_name_include(content);
        else if(search_key=='4')res=_Merchandises.search_mer_by_seller_uid(content);
        else if(search_key=='5')res=_Merchandises.search_mer_by_type(content);
        else res=_Merchandises.search_mer_by_mid(content);
        if(ex_not_valid=='y')res.Delete(6,{1,merchandises_table::len_state,"销售中"},db_type_not_equal);
    }
    catch (ErrorTB &e){
        cout<<e.what();
        return 0;
    }
    cout<<"搜索结果:\n";
    if(show_details=='n')res.sub_table({0,1,2,4,5,6}).show();
    else res.show_details();
    cout<<"是否退出商品搜索模式(y/default:n): ";char quit='n';cin>>quit;
    if(quit=='y')return 0;
    else return 1;
}

void CUI::show_mer() {
    cout<<"******************************************************************\n";
    cout<<"*                       进入商品查看模式                         *\n";
    cout<<"* 查看模式: 排除下架售出商品 排序关键字:MID(倒序) 不限制显示数量 *\n";
    cout<<"*              请输入是否要修改默认商品查看模式                  *\n";
    cout<<"******************************************************************\n";
    cout<<"是否要修改查看模式(y/default:n):";char change_mode;cin>>change_mode;
    char ex_not_valid='y',sort_key='1';
    int limit_num=0;
    table res=_Merchandises.get_full_table();
    if(change_mode=='y'){
        cout<<"是否排除下架售出商品(default:y/n):";cin>>ex_not_valid;
        cout<<"请输入关键字: (default)1.MID(倒序) 2.MID(顺序) 3.商品名 4.价格\n";cin>>sort_key;
        cout<<"请输入显示数量(输入为0不限制):";cin>>limit_num;
    }
    if(ex_not_valid!='n')res.Delete(6,{1,merchandises_table::len_state,"销售中"},db_type_not_equal);
    if(sort_key=='2')res.tr_sort(0,1);
    else if(sort_key=='3')res.tr_sort(1,1);
    else if(sort_key=='4')res.tr_sort(2,1);
    else res.tr_sort(0,0);
    if(limit_num!=0)res=res.limit(limit_num);
    cout<<"商品查看结果: \n";
    res.sub_table({0,1,2,4,5,6}).show();
}

void CUI::admin_remove_mer() {
    cout<<"************************************************\n";
    cout<<"*             进入管理员商品下架模式            *\n";
    cout<<"************************************************\n";
    cout<<"请输入要下架商品的MID: ";string mid;cin>>mid;
    try{_Merchandises.remove_mer_by_mid(mid);}
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
    cout<<"商品下架成功!\n";
}

void CUI::admin_manage_users() {
    cout<<"********************************************************************\n";
    cout<<"*                    进入管理员管理用户界面                        *\n";
    cout<<"* 1.查看所有用户 2.根据UID搜索用户 3.根据用户名搜索用户 4.删除用户 *\n";
    cout<<"********************************************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    try{
        if(op=='1')cout<<"所有用户信息:\n",_Users.admin_show_users();
        else if(op=='2'){
            cout<<"请输入查询UID: ";string uid;cin>>uid;
            cout<<"查询结果:\n";
            _Users.get_full_table().select(0,{1,users_table::len_uid,uid},db_type_equal).show_details();
        }
        else if(op=='3'){
            cout<<"请输入查询用户名: ";string name;cin>>name;
            cout<<"查询结果:\n";
            _Users.get_full_table().select(1,{1,users_table::len_name,name},db_type_equal).show_details();
        }
        else if(op=='4'){
            cout<<"请输入要删除用户的UID: ";string uid;cin>>uid;
            _Users.delete_user_by_uid(uid);
            cout<<"用户删除成功!\n";
        }
        else cout<<"输入有误！\n";
    }
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
}


void CUI::admin_manage_order_form() {
    cout<<"************************************\n";
    cout<<"*     进入管理员管理订单界面       *\n";
    cout<<"* 1.查看所有订单 2.根据OID搜索订单 *\n";
    cout<<"************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    try{
        if(op=='1')cout<<"所有订单信息:\n",_OrderForm.show();
        else if(op=='2'){
            cout<<"请输入查询OID: ";string oid;cin>>oid;
            cout<<"查询结果:\n";
            _OrderForm.get_full_table().select(0,{1,order_form_table::len_oid,oid},db_type_equal).show_details();
        }
        else cout<<"输入有误！\n";
    }
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
}

bool CUI::default_user_window(const table &user_inf) {
    cout<<"***************************************************************************************************\n";
    cout<<"*                                      正在使用用户使用模式                                       *\n";
    cout<<"* 1.卖家模式 2.买家模式 3.查看我的订单 4.修改用户信息 5.账户充值 6.查询余额 7.留言模块 8.注销用户 *\n";
    cout<<"***************************************************************************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    if(op=='1')while(seller_mode(user_inf));
    else if(op=='2')while(buyer_mode(user_inf));
    else if(op=='3')user_show_order_form(user_inf);
    else if(op=='4')change_user_inf(user_inf);
    else if(op=='5')user_charge(user_inf);
    else if(op=='6') {
        printf("您的余额为: %.1f元\n",_Users.get_full_table().select(0,{1,users_table::len_uid,user_inf.get_item(0,0).get_string()},db_type_equal).get_item(0,5).get_float());
    }
    else if(op=='7')messages_manage_mode(user_inf);
    else if(op=='8'){cout<<"退出成功!\n";return 0;}
    else cout<<"输入有误！\n";
    return 1;
}

void CUI::user_charge(const table &user_inf) {
    cout<<"***************************************************\n";
    cout<<"*              正在使用用户充值模式               *\n";
    cout<<"***************************************************\n";
    cout<<"请输入充值码: ";string charge_pwd;cin>>charge_pwd;
    cout<<"请输入充值金额: ";float cash;cin>>cash;
    if(charge_pwd!="123456"){cout<<"充值码错误!\n";return;}
    _Users.change_cash(user_inf,cash);
    cout<<"充值成功!\n";
}

bool CUI::seller_mode(const table &user_inf) {
    cout<<"*******************************************************************************************\n";
    cout<<"*                                   正在使用卖家模式                                      *\n";
    cout<<"* 1.发布商品 2.下架商品 3.修改商品信息 4.查看已发布商品 5.查看我的卖出订单 6.退出卖家模式 *\n";
    cout<<"*******************************************************************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    if(op=='1')seller_post_mer(user_inf);
    else if(op=='2')seller_remove_mer(user_inf);
    else if(op=='3')seller_change_mer(user_inf);
    else if(op=='4')_Merchandises.search_mer_by_seller_uid(user_inf.get_item(0,0).get_string()).sub_table({0,1,2,4,5,6}).show();
    else if(op=='5')_OrderForm.search_by_seller_uid(user_inf.get_item(0,0).get_string()).show();
    else if(op=='6'){cout<<"退出成功!\n";return 0;}
    else cout<<"输入有误！\n";
    return 1;
}

bool CUI::buyer_mode(const table &user_inf) {
    cout<<"*********************************************************************************\n";
    cout<<"*                                  正在使用买家模式                             *\n";
    cout<<"* 1.查看商品 2.搜索商品 3.购买商品 4.查看余额 5.查看我的买入订单 6.退出买家模式 *\n";
    cout<<"*********************************************************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    if(op=='1')show_mer();
    else if(op=='2')while(search_mer());
    else if(op=='3') {
        cout<<"请输入您要购买的商品MID: ";string mid;cin>>mid;
        try{_Merchandises.buy_mer_by_mid(_Users,_OrderForm,user_inf,mid);}
        catch (ErrorTB &e){
            cout<<e.what()<<endl;
            return 1;
        }
        cout<<"购买成功!\n";
    }
    else if(op=='4'){
        printf("您的余额为: %.1f元\n",_Users.get_full_table().select(0,{1,users_table::len_uid,user_inf.get_item(0,0).get_string()},db_type_equal).get_item(0,5).get_float());
    }
    else if(op=='5')_OrderForm.search_by_buyer_uid(user_inf.get_item(0,0).get_string()).show();
    else if(op=='6'){cout<<"退出成功!\n";return 0;}
    else cout<<"输入有误！\n";
    return 1;
}


void CUI::user_show_order_form(const table &user_inf) {
    cout<<"**************************************************\n";
    cout<<"*             正在使用用户查看订单模式           *\n";
    cout<<"* 1.查看我的卖出订单 2(default).查看我的购买订单 *\n";
    cout<<"**************************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    cout<<"查询结果:\n";
    if(op=='1')_OrderForm.search_by_seller_uid(user_inf.get_item(0,0).get_string()).show();
    else _OrderForm.search_by_buyer_uid(user_inf.get_item(0,0).get_string()).show();
}

void CUI::change_user_inf(const table &user_inf) {
    cout<<"*************************************************\n";
    cout<<"*            正在使用用户修改信息模式           *\n";
    cout<<"* 修改关键字: 1.用户名 2.密码 3.联系方式 4.地址 *\n";
    cout<<"*************************************************\n";
    cout<<"请输入修改关键字: ";int td_key;cin>>td_key;
    cout<<"请输入修改内容: ";string to_value;cin>>to_value;
    try{_Users.change_user_inf_str(user_inf,td_key,to_value);}
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
    cout<<"修改成功!\n";
}

void CUI::seller_post_mer(const table &user_inf) {
    cout<<"*************************************************\n";
    cout<<"*            正在使用卖家发布商品模式           *\n";
    cout<<"*************************************************\n";
    cout<<"请输入商品名称: ";string name;cin>>name;
    cout<<"请输入商品价格: ";float price;cin>>price;
    cout<<"请输入商品描述(以\"$\"结束):\n";
    char description[merchandises_table::len_description];
    cin.get();cin.getline(description,merchandises_table::len_description,'$');
    cout<<endl<<"请输入商品标签集: ";string type_set;cin>>type_set;
    try{_Merchandises.post_mer(user_inf,name,price,description,type_set);}
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
    cout<<"修改成功!\n";
}

void CUI::seller_remove_mer(const table &user_inf) {
    cout<<"************************************************\n";
    cout<<"*             进入卖家商品下架模式            *\n";
    cout<<"************************************************\n";
    cout<<"请输入要下架商品的MID: ";string mid;cin>>mid;
    try{_Merchandises.remove_mer_by_mid_by_user(user_inf,mid);}
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
    cout<<"商品下架成功!\n";
}

void CUI::seller_change_mer(const table &user_inf) {
    cout<<"***************************************************\n";
    cout<<"*          正在使用用户修改商品信息模式           *\n";
    cout<<"*            请输入需要修改的商品MID              *\n";
    cout<<"* 修改关键字: 1.商品名 2.价格 3.商品描述 4.标签集 *\n";
    cout<<"***************************************************\n";
    cout<<"请输入需要修改的MID: ";string mid;cin>>mid;
    cout<<"请输入修改关键字: ";int td_key;cin>>td_key;
    try {
        if(td_key==1){
            cout<<"请输入修改内容: ";string to_value;cin>>to_value;
            _Merchandises.change_mer_inf_str_by_mid_by_user(mid,user_inf,1,to_value);
        }
        else if(td_key==2){
            cout<<"请输入修改内容: ";float to_value;cin>>to_value;
            _Merchandises.change_mer_price_by_mid_by_user(mid,user_inf,to_value);
        }
        else if(td_key==3){
            cout<<"请输入修改内容(以\"$\"结束): \n";cin.get();
            char description[merchandises_table::len_description];
            cin.getline(description,merchandises_table::len_description,'$');
            _Merchandises.change_mer_inf_str_by_mid_by_user(mid,user_inf,3,description);
        }
        else if(td_key==4){
            cout<<"请输入修改内容: ";string to_value;cin>>to_value;
            _Merchandises.change_mer_inf_str_by_mid_by_user(mid,user_inf,7,to_value);
        }
        else cout<<"你输入的值有误! \n";
    }
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
        return;
    }
    cout<<"修改成功!\n";
}

void CUI::messages_manage_mode(const table &user_inf) {
    cout<<"****************************************************\n";
    cout<<"*              正在使用用户管理留言模式            *\n";
    cout<<"* 1.发送留言 2.查看我收到的留言 3.查看我发送的留言 *\n";
    cout<<"****************************************************\n";
    cout<<"请输入使用模块: ";char op;cin>>op;
    try{
        if(op=='1') {
            cout<<"请输入接收方UID: ";string receiver_uid;cin>>receiver_uid;
            cout<<"请输入留言内容(以换行符结束): \n";cin.get();
            char message[messages_table::len_message];
            cin.getline(message,messages_table::len_message,'\n');
            _Messages.send_message(_Users,user_inf,receiver_uid,message);
            cout<<"发送成功!\n";
        }
        else if(op=='2')_Messages.search_by_receiver(user_inf).show_details();
        else if(op=='3')_Messages.search_by_sender(user_inf).show_details();
        else{
            cout<<"你输入的值有误! \n";
            return;
        }
    }
    catch (ErrorTB &e){
        cout<<e.what()<<endl;
    }

}


