#ifndef CSYMBOL_H
#define CSYMBOL_H

#include <iostream>
#include <string>
using std::string;

class cSymbol
{
    public:
        cSymbol(string sym);
        virtual string toString();
        int GetSymCount();
        ~cSymbol();
        
    protected:
        string mSym;
        int mSequence;
        static int symbolCount;
        
};
#endif