#ifndef STRUCTDECL_H
#define STRUCTDECL_H

#include "DeclsNode.h"
#include "DeclNode.h"
#include "cSymbol.h"
#include <map>

class StructDecl : public DeclNode
{
    public:
        StructDecl(DeclsNode * decl, cSymbol * ID)
            : mSymbols(nullptr), mDecl(decl), mID(ID)
        {}
        virtual string toString()
        {
            return "STRUCT: " + mDecl->toString() + ' ' + mID->toString();
        }
    
    private:
        map<string, cSymbol*> * mSymbols;
        DeclsNode * mDecl;
        cSymbol * mID;
};
#endif