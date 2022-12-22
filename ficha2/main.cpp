#include <iostream>
using namespace std;

#include "Gestao.h"

int main()
{
    Gestao G;
    //G.AddPessoa("Ze", "VISEU", 20);
    //G.AddPessoa("Pedro", "VISEU", 19);
    //G.AddPessoa("Joao", "PORTO", 21);

    //G.Mostrar();
    //G.GravarFicheiro("dados.txt");
    G.LerFicheiro("dados.txt");
    G.Mostrar();
    return 0;
}
