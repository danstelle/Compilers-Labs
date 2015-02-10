#ifndef CASTNODE_H
#define CASTNODE_H

#include <string>

using std::string;

class cAstNode
{
    public:
        virtual string toString() = 0;
};
#endif