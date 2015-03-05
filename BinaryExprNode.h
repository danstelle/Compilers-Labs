/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To print the string for declaring a
 *          binary expression.
 ***********************************************/
#ifndef BINARYEXPRNODE_H
#define BINARYEXPRNODE_H

#include "ExprNode.h"
#include "DeclNode.h"
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
        DeclNode * GetType()
        {
            DeclNode * left = mExpr1->GetType();
            DeclNode * right = mExpr2->GetType();
            
            if (left == right || left->IsFloat())
                return left; // Return the float
            else if (right->IsFloat())
                return right; // Return the float
            else
            {
                if (left->GetSize() == 4)
                    return left; // Return the int
                else if (right->GetSize() == 4)
                    return right; // Return the int
                else
                    return left; // Both are chars so return either of them
            }
        }
        string GetName()
        {
            return "";
        }
        int ComputeOffsets(int base)
        {
            mExpr1->ComputeOffsets(base);
            mExpr2->ComputeOffsets(base);
            
            return base;
        }
    
    private:
        ExprNode * mExpr1;
        ExprNode * mExpr2;
        char mOp;
};
#endif