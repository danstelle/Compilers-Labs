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
            : mSymbols(symTable), mDecl(decl), mID(ID), mSize(-1)
        {}
        virtual string toString()
        {
            return "STRUCT: " + mDecl->toString() + ' ' + mID->toString()
                + " size: " + std::to_string(mSize);
        }
        int GetSize()
        {
            return mSize;
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
        int ComputeOffsets(int base)
        {
            mSize = mDecl->ComputeOffsets(0);
            return base;
        }
    
    private:
        map<string, cSymbol*> * mSymbols;
        DeclsNode * mDecl;
        cSymbol * mID;
        int mSize;
};
#endif