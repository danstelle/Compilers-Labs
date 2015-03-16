/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Expression node that manages float
 *          types
 ***********************************************/
#ifndef FLOATEXPRNODE_H
#define FLOATEXPRNODE_H

#include "ExprNode.h"
#include "DeclNode.h"
#include <string>

using std::string;

extern cSymbolTable * symbolTableRoot;

class FloatExprNode : public ExprNode
{
    public:
        FloatExprNode(float value) : mValue(value)
        {}
        virtual string toString()
        {
            return "(EXPR: " + std::to_string(mValue) + ")";
        }
        DeclNode * GetType()
        {
            return symbolTableRoot->FullLookup("float")->GetType();
        }
        string GetName()
        {
            return "float";
        }
        void GenerateCode()
        {
            EmitFloat(mValue);
        }
    
    private:
        float mValue;
};
#endif