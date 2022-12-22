#ifndef MOTOR_H
#define MOTOR_H


#include <iostream>
#include <string>
using namespace std;

class Gestao;
class Motor
{
    protected:
        float TEMPERATURA;
    private:
    Gestao *Ptr_Gestor;
    public:
        Motor(Gestao *pg);
        virtual ~Motor();

        virtual bool RUN() { cout << "RUN ??"; return false; }
        virtual bool STOP() { cout << "STOP ??"; return false; }
        virtual bool START() { cout << "START ??"; return false; }
        bool AvisoTemperatura();
};

#endif // MOTOR_H
