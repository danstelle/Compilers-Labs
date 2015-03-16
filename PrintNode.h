/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Statement node that manages things when
 *          print statements are made
 ***********************************************/
#ifndef PRINTNODE_H
#define PRINTNODE_H

#include <string>
#include "StmtNode.h"
#include "ExprNode.h"
#include "codegen.h"

using std::string;

class PrintNode : public StmtNode
{
    public:
        PrintNode(ExprNode * val) : mValue(val)
        {}
        virtual string toString()
        {
            return "PRINT: " + mValue->toString();
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
                EmitPrintTemp_F();
            }
            else
            {
                EmitString("Temp = ");
                mValue->GenerateCode();
                EmitString(";\n");
                EmitPrintTemp();
            }
        }
    
    private:
        ExprNode * mValue;
};
#endif