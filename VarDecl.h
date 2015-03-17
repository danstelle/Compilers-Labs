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
            : mType(type), mSym(sym), mSize(-1)
        {}
        virtual string toString()
        {
            return "VAR: " + mType->toString() + ' ' + mSym->toString()
                + " size: " + std::to_string(mSize) + " offset: " + std::to_string(mOffset);
        }
        int GetSize()
        {
            return mSize;
        }
        bool IsFloat()
        {
            if (mType->GetName() == "float")
                return true;
            else
                return false;
        }
        string GetName()
        {
            return mType->GetName();
        }
        int ComputeOffsets(int base)
        {
            int offset = base;
            
            if (mType)
            if (offset % WORD_SIZE != 0)
                offset += WORD_SIZE - (offset % WORD_SIZE);
            
            mSize = mType->GetType()->GetSize();
            mOffset = offset;
            
            return offset + mSize;
        }
        int GetOffset()
        {
            return mOffset;
        }
        DeclNode * GetType()
        {
            return mType->GetType();
        }
        
    private:
        int mSize;
        int mOffset;
        cSymbol * mType;
        cSymbol * mSym;
};
#endif