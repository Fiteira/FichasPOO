#include "Conta.h"

Conta::Conta(Pessoa *t)
{
    Titular = t;
    SALDO = 0;
}

Conta::~Conta()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

}
void Conta::Depositar(float v)
{
    if(v >=0)
        SALDO +=v;
    else
        cout << "O valor deve ser positivo" << endl;
}
void Conta::Show()
{
    cout << "Titular: [" << Titular->Get_nome() << "]" << endl;
    cout << "Saldo: " << SALDO << "" << endl;
    cout << "------------" << endl;
}
