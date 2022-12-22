#include <iostream>
using namespace std;

#include "Veiculo.h"
#include "Pessoa.h"
#include "Uteis.h"
#include "VLigeiro.h"
#include "VPesado.h"
#include "Bike.h"
#include "Gestao.h"

/*
void FG_1(const int &X)
{
    X = 5;
}
*/
int main()
{
    Uteis::MSG("Aula 4: 13_10_2022");
    /*
    Gestao G_Pedro;

    G_Pedro.Load("dados.txt");
    G_Pedro.Show();
    Pessoa *P = new Pessoa("Zezito", 12345);
    G_Pedro.AddPessoa(P);

    G_Pedro.Save("dados_1.txt");
    G_Pedro.Clear();
    */
    /*
    VPesado V("VOLVO", 1990);
    V.Show();

    Veiculo *X = new VPesado("XXX", 2000);
    X->Show();
*/

    Gestao G_Pedro;

    G_Pedro.Load("dados.txt");
    G_Pedro.Show();
    G_Pedro.AddVeiculo(new VLigeiro("VOLVO", 2020));
    G_Pedro.AddVeiculo(new VLigeiro("OPEL", 2010));
    G_Pedro.AddVeiculo(new VPesado("MAN", 2000, true));
    G_Pedro.AddVeiculo(new Bike());

    G_Pedro.ShowVeiculos();

    G_Pedro.SaveToXML("dados.xml");

    G_Pedro.Clear();

    /*
    Veiculo *V = new Bike();
    V->Parar();

    V = new VLigeiro("OPEL-CORSA", 2010);
    V->Parar();
*/

    return 0;
}
