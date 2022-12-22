#ifndef GESTAO_H
#define GESTAO_H

#include <iostream>
using namespace std;
#include <list>
#include <string>

#include "Pessoa.h"
#include "Veiculo.h"

class Gestao
{
    list<Veiculo *> LV;
    list<Pessoa *> LP;
    public:
        Gestao();
        virtual ~Gestao();
        void Load(string nf);
        void ShowVeiculos();
        void ShowPessoas();
        void Show();
        bool Save(string nf);
        void AddVeiculo(Veiculo *V);
        void AddPessoa(Pessoa *P);
        void Clear();
        void SaveToXML(string nf);
};

#endif // GESTAO_H
