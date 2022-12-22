#ifndef UTEIS_H
#define UTEIS_H
#include<iostream>
#include<string>

using namespace std;
#include <cstdlib>

class Uteis
{
    public:
    static bool LerVector(int *V,int N)
    {
        return true;
    }
    static bool GerarAleatorioVector(int *V,int N)
    {
        for(int i=0;i<N;i++)
        {
            V[i]=rand()%100;
        }
        return true;
    }
    static int LerInteiro(string txt)
    {
        cout << txt;
        int X;
        cin >> X;
        return X;
    }
    static void MostrarVector(int *V,int N)
    {
        cout << "{";
        for(int i=0;i<N;i++)
            cout << V[i] << ";";
        cout << "}";
    }
    static void CopiarVetor(int *x,int *y,int n)
    {
        cout<<"Funcao <"<<__FUNCTION__<< ">" << endl;

        for(int i=0;i<n;i++)
        {
            y[i]=x[i];
        }
    }
};

#endif // UTEIS_H
