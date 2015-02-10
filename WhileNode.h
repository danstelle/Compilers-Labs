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
    
    private:
        ExprNode * mValue;
        StmtNode * mStmt;
};
#endif