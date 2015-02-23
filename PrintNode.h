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
    
    private:
        ExprNode * mValue;
};
#endif