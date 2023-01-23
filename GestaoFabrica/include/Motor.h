#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Objetos.h"

enum ESTADO_MOTOR {ESTADO_PARADO = 0, ESTADO_RUN, ESTADO_AVARIADO ,SEM_ESTADO=-1};
enum TEMPERATURA_COR {VERDE, AMARELO, VERMELHO};

class Motor : public Objetos
{
    private:
        int CONSUMO_HORA;
        int CONSUMO;
        ESTADO_MOTOR ESTADO;
        TEMPERATURA_COR COR_MOTOR;

    protected:
        double TEMPERATURA;
        int HORAS_TRABALHO;

    public:
        Motor(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt);
        virtual ~Motor();
        virtual bool RUN() { cout << "RUN ??"; return false; }
        virtual bool START(){ cout << "START ??"; return false; }
        virtual bool RESTART(){ cout << "RESTART ??"; return false; }
        virtual bool STOP() { cout << "STOP ??"; return false; }
        bool ESTOU_QUENTE();
        bool ESTOU_AVARIADO();

        virtual void show(ostream &f = std::cout)
        {
            Objetos::show(f);
            f << "CONSUMO_HORA: " << CONSUMO_HORA << endl;
        }


        //gets
        int getCONSUMO_HORA(){return CONSUMO_HORA;}
        int getCONSUMO(){return CONSUMO;}
        ESTADO_MOTOR getESTADO() { return ESTADO; }
        TEMPERATURA_COR getCOR_MOTOR() { return COR_MOTOR; }
        double getTEMPERATURA(){return TEMPERATURA; }
        int getHorasTrabalho(){return HORAS_TRABALHO;}

        //sets
        void setCONSUMO_HORA(int consumoHora){CONSUMO_HORA = consumoHora; }
        void setCONSUMO(int CONSUMO){CONSUMO = CONSUMO; }
        void setESTADO(ESTADO_MOTOR EST) { ESTADO = EST; }
        void setCOR_MOTOR(TEMPERATURA_COR COR) { COR_MOTOR = COR; }
        void setTEMPERATURA(double temperatura){TEMPERATURA = temperatura; }


};

#endif // MOTOR_H
