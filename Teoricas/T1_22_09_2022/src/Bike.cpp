#include "Bike.h"

Bike::Bike()
: Veiculo()
{
    //ctor
}

Bike::~Bike()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Bike::Run()
{
    cout << "RUN de  <" << __FUNCTION__ << ">" << endl;
}
