#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
    int ID;
    public:
        User();
        virtual ~User();
        virtual bool PossoADD() { return false; }
        virtual bool PossoREM() { return false; }
};

#endif // USER_H
