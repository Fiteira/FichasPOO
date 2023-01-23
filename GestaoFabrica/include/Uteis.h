#ifndef UTEIS_H
#define UTEIS_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include<vector>
using namespace std;

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <conio.h>


class Uteis
{

public:
    Uteis();
    virtual ~Uteis();


    /** \brief Delay
     *
     * \param int milissegundo
     * \author Leandro Dias
     * \return void
     *
     */
    static void Delay(int ms)
    {
        int microsecond = 1000;
        usleep(ms * microsecond);
    }


    /** \brief Delay
     *
     * \param int milissegundo
     * \author Professor Morgado
     * \return void
     *
     */
    static void Wait(int s)
    {
        clock_t T0 = clock();
        clock_t T1 = T0 + s * CLOCKS_PER_SEC;
        while (clock() < T1);
    }



    /** \brief HoraAtual
     *
     * \param int sai por parametro hora
     * \author Leandro Dias
     * \return void
     *
     */

    static void HoraAtual(int &hora)
    {
        time_t t=time(0);
        tm* now = localtime(&t);
        hora=now->tm_hour;
    }

    /** \brief Numero inteiro Aleatorio
     *
     * \param int numero min e numero max
     * \author Leandro Dias
     * \return int
     *
     */
    static int Aleatorio(int _min,int _max)
    {
        srand(time(NULL)*getpid());
        return _min + rand()%(_max - _min + 1);
    }


    /** \brief Numero double Aleatorio
     *
     * \param double numero min e numero max
     * \author Leandro Dias
     * \return double
     *
     */
    static double AleatorioDouble(double _min,double _max)
    {
        srand(time(NULL)*getpid());
        double numero;
        numero=_min + (rand() / (RAND_MAX / (_max - _min)));
        return  numero;
    }

    /** \brief Mensagem de texto para o ecra
     *
     * \param  texto
     * \author Leandro Dias
     * \return void
     *
     */
    static void Msg(string txt)
    {
        cout << txt << endl;
    }


    /** \brief Ler inteiro mandando um texto como parametro
     *
     * \param  texto
     * \author Leandro Dias
     * \return int
     *
     */
    static int LerInteiro(string txt)
    {
        cout << txt;
        int X;
        cin >> X;
        return X;
    }


    /** \brief Separar String
     *
     * \param  uma string completa, o tipo que separa a string e o output de vector de strings separadas
     * \author Leandro Dias
     * \return void
     *
     */
    static void SepararStr(string const &str, const char tipo,vector<string> &out)
    {
        stringstream s(str);

        string s2;
        while (getline(s, s2, tipo) )
        {
            out.push_back(s2);
        }
    }

    /** \brief Probabilidade Acerto
     *
     * \param  int
     * \author Leandro Dias
     * \return true / false
     *
     */
    static bool ProbabilidadeAcerto(int n)
    {
        srand(time(NULL)*getpid());
        int numero=rand()%100;
        if(numero <= (n-1))
            return true;
        else
            return false;
    }

    /** \brief Liberar_Memoria
     *
     * \param  lista com template
     * \author Leandro Dias
     * \return void
     *
     */
    template <class T>
    static void LiberarMemoria(list<T*>* lista)
    {
        auto it = lista->begin();
        while (it != lista->end())
        {
            delete(*it);
            ++it;
        }
        lista->clear();
    }
};

#endif // UTEIS_H
