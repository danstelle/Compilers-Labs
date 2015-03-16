/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: StmtNode that manages while loops
 ***********************************************/
#ifndef WHILENODE_H
#define WHILENODE_H

#include <string>
#include "StmtNode.h"

using std::string;

class WhileNode : public StmtNode
{
    public:
        WhileNode(ExprNode * val, StmtNode * stmt)
            : mValue(val), mStmt(stmt)
        {}
        virtual string toString()
        {
            return "(WHILE: " + mValue->toString() + '\n' + mStmt->toString() + "\n)";
        }
        int ComputeOffsets(int base)
        {
            mValue->ComputeOffsets(base);
            mStmt->ComputeOffsets(base);
            
            return base;
        }
        void GenerateCode()
        {
            EmitString("while (");
            mValue->GenerateCode();
            EmitString(")\n{\n");
            mStmt->GenerateCode();
            EmitString("}\n");
        }
    
    private:
        ExprNode * mValue;
        StmtNode * mStmt;
};
#endif