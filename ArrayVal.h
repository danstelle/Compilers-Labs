#ifndef ARRAYVAL_H
#define ARRAYVAL_H

#include "ExprNode.h"
#include <string>

using std::string;

class ArrayVal
{
    public:
        ArrayVal()
        {}
        virtual string toString()
        {
            string temp = "(ARRAYVAL:";
            list<ExprNode*>::const_iterator it;
            
            for (it = mVals.begin(); it != mVals.end(); it++)
                temp += ' ' + (*it)->toString();
                
            temp += ")\n";
            
            return temp;
        }
        void AddNode(ExprNode * val)
        {
            mVals.push_back(val);
        }
        
    private:
        list<ExprNode*> mVals;
};

#endif