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
        cSymbol* Insert(string str);
        void IncreaseScope();
        void DecreaseScope();
        ~cSymbolTable();
    
    private:
        list<map<string,cSymbol*>*> mScope;
};
#endif