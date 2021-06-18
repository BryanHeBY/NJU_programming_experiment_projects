//
// Created by hby on 2021/4/29.
//

#ifndef SQL_INTERPRETOR_DEXPR_H
#define SQL_INTERPRETOR_DEXPR_H
#include "DTable.h"
#include "DFunc.h"
#include <stack>

class DLPToken: public DFunc{
public:
    DLPToken();
};

class DRPToken: public DObject{
public:
    DRPToken();
};

class DExpr: public DObject{
private:
    vector<DObject *> _expr;
    stack<DObject *> _func;
public:
    DExpr();
    DExpr(const DExpr &other);
    ~DExpr();
    void clear_func(int low_func);
    void push(DObject *dObject);
    void end_expr();
    DData getValue(DColInter &colIter)const;
    DData getValue(const DTRow &row)const;
    int expr_size();
};

void getTrueExpr(DExpr &expr);

#endif //SQL_INTERPRETOR_DEXPR_H
