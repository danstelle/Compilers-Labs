/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Properties of a function header
 ***********************************************/
#ifndef FUNCHEADER_H
#define FUNCHEADER_H

#include "FuncPrefix.h"
#include "ParamsSpec.h"
#include "DeclsNode.h"
#include "DeclNode.h"
#include "StmtsNode.h"
#include <string>

using std::string;

class FuncHeader : public DeclNode
{
    public:
        FuncHeader(cSymbol * sym, ParamsSpec * parameters)
            : mPrefix(sym), mParameters(parameters)
        {}
        virtual string toString()
        {
            string temp = mPrefix->toString();
            
            if (mParameters != nullptr)
                temp += ' ' + mParameters->toString();
            else
                temp += "()";
                
            return temp;
        }
        void SetParts(DeclsNode * decls, StmtsNode * stmts)
        {
            mStmts = stmts;
            mDecls = decls;
        }
        int GetSize()
        {
            return -51;
        }
        string GetName()
        {
            return mPrefix->GetName();
        }
    
    private:
        cSymbol * mPrefix;
        ParamsSpec * mParameters;
        StmtsNode * mStmts;
        DeclsNode * mDecls;
};
#endif