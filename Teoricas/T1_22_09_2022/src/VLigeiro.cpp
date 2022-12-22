#include "VLigeiro.h"
#include "Uteis.h"

VLigeiro::VLigeiro()
: Veiculo()
{
    //ctor
}

VLigeiro::VLigeiro(string _m, int _a)
: Veiculo(_m, _a)
{
    Uteis::MSG("Passei em VLigeiro::VLigeiro(string _m, int _a)");
}

VLigeiro::~VLigeiro()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void VLigeiro::Run()
{
    cout << "RUN de  <" << __FUNCTION__ << ">" << endl;
}
