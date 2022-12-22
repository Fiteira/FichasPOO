#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>
#include <fstream>
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
        virtual string Get_TIPO() { return "VEICULO"; }

        virtual void Run() = 0;
        virtual void Parar()
        {
            cout << "O Pa tens de implementar o metodo <" << __FUNCTION__ << ">\n";
            cout << "na classe: " << Get_TIPO() << endl;
        }
        virtual void SaveToXML(ofstream &F)
        {
            F << "NAO implementado o metodo <" << __FUNCTION__ << "> ";
            F << "na classe: " << Get_TIPO() << endl;
        }
};

#endif // VEICULO_H
