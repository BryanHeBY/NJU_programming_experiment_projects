//
// Created by hby on 2021/4/29.
//

#include "DCol.h"
#include <cstring>

DColIndex::DColIndex(short tIndex, int cIndex):DObject(23),_TIndex(tIndex),_CIndex(cIndex) {}

DCol::DCol(short tIndex, int cIndex,const char *name):DObject(24),_index(tIndex,cIndex){
    strcpy(_name,name);
}

DColInter::DColInter(const vector<DTable *> &tables):_tables(tables){
    _index=0;
    _end=1;
    for(auto i:_tables)_end*=i->_table.size();
}

bool DColInter::is_end() {return _index==_end;}
void DColInter::operator++() {_index++;}
const DData &DColInter::get(const DColIndex &dColIndex) {return _tables[dColIndex._TIndex]->_table[get_col(dColIndex._TIndex)][dColIndex._CIndex];}
int DColInter::get_col(int tIndex) {
    int t=_index;
    for(int i=_tables.size()-1;i>tIndex;i--)t/=_tables[i]->_table.size();
    return t%_tables[tIndex]->_table.size();
}
