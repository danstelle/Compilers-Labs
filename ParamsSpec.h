/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Specification for the list of paramters
 ***********************************************/
#ifndef PARAMSSPEC_H
#define PARAMSSPEC_H

#include "StmtNode.h"
#include "ParamSpec.h"
#include <list>

using std::list;

class ParamsSpec : public StmtNode
{
    public:
        ParamsSpec()
        {}
        virtual string toString()
        {
            string temp = "(PARAMS:";
            list<ParamSpec*>::const_iterator it;
            
            for (it = mParameters.begin(); it != mParameters.end(); it++)
                temp += ' ' + (*it)->toString();
                
            temp += ")\n";
            
            return temp;
        }
        void AddNode(ParamSpec * parameter)
        {
            mParameters.push_back(parameter);
        }
    
    private:
        list<ParamSpec*> mParameters;
};
#endif