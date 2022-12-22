#ifndef AQUARIO_H
#define AQUARIO_H

#include <iostream>
#include <string>
using namespace std;
#include <list>

#include "Peixe.h"

class Aquario
{
    list<Peixe *> LPeixes;
    list<Peixe *> LFome;
    list<Peixe *> LSair;

    string NSERIE;
    public:
        Aquario(string _ns = "00000");
        virtual ~Aquario();
        void RUN();
        void ADD(Peixe *P);
        Peixe *Pesquisar(string _ns);
        bool Remover(Peixe *P);
        bool Remover(string ns);
        void Alimentar(int x);
        void Mover_Brasas();
        void Esvaziar_Limpar();
        void Registar_Aviso_Fome(Peixe *P);
};

#endif // AQUARIO_H
