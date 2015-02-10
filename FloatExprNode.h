#ifndef FLOATEXPRNODE_H
#define FLOATEXPRNODE_H

#include "ExprNode.h"
#include <string>

using std::string;

class FloatExprNode : public ExprNode
{
    public:
        FloatExprNode(float value) : mValue(value)
        {}
        virtual string toString()
        {
            return "(EXPR: " + std::to_string(mValue) + ")";
        }
    
    private:
        float mValue;
};
#endif