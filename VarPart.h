#ifndef VARPART_H
#define VARPART_H

#include "ExprNode.h"
#include "cSymbol.h"
#include "ArrayVal.h"

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
    
    private:
        cSymbol * mSym;
        ArrayVal * mArray;
};
#endif
// #ifndef VARPART_H
// #define VARPART_H

// #include "ExprNode.h"
// #include "cSymbol.h"
// #include "ArrayVal.h"

// extern cSymbolTable * symbolTableRoot;

// class VarPart : public ExprNode
// {
//     public:
//         VarPart(cSymbol * sym, ArrayVal * ary)
//             : mSym(sym), mArray(ary)
//         {}
//         virtual string toString()
//         {
//             string temp = mSym->toString();
            
//             if (mArray != nullptr)
//                 temp += '[' + mArray->toString() + ']';
                
//             return temp;
//         }
//         DeclNode * GetType()
//         {
//             return mSym->GetType();
//         }
//         cSymbol * GetSym()
//         {
//             return mSym;
//         }
//         void SetSym(cSymbol * sym)
//         {
//             mSym = sym;
//         }
    
//     private:
//         cSymbol * mSym;
//         ArrayVal * mArray;
// };
// #endif