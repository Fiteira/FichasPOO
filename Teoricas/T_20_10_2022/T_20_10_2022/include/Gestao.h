#ifndef GESTAO_H
#define GESTAO_H


#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
#include "Admin.h"
#include "Normal.h"
#include "Visitante.h"
#include "MEletrico.h"
#include "MCombustao.h"

class Gestao
{
    list<User *> LUsers;
    list<Motor *> LMotores;
    list<Motor *> LMQuentes;

    User *Ut_Atual;
    public:
        Gestao(User *ut);
        virtual ~Gestao();
        void EstouQuente(Motor *M);
        void Ligar_Motores();
        void Run();
        void Add(User *X)   { LUsers.push_back(X); Ut_Atual = X; }
        void Add(Motor *M);

        void Manutencao();

};

#endif // GESTAO_H
