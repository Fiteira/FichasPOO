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
    TEMPERATURA += 0.1f;
    if (TEMPERATURA > 100)
        AvisoTemperatura();
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
