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
    
    private:
        float mValue;
};
#endif