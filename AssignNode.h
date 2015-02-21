/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To print the string for an assignment.
 * 
 * Constructor: Initializes all the members.
 * 
 * toString: Returns the string for an assignment.
 ***********************************************/
#ifndef ASSIGNNODE_H
#define ASSIGNNODE_H

#include "StmtNode.h"
#include "ExprNode.h"
#include "VarRef.h"
#include "parser.h"
#include <string>

using std::string;

class AssignNode : public StmtNode
{
    public:
        AssignNode(VarRef * left, ExprNode * right)
            : mLeft(left), mRight(right)
        {
            mErrorMsg = CheckValidity();
        }
        string CheckValidity()
        {
            mIsValid = false;
            DeclNode * character = symbolTableRoot->FullLookup("char")->GetType();
            DeclNode * integer = symbolTableRoot->FullLookup("int")->GetType();
            DeclNode * floating = symbolTableRoot->FullLookup("float")->GetType();
            string temp = "";
            
            if (mLeft->GetType() != mRight->GetType()) // Check to see if the types are the same
            {
                if (mLeft->GetType() == character && mRight->GetType() == integer)
                {
                    temp = "Cannot assign int to char";
                    mIsValid = true;
                }
                else if (mLeft->GetType() == integer && mRight->GetType() == floating)
                {
                    temp = "Cannot assign float to int";
                    mIsValid = true;
                }
                else if (mLeft->GetType() == character && mRight->GetType() == floating)
                {
                    temp = "Cannot assign float to char";
                    mIsValid = true;
                }
            }
            
            return temp;
        }
        // bool SemanticError()
        // {
        //     return mIsValid;
        // }
        // string GetMsg()
        // {
        //     return mError;
        // }
        virtual string toString()
        {
            return "(ASSIGN: " + mLeft->toString() + " = " + mRight->toString() + ")";
        }
        
    private:
        VarRef * mLeft;
        ExprNode * mRight;
        //string mError;
};
#endif