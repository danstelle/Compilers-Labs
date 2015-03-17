/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Statement node that manages return
 *          statments in functions
 ***********************************************/
#ifndef RETURNNODE_H
#define RETURNNODE_H

#include <string>
#include "StmtNode.h"

using std::string;

class ReturnNode : public StmtNode
{
    public:
        ReturnNode(ExprNode * val) : mValue(val)
        {}
        virtual string toString()
        {
            return "RETURN: " + mValue->toString();
        }
        int ComputeOffsets(int base)
        {
            mValue->ComputeOffsets(base);
            
            return base;
        }
        void GenerateCode()
        {
            if (mValue->GetType()->IsFloat())
            {
                EmitString("Temp_F = ");
                mValue->GenerateCode();
                EmitString(";\n");
            }
            else
            {
                EmitString("Temp = ");
                mValue->GenerateCode();
                EmitString(";\n");
            }
        }
    
    private:
        ExprNode * mValue;
};
#endif