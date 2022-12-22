#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>
using namespace std;

class Veiculo
{
    string MARCA;
    int ANO;

    public:
        Veiculo();
        Veiculo(string _marca, int _ano = 2022);
        virtual ~Veiculo();
        void Show();

};

#endif // VEICULO_H
