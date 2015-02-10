#ifndef DECLNODE_H
#define DECLNODE_H

#include <string>

using std::string;

class DeclNode
{
    public:
        virtual string toString() = 0;
};
#endif