#ifndef EXPRNODE_H
#define EXPRNODE_H

#include <string>
#include "cAstNode.h"

using std::string;

class ExprNode : public cAstNode
{
    public:
        virtual string toString() = 0;
};
#endif