#include "VPesado.h"

VPesado::VPesado()
{
    //ctor
}

VPesado::VPesado(string _m, int _a, bool tac)
: Veiculo(_m, _a)
{
    TACOGRAFO = tac;
}
VPesado::~VPesado()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void VPesado::Show()
{
    Veiculo::Show();
    cout << "TACOGRAFO: " << TACOGRAFO << endl;
    //------------------
    /*
    cout << "MARCA: " << Get_MARCA() << endl;
    cout << "ANO: " << Get_ANO() << endl;
    cout << "TACOGRAFO: " << TACOGRAFO << endl;
    //------------------
    // protected: no PAI, Veiculo
    cout << "MARCA: " << MARCA << endl;
    cout << "ANO: " << ANO << endl;
    cout << "TACOGRAFO: " << TACOGRAFO << endl;
    */
}

void VPesado::Run()
{
    cout << "RUN de  <" << __FUNCTION__ << ">" << endl;
}
