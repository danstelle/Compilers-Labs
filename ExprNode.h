#ifndef EXPRNODE_H
#define EXPRNODE_H

#include <string>
#include "DeclNode.h"
#include "cAstNode.h"

using std::string;

class ExprNode : public cAstNode
{
    public:
        virtual string toString() = 0;
        virtual DeclNode * GetType() = 0;
};
#endif