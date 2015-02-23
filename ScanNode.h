/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Statment node that manages scan calls
 ***********************************************/
#ifndef SCANNODE_H
#define SCANNODE_H

#include <string>
#include "StmtNode.h"

using std::string;

class ScanNode : public StmtNode
{
    public:
        ScanNode(ExprNode * val) : mValue(val)
        {}
        virtual string toString()
        {
            return "SCAN: " + mValue->toString();
        }
    
    private:
        ExprNode * mValue;
};
#endif