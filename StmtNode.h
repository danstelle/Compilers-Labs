/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Abstract base class for all StmtNodes
 ***********************************************/
#ifndef STMTNODE_H
#define STMTNODE_H

#include "cAstNode.h"

class StmtNode : public cAstNode
{
    public:
        virtual string toString() = 0;
};
#endif