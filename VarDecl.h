#ifndef VARDECL_H
#define VARDECL_H

#include "DeclNode.h"
/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Decl node that manages variable
 *          declarations
 ***********************************************/
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
        string GetName()
        {
            return mType->GetName();
        }
        
    private:
        cSymbol * mType;
        cSymbol * mSym;
};
#endif