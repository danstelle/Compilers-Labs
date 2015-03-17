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
            if (mParameters != nullptr)
                mParameters->ComputeOffsets(base);
            
            return base;
        }
        void GenerateCode()
        {
            EmitString("(*(int *)(&Memory[(Stack_Pointer)])) = Frame_Pointer;\n");
            EmitString("Stack_Pointer += 4;\n");
            
            if (mParameters != nullptr)
                mParameters->GenerateCode();
            
            EmitString("Frame_Pointer = Stack_Pointer - " + std::to_string(mParameters->GetSize()) + ";\n");
                
            EmitString(mID->GetName() + "_" + std::to_string(mID->GetSequence()) + "();\n");
        }
        bool IsFunc()
        {
            return true;
        }
    
    private:
        cSymbol * mID;
        ParamsNode * mParameters;
};
#endif