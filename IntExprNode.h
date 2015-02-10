#ifndef INTEXPRNODE_H
#define INTEXPRNODE_H

#include "ExprNode.h"
#include <string>

using std::string;

class IntExprNode : public ExprNode
{
    public:
        IntExprNode(int value) : mValue(value)
        {}
        virtual string toString()
        {
            return "(EXPR: " + std::to_string(mValue) + ")";
        }
    
    private:
        int mValue;
};
#endif