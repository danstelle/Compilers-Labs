/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Properties of a function declaration
 ***********************************************/
#ifndef FUNCDECL_H
#define FUNCDECL_H

#include "DeclNode.h"
#include "FuncHeader.h"
#include "DeclsNode.h"
#include "StmtsNode.h"

class FuncDecl : public DeclNode
{
    public:
        FuncDecl(FuncHeader * header, DeclsNode * decls, StmtsNode * stmts)
            : mHeader(header), mDecls(decls), mStmts(stmts)
        {}
        virtual string toString()
        {
            string temp = "(FUNC: " + mHeader->toString();
            
            if (mDecls != nullptr)
                temp += mDecls->toString();
            
            if (mStmts != nullptr)
                temp += mStmts->toString();
                
            temp += "\n)";
            
            return temp;
        }
    
    private:
        FuncHeader * mHeader;
        DeclsNode * mDecls;
        StmtsNode * mStmts;
};
#endif