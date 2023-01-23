#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class Fabrica;
class User
{
     private:
        int ID;
        string NOME;

    protected:

    public:
        User(int _id,string _nome);
        virtual ~User();
        virtual bool PossoLISTAR() {return false;}
        virtual bool PossoMANUTENCAO() { return false; }
        virtual bool PossoRUN() { return false; }
        virtual bool PossoREMOVER() { return false; }
        virtual bool PossoADD() { return false; }


        int getId(){return ID;}
        string getNome(){return NOME;}

};

#endif // USER_H
