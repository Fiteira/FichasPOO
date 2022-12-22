#include "Pessoa.h"

Pessoa::Pessoa(string _nome, string _bi)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    NOME=_nome;
    BI=_bi;
}

Pessoa::~Pessoa()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void Pessoa::Show()
{
    cout << "Nome: ["<< NOME <<"]"<<endl;
    cout << "BI: ["<< BI <<"]"<<endl;
    cout << "------------" << endl;
}

