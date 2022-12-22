#include "Motor.h"

#include "Gestao.h"

Motor::Motor(Gestao *pg)
{
    TEMPERATURA = 0;
    Ptr_Gestor = pg;
}

Motor::~Motor()
{
    //dtor
}

bool Motor::AvisoTemperatura()
{
    cout << "TEMPERATURA EM EXCESSO!!!!" << endl;
    if (Ptr_Gestor)
    {
        Ptr_Gestor->EstouQuente(this);
        return true;
    }
    return false;
}
