/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To be the root node for all nodes
 *          and require a toString function
 *          for all nodes.
 ***********************************************/
#ifndef CASTNODE_H
#define CASTNODE_H

#include <string>

using std::string;

class cAstNode
{
    public:
        virtual string toString() = 0;
        virtual void GenerateCode()
        {}
        virtual bool SemanticError()
        {
            return mIsError;
        }
        virtual string GetErrorMessage()
        {
            return mErrorMsg;
        }
        virtual int ComputeOffsets(int base)
        {
            return base;
        }
        
    protected:
        int mBase;
        bool mIsError;
        string mErrorMsg;
        static const int WORD_SIZE = 4;
};
#endif