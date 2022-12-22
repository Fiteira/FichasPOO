#ifndef MOTOR_H
#define MOTOR_H


#include <iostream>
#include <string>
using namespace std;

enum ESTADO_MOTOR {ESTADO_PARADO = 0, ESTADO_RUN, ESTADO_AVARIADO};
class Gestao;
class Motor
{
    protected:
        float TEMPERATURA;
    private:
    Gestao *Ptr_Gestor;
    ESTADO_MOTOR ESTADO;
    public:
        Motor(Gestao *pg);
        virtual ~Motor();

        virtual bool RUN() { cout << "RUN ??"; return false; }
        virtual bool STOP() { cout << "STOP ??"; return false; }
        virtual bool START() { cout << "START ??"; return false; }
        bool AvisoTemperatura();
        ESTADO_MOTOR Get_ESTADO() { return ESTADO; }
        void Set_ESTADO(ESTADO_MOTOR EST) { ESTADO = EST; }
        void Set_TEMPERATURA(float t) { TEMPERATURA = t; }
};

#endif // MOTOR_H
