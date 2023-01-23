#ifndef OBJETOS_H
#define OBJETOS_H


#include <iostream>
#include <string>
#include "Uteis.h"

using namespace std;

class Fabrica;
class Objetos
{
    private:
        int ID;
        string MARCA;
        int POSICAO_Y;
        int POSICAO_X;
        float PROB_AVARIA;
        Fabrica *Pt_Fabrica;
        string TIPO;
        int numeroDeAvarias;


    protected:

    public:
        Objetos(int _id,string _marca,int _posicaoY,int _posicaoX,Fabrica *Pt);
        virtual ~Objetos();
        virtual void show(ostream &f = std::cout);

        //gets
        int getID(){return ID;}
        string getMARCA(){return MARCA;}
        int getPOSICAO_Y(){return POSICAO_Y;}
        int getPOSICAO_X(){return POSICAO_X;}
        float getPROB_AVARIA(){return PROB_AVARIA;}
        Fabrica *getPt_Fabrica() { return Pt_Fabrica; }
        string getTIPO(){return TIPO;}
        int getNumeroDeAvarias(){return numeroDeAvarias;}

        //sets

        void setTIPO(string tipo){TIPO = tipo;}
        void setNumeroDeAvarias(int numero){numeroDeAvarias = numero;}





};

#endif // OBJETOS_H
