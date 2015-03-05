/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Function definitions for cSymbolTable
 ***********************************************/
#include "cSymbolTable.h"

cSymbolTable::cSymbolTable()
{
    cSymbol * character = new cSymbol("char", true);
    cSymbol * integer = new cSymbol("int", true);
    cSymbol * floating = new cSymbol("float", true);
    
    IncreaseScope();
    
    Insert(character);
    Insert(integer);
    Insert(floating);
    
    character->SetType(new BaseDeclNode(character, 1, false));
    integer->SetType(new BaseDeclNode(integer, 4, false));
    floating->SetType(new BaseDeclNode(floating, 8, true));
}

cSymbol * cSymbolTable::Insert(string in)
{
    cSymbol * temp = CurLookup(in);
    
    if (temp != nullptr)
        return temp;
    else
    {
        temp = new cSymbol(in);
        mScope.front()->insert(std::pair<string, cSymbol*>(in, temp));
        
        return temp;
    }
    
}

cSymbol * cSymbolTable::Insert(cSymbol * in)
{
    map<string,cSymbol*>::iterator it = mScope.front()->find(in->GetName());
    
    if(it != mScope.front()->end())
    {
        in = it->second;
    }
    else
    {
        if(FullLookup(in->GetName()) == in)
            in = Insert(in->GetName());
        else
            mScope.front()->insert(std::pair<string, cSymbol*>(in->GetName(), in));
    }
    
    return in;
}

cSymbol * cSymbolTable::FullLookup(string sym)
{
    list<map<string,cSymbol*>*>::iterator it;
    
    for(it = mScope.begin(); it != mScope.end(); ++it)
    {
        map<string,cSymbol*>::iterator symbol = (*it)->find(sym);
        
        if(symbol != (*it)->end())
            return symbol->second;
    }
    
    return nullptr;
}

cSymbol * cSymbolTable::CurLookup(string sym)
{
    map<string, cSymbol *>::const_iterator it = mScope.front()->find(sym);
    
    if (it == mScope.front()->end())
        return nullptr;
    else
        return it->second;
}

map<string,cSymbol*>* cSymbolTable::IncreaseScope()
{
    map<string, cSymbol*>* newTable = new map<string,cSymbol*>();
    mScope.push_front(newTable);
    return newTable;
}

void cSymbolTable::DecreaseScope()
{
    mScope.pop_front();
}

cSymbolTable::~cSymbolTable()
{}