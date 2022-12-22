#include "Gestao.h"

Gestao::Gestao(User *ut)
{
    Ut_Atual = ut;
    LUsers.push_back(ut);
}

Gestao::~Gestao()
{
    //dtor
}

void Gestao::EstouQuente(Motor *M)
{
    // Se M já está na lista nao deixo inserir
    LMQuentes.push_back(M);
}

void Gestao::Run()
{
    while(true)
    {
        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
            (*it)->RUN();
        cout << "NAvisos-TEMP = " << LMQuentes.size() << endl;
    }
}

void Gestao::Add(Motor *M)
{
    if (Ut_Atual)
    {
        if (Ut_Atual->PossoADD())
            LMotores.push_back(M);
        else
            cout << "Nao tens autorizacao!!!" << endl;
    }
    else
        cout << "Nao existe User!" << endl;
}
