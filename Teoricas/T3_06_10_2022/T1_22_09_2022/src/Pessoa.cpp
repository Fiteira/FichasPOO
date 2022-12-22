#include "Pessoa.h"

Pessoa::Pessoa(string _nome, int _cc, string _morada)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    NOME = _nome;
    CC = _cc;
    MORADA = _morada;
}

Pessoa::~Pessoa()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Pessoa::Show()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    cout << "PESSOA:" << endl;
    cout << "\t NOME: [" << NOME << "]" << endl;
    cout << "\t MORADA: [" << MORADA << "]" << endl;
    cout << "\t CC: [" << CC << "]" << endl;
}
