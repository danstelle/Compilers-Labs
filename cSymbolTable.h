#ifndef CSYMBOLTABLE_H
#define CSYMBOLTABLE_H

#include <iostream>
#include <list>
#include <map>
#include <string>
#include "cSymbol.h"

using std::list;
using std::map;
using std::string;

class cSymbolTable
{
    public:
        cSymbolTable();
        cSymbol * Insert(string str);
        cSymbol * Insert(cSymbol * in);
        cSymbol * FullLookup(string sym);
        cSymbol * CurLookup(string sym);
        void IncreaseScope();
        void DecreaseScope();
        ~cSymbolTable();
    
    private:
        list<map<string,cSymbol*>*> mScope;
};
#endif