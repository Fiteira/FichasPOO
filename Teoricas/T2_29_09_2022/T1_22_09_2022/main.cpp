#include <iostream>
using namespace std;

#include "Veiculo.h"
#include "Pessoa.h"
#include "Uteis.h"
#include "VLigeiro.h"

int main()
{
    Uteis::MSG("Aula 2: 29_09_2022");
    /*
    Pessoa P("Zezito!");

    P.Show();
    //P.NOME = "Miguel";
    P.Set_Nome("Miguel");
    P.Show();
    */
    VLigeiro VL("Opel Corsa: 1992", 1992);
    VL.Show();

    //Math.sin(343)
    return 0;
}
