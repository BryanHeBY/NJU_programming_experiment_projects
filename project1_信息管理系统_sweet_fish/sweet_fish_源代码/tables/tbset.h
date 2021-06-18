#ifndef TBSET_H
#define TBSET_H
#include "users_table.h"
#include "merchandises_table.h"
#include "order_form_table.h"
#include "messages_table.h"

class TBSet
{
public:
    TBSet();
    users_table Users;
    merchandises_table Merchandises;
    order_form_table OrderForm;
    messages_table Messages;
};

#endif // TBSET_H
