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
    
    private:
        list <DeclNode*> mDecls;
};
#endif