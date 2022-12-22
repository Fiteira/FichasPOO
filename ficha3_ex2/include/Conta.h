#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "Pessoa.h"

class Conta
{
    Pessoa *Titular;
    float SALDO;
    //list<Pessoa *> LTitulares;
    public:
        Conta(Pessoa *t);
        virtual ~Conta();
        void Depositar(float v);
        void Show();
        float Get_saldo(){return SALDO;}
        Pessoa *Get_titular(){return Titular;}
    protected:

    private:
};

#endif // CONTA_H
