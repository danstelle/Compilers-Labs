#ifndef BASEDECLNODE_H
#define BASEDECLNODE_H

#include "DeclNode.h"
#include "cSymbol.h"

class BaseDeclNode : public DeclNode
{
    public:
        BaseDeclNode(int size, bool isFloat) : mSize(size), mIsFloat(isFloat)
        {}
        virtual string toString()
        {
            return "Found a BaseDeclNode";
        }
        virtual bool IsInt()
        {
            return !mIsFloat;
        }
        virtual bool IsFloat()
        {
            return mIsFloat;
        }
        virtual bool IsType()
        {
            return true;
        }
        int GetSize()
        {
            return mSize;
        }
        
    protected:
        int mSize;
        bool mIsFloat;
};
#endif