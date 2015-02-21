#ifndef VARREF_H
#define VARREF_H

#include "ExprNode.h"
#include "VarPart.h"
#include "StructDecl.h"
#include <string>

using std::string;

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
            {
                temp += "(VarRef: " + (*it)->toString();
                
                //if (it != mParts.begin())
                //    temp += ')';
                //else if (mParts.size() > 1)
                //    temp += '\n';
            }
            
            for (int i = mParts.size(); i != 0; i--)
                temp += ')';
            
            return temp;
        }
        void AddNode(VarPart * part)
        {
            mIsValid = CheckValidity(part);
            if(!mIsValid)
                mParts.push_back(part);
            
        }
        DeclNode * GetType()
        {
            return mParts.back()->GetType();
        }
        bool CheckValidity(VarPart* symbol)
        {
            //First check to see if the symbol is in the current symbol table
            if (symbolTableRoot->FullLookup(symbol->GetSym()->GetName()) && symbol->GetSym()->GetDeclared())
                return false; // No error
            else if(mParts.size() == 0)
            {
                mErrorMsg = "Symbol " + symbol->GetSym()->GetName() + " not defined";
                return true;
            }
            else
            {
                StructDecl* decl = nullptr;
                
                //Get declnode from mSym
                //Convert to StructDecl
                try
                {
                    decl = ((StructDecl*)mParts.back()->GetType());
                }
                catch(int e)
                {}
                
                // If it was able to convert to a struct decl...
                if (decl != nullptr)
                {
                    // Find the symbol in the struct that it belongs to
                    cSymbol * sym = decl->Find(symbol->GetSym()->GetName());
                    
                    // If we find it in the struct...
                    if(sym != nullptr)
                    {
                        symbol->SetSym(sym);
                        //mParts.back()->SetSym(sym);
                        return false; // No error
                    }
                    else // else, we didn't find the symbol in the struct, return the error
                    {
                        mErrorMsg = symbol->GetSym()->GetName() + " is not a field of ";
                        list<VarPart*>::const_iterator it = mParts.begin();
                        int counter = mParts.size() - 1;
                        
                        // Iterate through list of parts displaying them
                        while (it != mParts.end())
                        {
                            mErrorMsg += (*it)->GetSym()->GetName(); // Add to the error message
                            
                            it++; // Move iterator to the next VarPart
                            counter--;
                            
                            // If the iterator has not displayed the last Varpart
                            // add a '.' to differentiate between the different parts
                            if (counter != 0)
                                mErrorMsg += '.';
                        }
                        
                        return true; // Error
                    }
                }
                else //Else decl was not a struct decl
                {
                    mErrorMsg = mParts.back()->GetSym()->GetName() + " is not a struct";
                    return true;
                }
            }
            
            //return true so compiler won't complain
            return true;
        }
        
    private:
        list<VarPart*> mParts;
};
#endif