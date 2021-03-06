/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Specification for parameters
 ***********************************************/
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
        VarDecl * GetDecl()
        {
            return mDecl;
        }
    
    private:
        VarDecl * mDecl;
};
#endif