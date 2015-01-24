#include "cSymbolTable.h"



cSymbolTable::cSymbolTable()
{
}

cSymbol* cSymbolTable::Insert(string in)
{
    cSymbol *retVal;
    map<string,cSymbol*>::iterator it = mScope.front()->find(in);
    
    if(it != mScope.front()->end())
        retVal = it->second;
    else
    {
        retVal = new cSymbol(in);
        mScope.front()->insert(std::pair<string, cSymbol*>(in, retVal));
    }
    
    return retVal;
}

void cSymbolTable::IncreaseScope()
{
    map <string, cSymbol *> * newTable = new map<string,cSymbol*>();
    mScope.push_front(newTable);
}

void cSymbolTable::DecreaseScope()
{
    mScope.pop_front();
}

cSymbolTable::~cSymbolTable()
{}