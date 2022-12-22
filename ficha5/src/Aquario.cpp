#include "Aquario.h"
#include "Uteis.h"

Aquario::Aquario(string _ns)
{
    NSERIE = _ns;
}

Aquario::~Aquario()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

void Aquario::RUN()
{
     bool PARAR= false;
    while(!PARAR)
    {
        for (list<Peixe *>::iterator it = LPeixes.begin(); it != LPeixes.end(); ++it)
        (*it)->RUN();
        Uteis::DELAY(50);
    }
}

void Aquario::ADD(Peixe *P)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    if(P)
    {
        P->Ficas_Neste_Aquario(this);
        LPeixes.push_back(P);
    }

}
Peixe *Aquario::Pesquisar(string _ns)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return NULL;
}
bool Aquario::Remover(Peixe *P)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return false;
}
bool Aquario::Remover(string ns)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return false;
}
void Aquario::Alimentar(int x)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void Aquario::Mover_Brasas()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void Aquario::Esvaziar_Limpar()
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
void Aquario::Registar_Aviso_Fome(Peixe *P)
{
    LFome.push_back(P);
}
