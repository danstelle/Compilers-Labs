/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Properties of a parameter for a
 *          function
 ***********************************************/
#ifndef PARAMNODE_H
#define PARAMNODE_H

#include "ExprNode.h"

class ParamNode
{
    public:
        ParamNode(ExprNode * expr) : mExpr(expr)
        {}
        virtual string toString()
        {
            return mExpr->toString();
        }
        int ComputeOffsets(int base)
        {
            mExpr->ComputeOffsets(base);
            
            return base;
        }
    
    private:
        ExprNode * mExpr;
};
#endif