#ifndef VARDECL_H
#define VARDECL_H

#include "DeclNode.h"
#include "ArraySpec.h"
#include <string>

using std::string;

class VarDecl : public DeclNode
{
    public:
        VarDecl(cSymbol * type, cSymbol * sym, ArraySpec * spec)
            : mType(type), mSym(sym), mSpec(spec)
        {}
        virtual string toString()
        {
            string ret = "VAR: " + mType->toString() + ' ' + mSym->toString(); //+ ' ' + mSpec->toString();
            if(mSpec != nullptr)
                ret += mSpec->toString();
            
            return ret;
        }
        
    private:
        cSymbol * mType;
        cSymbol * mSym;
        ArraySpec * mSpec;
};
#endif