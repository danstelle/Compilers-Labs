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
            mParameters.push_back(parameter);
        }
        int ComputeOffsets(int base)
        {
            list<ParamNode*>::iterator it = mParameters.begin();
            
            for (; it != mParameters.end(); it++)
                (*it)->ComputeOffsets(base);
                
            return base;
        }
    
    private:
        list<ParamNode*> mParameters;
};
#endif