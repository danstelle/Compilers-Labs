/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Properties of a function header
 ***********************************************/
#ifndef FUNCHEADER_H
#define FUNCHEADER_H

#include "FuncPrefix.h"
#include "ParamsSpec.h"
#include "DeclsNode.h"
#include "DeclNode.h"
#include "StmtsNode.h"
#include <string>

using std::string;

class FuncHeader : public DeclNode
{
    public:
        FuncHeader(cSymbol * sym, ParamsSpec * parameters)
            : mPrefix(sym), mParameters(parameters), mSize(-1)
        {}
        virtual string toString()
        {
            string temp = "(FUNC: " + mPrefix->toString();
            
            if (mParameters != nullptr)
                temp += mParameters->toString();
            else
                temp += "()";
                
            temp += '\n';
            
            if (mDecls != nullptr)
                temp += mDecls->toString();
               
            temp += '\n';
                
            if (mStmts != nullptr)
                temp += mStmts->toString();
                
            temp += "\n size: " + std::to_string(mSize);
            
            temp += "\n)";
            
            return temp;
        }
        void SetParts(DeclsNode * decls, StmtsNode * stmts)
        {
            mStmts = stmts;
            mDecls = decls;
        }
        int GetSize()
        {
            return mSize;
        }
        string GetName()
        {
            return mPrefix->GetName();
        }
        int ComputeOffsets(int base)
        {
            int offset = 0;
            
            if (mParameters != nullptr)
                offset = mParameters->ComputeOffsets(offset);
                
            if (mDecls != nullptr)
                offset = mDecls->ComputeOffsets(offset);
                
            if (mStmts != nullptr)
                mStmts->ComputeOffsets(offset);
            
            if (mDecls != nullptr)    
                mSize = mDecls->GetSize();
            
            return base;
        }
        void GenerateCode()
        {
            StartFunctionOutput();
            EmitString(mPrefix->GetName() + '_' + std::to_string(mPrefix->GetSequence()) + "()\n{\n");
            
            //if (mParameters != nullptr)
            //    mParameters->GenerateCode();
                
            if (mDecls != nullptr)
                EmitString("Stack_Pointer += " + std::to_string(mSize) + ";\n");
                
            if (mStmts != nullptr)
                mStmts->GenerateCode();
                
            EmitString("Stack_Pointer = Frame_Pointer;\n");
            EmitString("Stack_Pointer -= 4;\n");
            EmitString("Frame_Pointer = (*(int *)(&Memory[(Stack_Pointer)]));\n");
            
            EmitString("}\n");
            EndFunctionOutput();
        }
        bool IsFunc()
        {
            return true;
        }
    
    private:
        int mSize;
        cSymbol * mPrefix;
        ParamsSpec * mParameters;
        StmtsNode * mStmts;
        DeclsNode * mDecls;
};
#endif