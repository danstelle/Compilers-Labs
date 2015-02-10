#ifndef ARRAYSPEC_H
#define ARRAYSPEC_H

#include <string>

using std::string;

class ArraySpec
{
    public:
        ArraySpec()
        {}
        virtual string toString()
        {
            string temp = "(ARRAYSPEC: ";
            list<int>::const_iterator it;
            
            for (it = mArray.begin(); it != mArray.end(); it++)
                temp += std::to_string(*it) + ' ';
                
            temp += ")\n";
            
            return temp;
        }
        void AddNode(int val)
        {
            mArray.push_back(val);
        }
        
    private:
        list <int> mArray;
        
};
#endif