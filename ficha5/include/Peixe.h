#ifndef PEIXE_H
#define PEIXE_H
#include <iostream>
#include <string>
using namespace std;

//#include "Aquario.h"
class Aquario;
class Peixe
{
    Aquario *Pt_Aquario;
    string COR;
    string ESPECIE;
    int PESO;
    int NSERIE;
    public:
        Peixe(string _exp,int _ns,int _peso=10,string _cor="cinzento");
        virtual ~Peixe();
        bool RUN();
        void Comer(int g);
        void Aviso_Tenho_Fome();
        void Aviso_Quero_Sair();
        void Ficas_Neste_Aquario(Aquario *A) { Pt_Aquario = A; }

};

#endif // PEIXE_H
