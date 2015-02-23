/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Expression node that manages integer
 *          types./
 ***********************************************/
#ifndef INTEXPRNODE_H
#define INTEXPRNODE_H

#include "ExprNode.h"
#include <string>

using std::string;

extern cSymbolTable * symbolTableRoot;

class IntExprNode : public ExprNode
{
    public:
        IntExprNode(int value) : mValue(value)
        {}
        virtual string toString()
        {
            return "(EXPR: " + std::to_string(mValue) + ")";
        }
        DeclNode * GetType()
        {
            if (mValue >= -128 && mValue < 128)
                return symbolTableRoot->FullLookup("char")->GetType();
            
            return symbolTableRoot->FullLookup("int")->GetType();
        }
        string GetName()
        {
            return "int";
        }
    
    private:
        int mValue;
};
#endif