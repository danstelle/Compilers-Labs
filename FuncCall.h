/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Properties of a function call
 ***********************************************/
#ifndef FUNCCALL_H
#define FUNCCALL_H

#include "cSymbol.h"
#include "ParamsNode.h"
#include "StmtNode.h"
#include "ExprNode.h"

class FuncCall : public StmtNode, public ExprNode
{
    public:
        FuncCall(cSymbol * ID, ParamsNode * parameters)
            : mID(ID), mParameters(parameters)
        {}
        virtual string toString()
        {
            return "(FUNC CALL: " + mID->toString() + mParameters->toString() + ")";
        }
        DeclNode * GetType()
        {
            return mID->GetType();
        }
        string GetName()
        {
            return mID->GetName();
        }
        int ComputeOffsets(int base)
        {
            mParameters->ComputeOffsets(base);
            
            return base;
        }
    
    private:
        cSymbol * mID;
        ParamsNode * mParameters;
};
#endif