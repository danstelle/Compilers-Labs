#ifndef PARAMSPEC_H
#define PARAMSPEC_H

#include "VarDecl.h"
#include <string>

using std::string;

class ParamSpec
{
    public:
        ParamSpec(VarDecl * decl) : mDecl(decl)
        {}
        virtual string toString()
        {
            return mDecl->toString();
        }
    
    private:
        VarDecl * mDecl;
};
#endif