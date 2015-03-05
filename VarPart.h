/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Manages each piece of a variable declaration
 *          and is a piece of structs
 ***********************************************/
#ifndef VARPART_H
#define VARPART_H

#include "ExprNode.h"
#include "cSymbol.h"
#include "DeclNode.h"
#include "ArrayVal.h"
#include "ArrayDecl.h"

extern cSymbolTable * symbolTableRoot;

class VarPart : public ExprNode
{
    public:
        VarPart(cSymbol * sym, ArrayVal * ary)
            : mSym(sym), mArray(ary)
        {}
        virtual string toString()
        {
            string temp = mSym->toString();
            
            if (mArray != nullptr)
                temp += '[' + mArray->toString() + ']';
                
            return temp;
        }
        DeclNode * GetType()
        {
            if (HasIndecies())
                return static_cast<ArrayDecl*>(mSym->GetType())->GetType();
            else
                return mSym->GetType();
        }
        cSymbol * GetSym()
        {
            return mSym;
        }
        void SetSym(cSymbol * sym)
        {
            mSym = sym;
        }
        void SetField(DeclNode * field)
        {
            mField = field;
        }
        DeclNode * GetField()
        {
            return mField;
        }
        string GetName()
        {
            return mSym->GetName();
        }
        bool HasIndecies()
        {
            if (mArray == nullptr)
                return false; // Does not have indecies
            else
                return true; // Has indecies
        }
    
    private:
        //DeclNode * mType;
        DeclNode * mField;
        cSymbol * mSym;
        ArrayVal * mArray;
};
#endif
