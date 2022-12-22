#include "Pessoa.h"
#include <fstream>

Pessoa::Pessoa(string _nome, string _cidade, int _id)
{
    NOME = _nome;
    CIDADE = _cidade;
    IDADE = _id;
}

Pessoa::~Pessoa()
{
    //dtor
}
string Pessoa::Get_Cidade()
{
    return CIDADE;
}
void Pessoa::ShowPessoa()
{
    cout << "Nome: [" << NOME << "]" << endl;
    cout << "Cidade: [" << CIDADE << "]" << endl;
    cout << "Idade: [" << IDADE << "]" << endl;
    cout << "------------------------" << endl;
}
void Pessoa::SavePessoa(string nome_ficheiro)
{
    ofstream F;
    F.open(nome_ficheiro, ios::app);
        if (!F.is_open()) return;
        F << CIDADE << ";" << NOME << ";" << IDADE << ";" << endl;
    F.close();

}
