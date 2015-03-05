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
    
    private:
        ExprNode * mValue;
};
#endif