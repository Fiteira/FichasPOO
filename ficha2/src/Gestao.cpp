#include "Gestao.h"
#include "Pessoa.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

Gestao::Gestao()
{
    //ctor
}

Gestao::~Gestao()
{
    //dtor
}

bool Gestao::AddPessoa(string nome, string cidade, int idade)
{
    Pessoa *P = new Pessoa(nome, cidade, idade);
    AddPessoa(P);
    return true;
}
bool Gestao::AddPessoa(Pessoa *P)
{
    DADOS[P->Get_Cidade()].push_back(P);
    return true;
}

void split_str(string const &str, const char delim,vector<string> &out)
{
    // create a stream from the string
    stringstream s(str);

    string s2;
    while (getline(s, s2, delim) )
    {
        out.push_back(s2); // store the string in s2
    }
}

bool Gestao::LerFicheiro(string nome_ficheiro)
{
    ifstream F;
    string line;
    vector<string> palavra;
    F.open(nome_ficheiro);

    while (getline(F, line)){
        //cout << line << endl;
        split_str(line,';',palavra);

        string CIDADE = palavra[0];
        string NOME = palavra[1];
        string IDADE = palavra[2];
        int idade = stoi(IDADE);
        AddPessoa(NOME,CIDADE,idade);

        palavra.clear();

    }

    return true;
}
void Gestao::Mostrar()
{
    map<string,list<Pessoa *>>::iterator it;
    for(it=DADOS.begin(); it!=DADOS.end(); ++it)
    {
        cout <<"\t [" << it->first << "]\n";
        cout << "------------------------" << endl;
        list<Pessoa *>LP=it->second;
        list<Pessoa *>::iterator it;

        for (it = LP.begin(); it != LP.end(); ++it)
        {
            Pessoa *P = *it;
            P->ShowPessoa();
        }
    }
}
bool Gestao::Remover(Pessoa *P)
{

    return true;
}
bool Gestao::Remover(string nome)
{

    return true;
}
bool Gestao::GravarFicheiro(string ficheiro)
{
    map<string,list<Pessoa *>>::iterator it;
    for(it=DADOS.begin(); it!=DADOS.end(); ++it)
    {

        list<Pessoa *>LP=it->second;
        list<Pessoa *>::iterator it;

        for (it = LP.begin(); it != LP.end(); ++it)
        {
            Pessoa *P = *it;
            P->SavePessoa(ficheiro);
        }
    }
    return true;
}
Pessoa *Gestao::PesquisarPessoa(string nome)
{

    return NULL;
}
