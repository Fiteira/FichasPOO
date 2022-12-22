#include "MCombustao.h"

MCombustao::MCombustao(Gestao *pg)
: Motor(pg)
{
    //ctor
}

MCombustao::~MCombustao()
{
    //dtor
}

bool MCombustao::RUN()
{
    cout << "MCombustao.... RUN : TEMP = " << TEMPERATURA << endl;
    cout << "ESTADO: " << Get_ESTADO() << endl;
    if (Get_ESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        TEMPERATURA += 0.1f;
        if (TEMPERATURA > 100)
        {
            AvisoTemperatura();
            //Set_ESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        }
    }
    return true;
}
bool MCombustao::STOP()
{
        cout << "MCombustao.... STOP" << endl;
    return true;
}
bool MCombustao::START()
{
    cout << "MCombustao.... START" << endl;
    return true;
}
