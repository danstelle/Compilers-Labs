/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Holds the list of parameters for a
 *          function
 ***********************************************/
#ifndef PARAMSNODE_H
#define PARAMSNODE_H

#include "ParamNode.h"
#include "StmtNode.h"

class ParamsNode : public StmtNode
{
    public:
        ParamsNode()
        {}
        virtual string toString()
        {
            string temp = "(PARAM:";
            list<ParamNode*>::const_iterator it;
            
            for (it = mParameters.begin(); it != mParameters.end(); it++)
                temp += (*it)->toString() + ' ';
                
            temp += ")\n";
            
            return temp;
        }
        void AddNode(ParamNode * parameter)
        {
            if (parameter != nullptr)
                mParameters.push_back(parameter);
        }
        int GetSize()
        {
            return mSize;
        }
        int ComputeOffsets(int base)
        {
            int offset = 0;
            list<ParamNode*>::iterator it = mParameters.begin();
            
            for (; it != mParameters.end(); it++)
                offset = (*it)->ComputeOffsets(offset);
                
            mSize = offset;
                
            return base;
        }
        void GenerateCode()
        {
            list<ParamNode*>::iterator it = mParameters.begin();
            
            for (; it != mParameters.end(); it++)
                (*it)->GenerateCode();
        }
    
    private:
        int mSize;
        list<ParamNode*> mParameters;
};
#endif