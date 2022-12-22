#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
using namespace std;
#include <string>

class Pessoa
{
    string NOME, CIDADE;
    int IDADE;
    public:
        Pessoa(string _nome, string _cidade, int _id = 18);
        virtual ~Pessoa();
        string Get_Cidade();
        virtual void ShowPessoa();
        void SavePessoa(string nome_ficheiro);
};

#endif // PESSOA_H
