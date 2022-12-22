#ifndef GESTAO_H
#define GESTAO_H

#include <iostream>
using namespace std;
#include <list>
#include <map>

#include "Pessoa.h"

class Gestao
{
    //list<PESSOA *> LP;
    map<string, list<Pessoa *>> DADOS;
    public:
        Gestao();
        virtual ~Gestao();
        bool AddPessoa(string nome, string cidade, int idade);
        bool AddPessoa(Pessoa *P);
        bool LerFicheiro(string nome_ficheiro);
        void Mostrar();
        bool Remover(Pessoa *P);
        bool Remover(string nome);
        bool GravarFicheiro(string ficheiro);
        Pessoa *PesquisarPessoa(string nome);
};

#endif // GESTAO_H
