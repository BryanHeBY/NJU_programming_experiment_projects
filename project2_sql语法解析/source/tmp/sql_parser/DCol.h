//
// Created by hby on 2021/4/29.
//

#ifndef SQL_INTERPRETOR_DCOL_H
#define SQL_INTERPRETOR_DCOL_H
#include "DTable.h"
#include "DExpr.h"


class DColIndex: public DObject{
public:
    short _TIndex,_CIndex;
    DColIndex(short tIndex,int cIndex);
    ~DColIndex()=default;
};

class DCol: public DObject{
public:
    DColIndex _index;
    char _name[MAX_NAME_SIZE];
    DCol(short tIndex,int cIndex,const char *name);
    ~DCol()=default;
};

struct DColInter{
    vector<DTable *> _tables;
    int _index,_end;
    DColInter(const vector<DTable *> &tables);
    bool is_end();
    void operator ++();
    int get_col(int tIndex);
    const DData &get(const DColIndex &dColIndex);
};



#endif //SQL_INTERPRETOR_DCOL_H
