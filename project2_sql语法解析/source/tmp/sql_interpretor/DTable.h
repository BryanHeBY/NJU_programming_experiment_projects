//
// Created by hby on 2021/4/23.
//

#ifndef SQL_INTERPRETOR_DTABLE_H
#define SQL_INTERPRETOR_DTABLE_H
#include "DObject.h"
#include <vector>
#include <set>

using namespace std;
class DTable;
class DExpr;
const int MAX_NAME_SIZE=20;
struct DVarDeclare{
    short type_id,size;
    char name[MAX_NAME_SIZE];
    bool not_null,primary_key,auto_increment;
    DVarDeclare();
    DVarDeclare(short _type_id,short _size,const char *_name="",bool _not_null=0,bool _primary_key=0,bool _auto_increment=0);
};
ostream &operator << (ostream &os,const DVarDeclare &var);
struct row_less;
struct cmp_pair_less;
struct row_eq;
struct row_same;

class DTRow : public DObject{
private:
    vector<DData> _row;
public:
    DTRow(const DTable &table,ifstream &ifs);
    DTRow(const vector<DData> &row);
    void write_file(ofstream &ofs);
    ~DTRow()=default;
    friend row_less;
    friend row_eq;
    friend row_same;
    friend cmp_pair_less;
    friend DTable;
    const DData &operator [] (int index)const;
    friend ostream &operator<<(ostream &os,const DTable &table);
};

struct cmp_pair_less{
    cmp_pair_less()=default;
    bool operator() (const pair<DTRow,DData> &a,const pair<DTRow,DData> &b);
};

struct row_less{
    int compare_key;
    row_less(int key);
    bool operator() (const DTRow &a,const DTRow &b);
};

struct row_eq{
    int compare_key;
    row_eq(int key);
    bool operator() (const DTRow &a,const DTRow &b);
};

struct row_same{
    row_same()=default;
    bool operator() (const pair<DTRow,DData> &a,const pair<DTRow,DData> &b);
};

struct row_order{
    bool desc;
    row_order(int _desc);
    bool operator() (const pair<DTRow,DData> &a,const pair<DTRow,DData> &b);
};

class DCol;

vector<DCol> gen_all(const vector<DTable *> &tables);
vector<DVarDeclare> gen_varsDeclare(const vector<DCol> &dCols,const vector<DTable *> &tables);

struct DColInter;
struct DColIndex;
DTable SELECT(const string &name,bool distinct,const vector<DCol> &dCols, const vector<DTable *> &tables,const DExpr &where,const DColIndex &OrderBy,bool desc,int limit_num);

class DTable: public DObject{
private:
    char _name[MAX_NAME_SIZE];
    short _vars_num,_primary_key;
    int _counter;
    vector<DVarDeclare> _varsDeclare;
    vector<DTRow> _table;
    bool has_changed;
public:
    DTable(const string &str,const vector<DVarDeclare> &varClaim);
    DTable(const char *f_src);
    ~DTable()=default;
    const string name()const;
    void write_file(const char *f_src);
    friend DTRow;
    friend DTable SELECT(const string &name,bool distinct,const vector<DCol> &dCols, const vector<DTable *> &tables,const DExpr &where,const DColIndex &OrderBy,bool desc,int limit_num);
    void INSERT(vector<DData> values);
    void DELETE(const DExpr &where);
    void UPDATE(vector<pair<DColIndex,DExpr*>> &update_list,const DExpr &where);
    friend DColInter;
    const DTRow &operator[](int index)const;
    const vector<DTRow> &table()const;
    const vector<DVarDeclare> &varsDeclare();
    friend ostream &operator<<(ostream &os,const DTable &table);
    const int changed();
    void print_table_info(ostream &os);
    int primary_key();
};




#endif //SQL_INTERPRETOR_DTABLE_H
