/***********************************************
 * Author: Daniel Stelle
 *  
 * Purpose: Function definitions for cSymbol
 ***********************************************/
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

DeclNode * cSymbol::GetType()
{
    return mDecl;
}

void cSymbol::SetType(DeclNode * type)
{
    mDecl = type;
}

bool cSymbol::IsType()
{
    return mIsType;
}

void cSymbol::MakeType()
{
    mIsType = true;
}

void cSymbol::SetDeclared()
{
    mIsDeclared = true;
}

bool cSymbol::GetDeclared()
{
    return mIsDeclared;
}

cSymbol::~cSymbol()
{}