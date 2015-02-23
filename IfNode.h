/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Statment node that manages if statements
 ***********************************************/
#ifndef IFNODE_H
#define IFNODE_H

#include <string>
#include "StmtNode.h"

using std::string;

class IfNode : public StmtNode
{
    public:
        IfNode(ExprNode * val, StmtNode * stmt1, StmtNode * stmt2)
            : mValue(val), mStmt1(stmt1), mStmt2(stmt2)
        {}
        virtual string toString()
        {
            string temp = "(IF: " + mValue->toString() + "\n" + mStmt1->toString() + "\n";
            
            if (mStmt2 != nullptr)
                temp += "ELSE:\n" + mStmt2->toString() + "\n";
                
            temp += ")";
            
            return temp;
        }
    
    private:
        ExprNode * mValue;
        StmtNode * mStmt1;
        StmtNode * mStmt2;
};
#endif