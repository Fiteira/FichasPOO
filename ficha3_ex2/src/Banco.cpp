#include "Banco.h"

Banco::Banco(string _nome)
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    NOME = _nome;
}

Banco::~Banco()
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    LimparBanco();
}

void Banco::Show()
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    ShowClientes();
    ShowContas();
}
void Banco::ShowClientes()
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Pessoa *>::iterator it;
    for(it = LP.begin(); it != LP.end(); ++it)
            (*it)->Show();
}
void Banco::ShowContas()
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Conta *>::iterator it;
    for(it =LC.begin();it !=LC.end();++it)
        (*it)->Show();
}
void Banco::Add(Pessoa *P)
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if(P) LP.push_back(P);
}
void Banco::Add(Conta *C)
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if(C) LC.push_back(C);
}
bool Banco::RemoverConta(Conta *C)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return false;
}
Conta *Banco::PesquisarContaMaisGordinha()
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Conta *>::iterator it;
    Conta *Gorduxa = LC.front();
    for(it =LC.begin();it !=LC.end();++it)
    {
        if(Gorduxa->Get_saldo()< (*it)->Get_saldo())
            Gorduxa = *it;
    }
    return Gorduxa;
}
list<Conta *> *Banco::ContasSaldoInferior(float valor)
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Conta *> *laux = new list<Conta *>();
    list<Conta *>::iterator it;
    for(it =LC.begin();it !=LC.end();++it)
        if((*it)->Get_saldo() < valor)
            laux->push_back(*it);

    return laux;
}
void Banco::ExportarXML(string nf)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void Banco::LimparBanco()
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Pessoa *>::iterator it;
    for(it =LP.begin();it !=LP.end();++it)
        delete (*it);
    LP.clear();
    list<Conta *>::iterator itc;
    for(itc =LC.begin();itc !=LC.end();++itc)
        delete (*itc);
    LC.clear();
}
Pessoa *Banco::PesquisarPessoa(string bi)
{
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    list<Pessoa *>::iterator it;
        for(it =LP.begin();it !=LP.end();++it)
        {
            string comp=(*it)->Get_bi();
            if(comp.compare(bi) == 0)
                return (*it);
        }
    return NULL;
}
Conta *Banco::PesquisarConta(Pessoa *P)
{
    list<Conta *>::iterator it;
        for(it =LC.begin();it !=LC.end();++it)
        {
            string dono=(*it)->Get_titular()->Get_bi();
            if(dono.compare(P->Get_bi()) == 0)
                return (*it);
        }
    return NULL;
}
void Banco::Depositar(string bi, float dep)
{
    Pessoa *P=PesquisarPessoa(bi);
    Conta *C=PesquisarConta(P);
    C->Depositar(dep);
    //cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

bool Banco::RemoverConta(string bi)
{
    list<Conta *>::iterator it;
    for(it =LC.begin();it !=LC.end();++it)
    {
        string bic=(*it)->Get_titular()->Get_bi();
        if(bic.compare(bi)==0)
        {
            LC.remove(*it);
            return true;
        }
    }
    return false;
}
