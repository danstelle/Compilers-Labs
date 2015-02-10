#ifndef FUNCHEADER_H
#define FUNCHEADER_H

#include "FuncPrefix.h"
#include "ParamsSpec.h"
#include <string>

using std::string;

class FuncHeader
{
    public:
        FuncHeader(FuncPrefix * prefix, ParamsSpec * parameters)
            : mPrefix(prefix), mParameters(parameters)
        {}
        virtual string toString()
        {
            string temp = mPrefix->toString();
            
            if (mParameters != nullptr)
                temp += ' ' + mParameters->toString();
            else
                temp += "()";
                
            return temp;
        }
    
    private:
        FuncPrefix * mPrefix;
        ParamsSpec * mParameters;
};
#endif