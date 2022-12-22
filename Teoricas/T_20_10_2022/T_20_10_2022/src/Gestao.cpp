
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
    list<Motor *>::iterator it;
    it = find(LMQuentes.begin(), LMQuentes.end(), M);
    if (it != LMQuentes.end())
        cout << "........................JA LA ESTA !!!!!!!!!!!" << endl;
    else
    {
        M->Set_ESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        LMQuentes.push_back(M);
    }
}
void Gestao::Ligar_Motores()
{
    for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
        (*it)->Set_ESTADO(ESTADO_MOTOR::ESTADO_RUN);
}

void Gestao::Run()
{
    while(true)
    {
        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
            (*it)->RUN();
        cout << "NAvisos-TEMP = " << LMQuentes.size() << endl;
        if (LMQuentes.size() > 0)
            Manutencao();
    }
}

void Gestao::Manutencao()
{
    for (list<Motor *>::iterator it = LMQuentes.begin(); it != LMQuentes.end(); ++it)
    {
        (*it)->Set_TEMPERATURA(10);
        (*it)->Set_ESTADO(ESTADO_MOTOR::ESTADO_RUN);
    }
    LMQuentes.clear();
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
