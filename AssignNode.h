/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To print the string for an assignment.
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
            mIsError = CheckValidity();
        }
        bool CheckValidity()
        {
            DeclNode * character = symbolTableRoot->FullLookup("char")->GetType();
            DeclNode * integer = symbolTableRoot->FullLookup("int")->GetType();
            DeclNode * floating = symbolTableRoot->FullLookup("float")->GetType();
            DeclNode * l_type = mLeft->GetType();
            DeclNode * r_type = mRight->GetType();
            
            if ((l_type->GetName() == r_type->GetName()) || // Check if they are the same type
                (l_type->GetName() == integer->GetName() && r_type->GetName() == character->GetName()) || // Check valid integer assignments
                (l_type->GetName() == floating->GetName() && (r_type->GetName() == integer->GetName() || r_type->GetName() == character->GetName()))) // Check valid float assignments
            {
                return false; // No error
            }
            else
            {
                mErrorMsg = "Cannot assign " + r_type->GetName() + " to " + l_type->GetName();
                return true; // Anything that does not match the above conditions
            }
        }
        virtual string toString()
        {
            return "(ASSIGN: " + mLeft->toString() + " = " + mRight->toString() + ")";
        }
        int ComputeOffsets(int base)
        {
            mLeft->ComputeOffsets(base);
            
            if (mRight != nullptr)
                mRight->ComputeOffsets(base);
            
            return base;
        }
        void GenerateCode()
        {
            if (mRight->IsFunc())
            {
                mRight->GenerateCode();
                mLeft->GenerateCode();
                EmitString(" = ");
                
                if (mRight->GetType()->IsFloat())
                    EmitString("Temp_F;\n");
                else
                    EmitString("Temp;\n");
            }
            else
            {
                mLeft->GenerateCode();
                EmitString(" = ");
                mRight->GenerateCode();
                EmitString(";\n");
            }
        }
        
    private:
        VarRef * mLeft;
        ExprNode * mRight;
};
#endif