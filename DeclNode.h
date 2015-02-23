/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Abstract class for the decl nodes
 ***********************************************/
#ifndef DECLNODE_H
#define DECLNODE_H

#include "cAstNode.h"
#include <string>

using std::string;

class DeclNode : public cAstNode
{
    public:
        //virtual string toString() = 0;
        virtual bool IsType()
        {
            return false;
        }
        virtual bool IsFunc()
        {
            return false;
        }
        virtual bool IsArray()
        {
            return false;
        }
        virtual bool IsFloat()
        {
            return false;
        }
        virtual bool IsInt()
        {
            return false;
        }
        virtual bool IsChar()
        {
            return false;
        }
        virtual bool IsStruct()
        {
            return false;
        }
        virtual string GetName() = 0;
        virtual int GetSize() = 0;
        //bool CompatibleWith(cDeclNode *right)
        //{
            
        //}
};
#endif