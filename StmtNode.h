#ifndef STMTNODE_H
#define STMTNODE_H

#include "cAstNode.h"

class StmtNode : public cAstNode
{
    public:
        virtual string toString() = 0;
};
#endif