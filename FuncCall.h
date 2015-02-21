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
    
    private:
        cSymbol * mID;
        ParamsNode * mParameters;
};
#endif