#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Pessoa
{
    //list<Conta *> LContas;

    public:
        Pessoa(string _nome, string _bi);
        virtual ~Pessoa();
        void Show();
        string Get_nome(){return NOME;}
        string Get_bi(){return BI;}
    protected:

    private:
        string NOME;
        string BI;
};

#endif // PESSOA_H
