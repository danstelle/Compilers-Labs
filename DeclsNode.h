#ifndef DECLSNODE_H
#define DECLSNODE_H


/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Holds a list of decl nodes
 ***********************************************/
#include "DeclNode.h"
#include <string>

using std::string;

class DeclsNode
{
    public:
        DeclsNode()
        {}
        virtual string toString()
        {
            string temp = "DECLS:\n{\n";
            list<DeclNode*>::const_iterator it = mDecls.begin();
            
            while (it != mDecls.end())
            {
                temp += (*it)->toString() + '\n';
                it++;
            }
            
            temp += "}\n";
            
            return temp;
        }
        void AddNode(DeclNode * nn)
        {
            mDecls.push_back(nn);
        }
        int GetSize()
        {
            return mSize;
        }
        virtual int ComputeOffsets(int base)
        {
            int offset = base;
            list<DeclNode*>::iterator it;
            
            for (it = mDecls.begin(); it != mDecls.end(); it++)
                offset = (*it)->ComputeOffsets(offset);
                
            mSize = offset - base;
            
            return offset;
        }
        virtual void GenerateCode()
        {
            list<DeclNode*>::iterator it;
            
            for (it = mDecls.begin(); it != mDecls.end(); it++)
                (*it)->GenerateCode();
        }
    
    private:
        int mSize;
        list <DeclNode*> mDecls;
};
#endif