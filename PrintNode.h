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
    
    private:
        ExprNode * mValue;
};
#endif