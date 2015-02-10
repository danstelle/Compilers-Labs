#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include "StmtNode.h"
#include "ExprNode.h"
#include "VarRef.h"

class AssignNode : public StmtNode
{
    public:
        AssignNode(VarRef * left, ExprNode * right)
            : mLeft(left), mRight(right)
        {}
        virtual string toString()
        {
            return "(ASSIGN: " + mLeft->toString() + " = " + mRight->toString() + ")";
        }
        
    private:
        VarRef * mLeft;
        ExprNode * mRight;
};
#endif