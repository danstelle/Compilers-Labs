#ifndef CSYMBOL_H
#define CSYMBOL_H

#include <iostream>
#include <string>
using std::string;

class cSymbol
{
    public:
        cSymbol(string sym, bool isType = false);
        virtual string toString();
        int GetSymCount();
        string GetName();
        bool IsType();
        void MakeType();
        ~cSymbol();
        
    protected:
        string mSym;
        int mSequence;
        static int symbolCount;
        bool mIsType;
        
};
#endif