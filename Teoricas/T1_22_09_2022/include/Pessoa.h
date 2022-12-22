#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
using namespace std;

class Pessoa
{
    string NOME;
    string MORADA;
    int CC;
    public:
        Pessoa(string _nome, int _cc = -1, string _morada = "VISEU");
        virtual ~Pessoa();

        void Show();
        void Set_Nome(string _no)
        {
            NOME = _no;
        }

};

#endif // PESSOA_H
