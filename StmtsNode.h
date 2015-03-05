#ifndef STMTSNODE_H
#define STMTSNODE_H
/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Holds a list of stmt nodes
 ***********************************************/
#include <list>
#include <string>
#include "StmtNode.h"
#include "cAstNode.h"

using std::list;
using std::string;

class StmtsNode : cAstNode
{
    public:
        StmtsNode()
        {}
        virtual string toString()
        {
            string temp = "STMTS: \n{\n";
            list<StmtNode*>::const_iterator it;
            
            for (it = mStmtList.begin(); it != mStmtList.end(); it++)
                temp += (*it)->toString() + '\n';
            
            temp += "}";
            
            return temp;
        }
        void AddNode(StmtNode * node)
        {
            mStmtList.push_back(node);
        }
        int ComputeOffsets(int base)
        {
            int offset = base;
            list<StmtNode*>::iterator it;
            
            for (it = mStmtList.begin(); it != mStmtList.end(); it++)
                offset = (*it)->ComputeOffsets(offset);
                
            mSize = offset - base;
            
            return offset;
        }
    
    private:
        list<StmtNode *> mStmtList;
        int mSize;
};
#endif