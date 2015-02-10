#ifndef VARREF_H
#define VARREF_H

#include "ExprNode.h"
#include "VarPart.h"
#include <string>

using std::string;

class VarRef : public ExprNode
{
    public:
        VarRef()
        {}
        virtual string toString()
        {
            string temp = "";
            
            list<VarPart*>::const_iterator it = mParts.begin();
            
            for (; it != mParts.end(); it++)
            {
                temp += "(VarRef: " + (*it)->toString();
                
                if (it != mParts.begin())
                    temp += ')';
                else if (mParts.size() > 1)
                    temp += '\n';
            }
            
            temp += ")";
            
            return temp;
        }
        void AddNode(VarPart * part)
        {
            mParts.push_back(part);
        }
        
    private:
        list<VarPart*> mParts;
};
#endif