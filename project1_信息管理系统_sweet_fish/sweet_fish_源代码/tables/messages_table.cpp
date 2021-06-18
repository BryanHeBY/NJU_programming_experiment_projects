//
// Created by hby on 2021/3/30.
//

#include "messages_table.h"
#include "../error_solve/ErrorTB.h"

void messages_table::create_table() {
    table messages(
            5,
            {"LID","发送方UID","接收方UID","发送时间","留言内容"},
            {1,1,1,1,1},
            {len_lid,len_sender_uid,len_receiver_uid,len_send_time,len_message},
            0,'L'
            );
    messages.write_file(_src.c_str());
}

messages_table::messages_table():base_table("messages","messages.tb"){
    if(!isFileExists(_src.c_str()))create_table();
    _table=table(_src.c_str(),1,2);
}

void messages_table::send_message(users_table &Users, const table &sender, const string &receiver_uid,const string &message) {
    if(message.empty())throw (ErrorTB("message is empty.","701","留言内容为空!\n"));
    Users.check_user_exist_by_uid(receiver_uid);
    _table.insert({
        CounterBase,
        {1,len_sender_uid,sender.get_item(0,0).get_string()},
        {1,len_receiver_uid,receiver_uid},
        {1,len_send_time,get_now_time()},
        {1,len_message,message}
    });
}

table messages_table::search_by_receiver(const table &receiver) {
    return _table.select(2,{1,len_receiver_uid,receiver.get_item(0,0).get_string()},db_type_equal);
}

table messages_table::search_by_sender(const table &sender) {
    return _table.select(1,{1,len_sender_uid,sender.get_item(0,0).get_string()},db_type_equal);
}

