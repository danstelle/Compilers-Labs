#ifndef BINARYEXPRNODE_H
#define BINARYEXPRNODE_H

#include "ExprNode.h"
#include <string>

using std::string;

class BinaryExprNode : public ExprNode
{
    public:
        BinaryExprNode(ExprNode * expr1, char op, ExprNode * expr2)
            : mExpr1(expr1), mExpr2(expr2), mOp(op)
        {}
        virtual string toString()
        {
           return "(EXPR: " + mExpr1->toString() + " " + mOp + " " + mExpr2->toString() + ")";
        }
    
    private:
        ExprNode * mExpr1;
        ExprNode * mExpr2;
        char mOp;
};
#endif