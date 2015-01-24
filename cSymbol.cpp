#include "cSymbol.h"

int cSymbol::symbolCount = 0;

cSymbol::cSymbol(string str)
    :mSym(str), mSequence(++symbolCount)
{}

int cSymbol::GetSymCount()
{
    return symbolCount;
}

string cSymbol::toString()
{
    return "sym: " + mSym + " " + std::to_string(mSequence);
}

cSymbol::~cSymbol()
{}