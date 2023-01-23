#ifndef NORMAL_H
#define NORMAL_H

#include <iostream>
#include <string>
using namespace std;

#include <User.h>


class Normal : public User
{
    private:

    protected:

    public:
        Normal(int _id,string _nome);
        virtual ~Normal();
        bool PossoLISTAR() {return true;}
        bool PossoMANUTENCAO() { return true; }
        bool PossoRUN() { return true; }
        bool PossoREMOVER() { return false; }
        bool PossoADD() { return true; }

};

#endif // NORMAL_H
