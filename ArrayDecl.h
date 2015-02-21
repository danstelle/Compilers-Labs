/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To print the string for declaring an
 *          array.
 * 
 * Constructor: Initializes all the members
 * 
 * toString: Returns the string for declaring
 *           the array.
 ***********************************************/
#ifndef ARRAYDECL_H
#define ARRAYDECL_H

#include "DeclNode.h"
#include "ArraySpec.h"
#include "cSymbol.h"

class ArrayDecl : public DeclNode
{
    public:
        ArrayDecl(cSymbol * type, cSymbol * sym, ArraySpec * spec)
            : mType(type), mSym(sym), mSpec(spec)
        {}
        virtual string toString()
        {
            return "ARRAY: " + mType->toString() + ' ' + mSym->toString() + ' ' +mSpec->toString();
        }
        int GetSize()
        {
            return -17;
        }
    
    private:
        cSymbol * mType;
        cSymbol * mSym;
        ArraySpec * mSpec;
};
#endif