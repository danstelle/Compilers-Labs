/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: The base node for most decl nodes
 ***********************************************/
#ifndef BASEDECLNODE_H
#define BASEDECLNODE_H

#include "DeclNode.h"
#include "cSymbol.h"

class BaseDeclNode : public DeclNode
{
    public:
        BaseDeclNode(cSymbol * sym, int size, bool isFloat)
            : mSym(sym), mSize(size), mIsFloat(isFloat)
        {}
        virtual string toString()
        {
            return "Found a BaseDeclNode";
        }
        virtual bool IsInt()
        {
            return !mIsFloat;
        }
        virtual bool IsFloat()
        {
            return mIsFloat;
        }
        virtual bool IsType()
        {
            return true;
        }
        int GetSize()
        {
            return mSize;
        }
        string GetName()
        {
            return mSym->GetName();
        }
        
    protected:
        int mSize;
        bool mIsFloat;
        cSymbol * mSym;
};
#endif