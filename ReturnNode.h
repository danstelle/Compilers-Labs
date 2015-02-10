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
    
    private:
        ExprNode * mValue;
};
#endif