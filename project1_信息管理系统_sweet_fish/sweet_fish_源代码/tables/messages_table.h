//
// Created by hby on 2021/3/30.
//

#ifndef INF_MAN_MESSAGES_TABLE_H
#define INF_MAN_MESSAGES_TABLE_H
#include "base_table.h"
#include "users_table.h"
#include <time.h>

class messages_table: public base_table {
public:
    const static int len_lid=7,len_sender_uid=7,len_receiver_uid=7,len_send_time=20,len_message=300;
    const int var_size[5]={len_lid,len_sender_uid,len_receiver_uid,len_send_time,len_message};
    void create_table();
    messages_table();
    void send_message(users_table &Users,const table &sender,const string &receiver_uid,const string &message);
    table search_by_receiver(const table &receiver);
    table search_by_sender(const table &sender);
};


#endif //INF_MAN_MESSAGES_TABLE_H
