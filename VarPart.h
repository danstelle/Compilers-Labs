#ifndef VARPART_H
#define VARPART_H

#include "ExprNode.h"
#include "cSymbol.h"
#include "ArrayVal.h"

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
    
    private:
        cSymbol * mSym;
        ArrayVal * mArray;
};
#endif