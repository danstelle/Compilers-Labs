/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To print the string for declaring a
 *          block.
 * 
 * Constructor: Initializes all the members
 * 
 * toString: Returns the string for declaring
 *           the block.
 ***********************************************/
#ifndef BLOCKNODE_H
#define BLOCKNODE_H

#include <string>
#include "StmtNode.h"
#include "StmtsNode.h"
#include "DeclsNode.h"
#include "cAstNode.h"

using std::string;

class BlockNode : public StmtNode
{
    public:
        BlockNode(DeclsNode * decl, StmtsNode * stmts) : mDecls(decl), mStmts(stmts)
        {}
        virtual string toString()
        {
            string temp = "BLOCK:\n{\n";
            
            if (mDecls != nullptr)
                temp += mDecls->toString() + ' ' + mStmts->toString();
            else
                temp += mStmts->toString();
                
            temp += "\n}";
            
            return temp;
        }
  
    private:
        DeclsNode * mDecls;
        StmtsNode * mStmts;
};
#endif