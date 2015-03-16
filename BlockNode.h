/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To print the string for declaring a
 *          block.
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
            string temp = "BLOCK: size: " + std::to_string(mSize) + "\n{\n";
            
            if (mDecls != nullptr)
                temp += mDecls->toString() + ' ' + mStmts->toString();
            else
                temp += mStmts->toString();
                
            temp += "\n}";
            
            return temp;
        }
        int ComputeOffsets(int base)
        {
            int offset = base;
            
            //if (offset % WORD_SIZE != 0)
            //    offset += WORD_SIZE - (offset % WORD_SIZE);
            
            if (mDecls != nullptr)
                offset = mDecls->ComputeOffsets(offset);
                
            if (mStmts != nullptr)
                offset = mStmts->ComputeOffsets(offset);
            
            mSize = offset - base;
            
            return base;
        }
        void GenerateCode()
        {
            // if (mDecls != nullptr)
            //     mDecls->GenerateCode();
            
            if (mStmts != nullptr)
                mStmts->GenerateCode();
        }
  
    private:
        int mSize;
        DeclsNode * mDecls;
        StmtsNode * mStmts;
};
#endif