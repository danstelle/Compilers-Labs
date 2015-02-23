/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Decl node that manages structs
 ***********************************************/
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
            if (mSymbols != nullptr)
            {
                map<string,cSymbol*>::iterator it = mSymbols->find(symbol);
                
                if (it != mSymbols->end())
                {
                    //std::cout << "Thing: " << it->second->GetName() << std::endl;
                    return it->second;
                }
            }
            
            return nullptr;
        }
        bool IsStruct()
        {
            return true;
        }
        string GetName()
        {
            return mID->GetName();
        }
    
    private:
        map<string, cSymbol*> * mSymbols;
        DeclsNode * mDecl;
        cSymbol * mID;
};
#endif