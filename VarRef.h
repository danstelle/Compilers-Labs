/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Manages when a variable is referenced
 ***********************************************/
#ifndef VARREF_H
#define VARREF_H

#include "ExprNode.h"
#include "VarPart.h"
#include "VarDecl.h"
#include "StructDecl.h"
#include <string>

using std::string;

extern cSymbolTable* symbolTableRoot;

class VarRef : public ExprNode
{
    public:
        VarRef()
        {}
        virtual string toString()
        {
            string temp = "";
            
            list<VarPart*>::const_iterator it = mParts.begin();
            
            for (; it != mParts.end(); it++)
                temp += "(VarRef: " + (*it)->toString() + ' ';
            
            for (int i = mParts.size() - 1; i != 0; i--)
                temp += ')';
            
            temp += "size: " + std::to_string(mSize) + " offset: " + std::to_string(mOffset);
            
            temp += ')';
            
            return temp;
        }
        void AddNode(VarPart * part)
        {
            mIsError = CheckValidity(part);
            
            if(!mIsError)
                mParts.push_back(part);
        }
        string GetName()
        {
            return mParts.back()->GetSym()->GetName();
        }
        DeclNode * GetType()
        {
            return mParts.back()->GetType();
        }
        bool CheckValidity(VarPart* symbol)
        {
            if(mParts.size() == 0)
            {
                if(!symbol->GetSym()->GetDeclared())
                {
                    mErrorMsg = "Symbol " + symbol->GetSym()->GetName() + " not defined";
                    return true;
                }
            }
            else
            {
                VarDecl* vdecl = dynamic_cast<VarDecl*>(mParts.back()->GetType());
                StructDecl* decl = dynamic_cast<StructDecl*>(vdecl->GetType());
                
                // If it was able to convert to a struct decl...
                if (decl != nullptr)
                {
                    // Find the symbol in the struct that it belongs to
                    cSymbol * sym = decl->Find(symbol->GetSym()->GetName());
                    
                    // If we find it in the struct...
                    if(sym != nullptr)
                    {
                        symbol->SetSym(sym);
                        symbol->SetField(sym->GetType());
                        return false; // No error
                    }
                    else // else, we didn't find the symbol in the struct, return the error
                    {
                        mErrorMsg = symbol->GetSym()->GetName() + " is not a field of ";
                        CreateErrMsg("");
                        
                        return true; // Error
                    }
                }
                else //Else decl was not a struct decl
                {
                    //mErrorMsg = mParts.back()->GetSym()->GetName() + " is not a struct";
                    CreateErrMsg(" is not a struct");
                    return true;
                }
            }
            
            //return true so compiler won't complain
            return false;
        }
        void CreateErrMsg(string end)
        {
            list<VarPart*>::const_iterator it = mParts.begin();
            int counter = mParts.size() - 1;
            
            // Iterate through list of parts displaying them
            while (it != mParts.end())
            {
                mErrorMsg += (*it)->GetSym()->GetName(); // Add to the error message
                
                it++; // Move iterator to the next VarPart
                
                // If the iterator has not displayed the last Varpart
                // add a '.' to differentiate between the different parts
                if (counter != 0)
                    mErrorMsg += '.';
                    
                counter--;
            }
            
            mErrorMsg += end;
        }
        int ComputeOffsets(int base)
        {
            //int offset = 0;
            list<VarPart*>::iterator it = mParts.begin();
            mOffset = dynamic_cast<VarDecl*>((*it)->GetSym()->GetType())->GetOffset();
            
            for (it++; it != mParts.end(); it++)
                mOffset += dynamic_cast<VarDecl*>((*it)->GetField())->GetOffset();
            
            for (it = mParts.begin(); it != mParts.end(); it++)
                mSize = dynamic_cast<VarDecl*>((*it)->GetSym()->GetType())->GetSize();
            
            return base;
        }
        void GenerateCode()
        {
            if (mParts.back()->GetType()->IsFloat())
                EmitString("(*(double *)(&Memory[(Frame_Pointer + " + std::to_string(mOffset) + ")]))");
            else
                EmitString("(*(int *)(&Memory[(Frame_Pointer + " + std::to_string(mOffset) + ")]))");
        }
        
    private:
        int mOffset;
        int mSize;
        list<VarPart*> mParts;
};
#endif