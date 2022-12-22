#include <iostream>
using namespace std;

#include "Veiculo.h"
#include "Pessoa.h"
#include "Uteis.h"
#include "VLigeiro.h"
#include "VPesado.h"
#include "Gestao.h"

int main()
{
    Uteis::MSG("Aula 3: 06_10_2022");
    /*
    Gestao G_Pedro;

    G_Pedro.Load("dados.txt");
    G_Pedro.Show();
    Pessoa *P = new Pessoa("Zezito", 12345);
    G_Pedro.AddPessoa(P);

    G_Pedro.Save("dados_1.txt");
    G_Pedro.Clear();
    */
    VPesado V("VOLVO", 1990);
    V.Show();

    Veiculo *X = new VPesado("XXX", 2000);
    X->Show();

    return 0;
}
