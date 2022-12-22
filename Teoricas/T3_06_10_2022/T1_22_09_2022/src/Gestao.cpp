#include "Gestao.h"

Gestao::Gestao()
{
    cout << "Passei em <" << __FUNCTION__ << ">\n";
}

Gestao::~Gestao()
{
    cout << "Passei em <" << __FUNCTION__ << ">\n";

    Clear();
}

void Gestao::Load(string nf)
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
}
void Gestao::ShowVeiculos()
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
    list<Veiculo *>::iterator it;
    for (it = LV.begin(); it != LV.end(); ++it)
    {
        Veiculo *V = *it;
        V->Show();
    }
}
void Gestao::ShowPessoas()
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
    list<Pessoa *>::iterator it;
    for (it = LP.begin(); it != LP.end(); ++it)
    {
        Pessoa *P = *it;
        P->Show();
    }
     //   (*it)->Show();
}
void Gestao::Show()
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
    ShowPessoas();
    ShowVeiculos();
}
bool Gestao::Save(string nf)
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
}
void Gestao::AddVeiculo(Veiculo *V)
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
    LV.push_back(V);
}
void Gestao::AddPessoa(Pessoa *P)
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
    LP.push_back(P);
}
void Gestao::Clear()
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
}
void Gestao::SaveToXML(string nf)
{
    cout << "Um dia faco o metodo<" << __FUNCTION__ << "\n";
}
