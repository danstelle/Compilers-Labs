/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: To handle the different symbols that
 *          lang.l finds.
 * 
 * Constructor: Initializes all the members
 * 
 * toString: 
 ***********************************************/
#ifndef CSYMBOL_H
#define CSYMBOL_H

#include <iostream>
#include <string>
#include "DeclNode.h"
using std::string;

class cSymbol
{
    public:
        cSymbol(string sym, bool isType = false);
        virtual string toString();
        int GetSymCount();
        string GetName();
        DeclNode * GetType();
        void SetType(DeclNode * type);
        bool IsType();
        bool GetDeclared();
        void SetDeclared();
        void MakeType();
        ~cSymbol();
        
    protected:
        string mSym;
        int mSequence;
        static int symbolCount;
        bool mIsType;
        bool mIsDeclared;
        DeclNode * mDecl;
};
#endif