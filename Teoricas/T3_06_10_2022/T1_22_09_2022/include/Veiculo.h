#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>
using namespace std;

class Veiculo
{
    //protected:
    string MARCA;
    int ANO;

    public:
        Veiculo();
        Veiculo(string _marca, int _ano = 2022);
        virtual ~Veiculo();

        virtual void Show();

        int Get_ANO() { return ANO; }
        string Get_MARCA() { return MARCA; }
};

#endif // VEICULO_H
