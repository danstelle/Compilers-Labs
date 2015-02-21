#ifndef STRUCTDECL_H
#define STRUCTDECL_H

#include "DeclsNode.h"
#include "DeclNode.h"
#include "cSymbol.h"
#include <map>
using std::map;

class StructDecl : public DeclNode
{
    public:
        StructDecl(map<string,cSymbol*>* symTable, DeclsNode * decl, cSymbol * ID)
            : mSymbols(symTable), mDecl(decl), mID(ID)
        {}
        virtual string toString()
        {
            return "STRUCT: " + mDecl->toString() + ' ' + mID->toString();
        }
        int GetSize()
        {
            return 28;
        }
        cSymbol* Find(string symbol)
        {
            cSymbol* sym = nullptr;
           
            if(mSymbols != nullptr)
            {
                map<string,cSymbol*>::iterator it = mSymbols->find(symbol);
                if(it != mSymbols->end())
                    sym = it->second;
            }
            return sym;
        }
        bool IsStruct()
        {
            return true;
        }
    
    private:
        map<string, cSymbol*> * mSymbols;
        DeclsNode * mDecl;
        cSymbol * mID;
};
#endif