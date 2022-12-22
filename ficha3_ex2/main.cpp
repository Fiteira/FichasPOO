#include <iostream>
#include <time.h>

using namespace std;

#include "Banco.h"

void gerarContas(int qtd)
{

    //srand((unsigned) time(NULL));
    Banco BES("Banco Viseu");

    list<Pessoa *> clientes;

    int i;

    for ( i = 0; i < qtd ; i++)
    {
        int random = rand() % 100000;
        float saldo = rand() % 1000;
        string nome = "Cliente" + to_string(i);
        string bi = to_string(random);
        Pessoa *PES = new Pessoa(nome, bi);
        BES.Add(PES);
        Conta *C = new Conta(PES);
        BES.Add(C);
        C->Depositar(saldo);
    }
    BES.Show();
    cout << "*********************" << endl;
    //BES.Depositar("41",2);
    //BES.ShowContas();
    BES.PesquisarContaMaisGordinha()->Show();
}

int main()
{
    gerarContas(2);


    return 0;
}
