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
            return "(FUNC CALL: " + mID->toString() + mParameters->toString() + ")\n";
        }
        DeclNode * GetType()
        {
            return mID->GetType();
        }
        string GetName()
        {
            return mID->GetName();
        }
    
    private:
        cSymbol * mID;
        ParamsNode * mParameters;
};
#endif