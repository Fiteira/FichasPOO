#ifndef ORDENACAO_H
#define ORDENACAO_H

#include<iostream>
#include<string>
#include<fstream>
#include<time.h>

using namespace std;

    class Ordenacao
    {
        public:
            static void BubbleSort(int *V,int N,string f_output)
            {
                int NT=0;
                float Tempo=0;
                clock_t t;
                t=clock();
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<N-i-1;j++)
                    {
                        if(V[j]>V[j+1])
                        {
                            int Aux=V[j];
                        V[j]=V[j+1];
                        V[j+1]=Aux;
                        NT++;
                        }
                    }
                }
            t=clock()-t;
            Tempo=((float)t)/CLOCKS_PER_SEC;
            ofstream F(f_output,ios::app);

            F << __FUNCTION__ <<"," << N << "," << NT << "," << Tempo << endl;

            F.close();
        }
        static void InsertSort(int *V, int N, string f_output)
        {
            int NT = 0;
            float Tempo = 0;
            // codigo da ordenacao....

            ofstream F(f_output, ios::app);
            F << __FUNCTION__ <<";" << N << ";" << NT << ";" << Tempo << endl;
            F.close();
        }
};

#endif // ORDENACAO_H
