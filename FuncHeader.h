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
            string temp = "(FUNC: " + mPrefix->toString();
            
            if (mParameters != nullptr)
                temp += mParameters->toString();
            else
                temp += "()";
                
            temp += '\n';
            
            if (mDecls != nullptr)
                temp += mDecls->toString();
               
            temp += '\n';
                
            if (mStmts != nullptr)
                temp += mStmts->toString();
                
            temp += "\n size: " + std::to_string(mSize);
            
            temp += "\n)";
            
            return temp;
        }
        void SetParts(DeclsNode * decls, StmtsNode * stmts)
        {
            mStmts = stmts;
            mDecls = decls;
        }
        int GetSize()
        {
            return mSize;
        }
        string GetName()
        {
            return mPrefix->GetName();
        }
        int ComputeOffsets(int base)
        {
            int offset = 0;
            
            if (mParameters != nullptr)
                offset = mParameters->ComputeOffsets(offset);
                
            if (mDecls != nullptr)
                offset = mDecls->ComputeOffsets(offset);
                
            if (mStmts != nullptr)
                mStmts->ComputeOffsets(offset);
                
            mSize = mDecls->GetSize();
            
            return base;
        }
    
    private:
        int mSize;
        cSymbol * mPrefix;
        ParamsSpec * mParameters;
        StmtsNode * mStmts;
        DeclsNode * mDecls;
};
#endif