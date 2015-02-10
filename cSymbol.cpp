#include "cSymbol.h"

int cSymbol::symbolCount = 0;

cSymbol::cSymbol(string str, bool isType)
    :mSym(str), mSequence(++symbolCount), mIsType(isType)
{}

int cSymbol::GetSymCount()
{
    return symbolCount;
}

string cSymbol::toString()
{
    return "sym: " + mSym + " " + std::to_string(mSequence);
}

string cSymbol::GetName()
{
    return mSym;
}

bool cSymbol::IsType()
{
    return mIsType;
}

void cSymbol::MakeType()
{
    mIsType = true;
}

cSymbol::~cSymbol()
{}