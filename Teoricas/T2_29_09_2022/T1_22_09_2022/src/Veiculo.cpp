#include "Veiculo.h"

Veiculo::Veiculo()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    ANO = 2000;
    MARCA = "???";
}

Veiculo::~Veiculo()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Veiculo::Show()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    cout << "MARCA: [" << MARCA << "]" << endl;
    cout << "ANO: " << ANO << endl;
}

Veiculo::Veiculo(string _marca, int _ano)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    MARCA = _marca;
    ANO = _ano;
}
