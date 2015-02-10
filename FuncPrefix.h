#ifndef FUNCPREFIX_H
#define FUNCPREFIX_H

#include "cSymbol.h"
#include "ParamsNode.h"
#include <string>

using std::string;

class FuncPrefix
{
    public:
        FuncPrefix(cSymbol * typeID, cSymbol * ID)
            : mTypeID(typeID), mID(ID)
        {}
        virtual string toString()
        {
            return mID->toString();
        }
    
    private:
        cSymbol * mTypeID;
        cSymbol * mID;
};
#endif