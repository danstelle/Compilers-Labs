#ifndef VARDECL_H
#define VARDECL_H

#include "DeclNode.h"
#include "cSymbol.h"
#include <string>

using std::string;

class VarDecl : public DeclNode
{
    public:
        VarDecl(cSymbol * type, cSymbol * sym)
            : mType(type), mSym(sym)
        {}
        virtual string toString()
        {
            return "VAR: " + mType->toString() + ' ' + mSym->toString();
        }
        int GetSize()
        {
            return -90;
        }
        
    private:
        cSymbol * mType;
        cSymbol * mSym;
};
#endif