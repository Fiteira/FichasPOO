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
    //dtor
}
