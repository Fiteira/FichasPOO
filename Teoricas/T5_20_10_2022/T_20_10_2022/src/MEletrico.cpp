#include "MEletrico.h"

MEletrico::MEletrico(Gestao *pg)
: Motor(pg)
{
    //ctor
}

MEletrico::~MEletrico()
{
    //dtor
}

bool MEletrico::RUN()
{
    cout << "MEletrico.... RUN" << endl;
    return true;
}
bool MEletrico::STOP()
{
        cout << "MEletrico.... STOP" << endl;
    return true;
}
bool MEletrico::START()
{
    cout << "MEletrico.... START" << endl;
    return true;
}
