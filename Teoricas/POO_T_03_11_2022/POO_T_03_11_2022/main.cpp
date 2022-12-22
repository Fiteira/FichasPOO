#include <iostream>
using namespace std;
#include <ostream>
#include <fstream>
#include <string>
#include <list>

void FListar(ostream &F = cout)
{
    F << "ola Pessoal" << endl;
}

void TrocarInt(int &x, int &y)
{
    int aux;
    aux = x;
    x = y;
    y = aux;
}

template <class T>
void Trocar(T &x, T &y)
{
    T aux;
    aux = x;
    x = y;
    y = aux;
}
template<class T>
void Escrever(T x)
{
    cout << x << endl;
}
template <class T, class U>
void calculo(T x, U y)
{
    T Res = x+y;
    Escrever(Res);
}
template <class T, class U>
class Associacao
{
    T Obj1;
    U Obj2;
public:
    Associacao(T x, U y)
    {
        Obj1 = x;
        Obj2 = y;
    }
};

template <class T>
class NO
{
public:
    T *Info;
    NO<T> *Prox;
public:
    NO(T *x, NO<T> *seg = NULL)
    {
        Info = x;
        Prox = seg;
    }
};
template <class T>
class ListaFM
{
    int NEL;
    NO<T> *Inicio;
public:
    ListaFM()
    {
        Inicio = NULL;
        NEL = 0;
    }
    void push_front(T *x)
    {
        NEL = 0;
        Inicio = new NO<T>(x, Inicio);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    //system("video_camara.mp4");
    /*
    FListar(cout);
    ofstream FF("lixo.txt");
    FListar(FF);
    FF.close();
    */
    /*
    int A = 10;
    int B = 20;
    */
    string A = "Ze10";
    string B = "Pedro";

    //cout << "A = " << A << " B = " << B << endl;
    //TrocarInt(A, B);
    /*
    cout << "A = " << A << " B = " << B << endl;
    Trocar(A, B);
    cout << "A = " << A << " B = " << B << endl;

    calculo("5", 8);
    */
    /*
    Associacao<int, string> XX(12, A);

    //Associacao<Carro, Pessoa> XX(C1, P1);
    list<Associacao<int, string>> L1;

    Associacao<int, Associacao<string, string>> XXXX;
*/

    list<string> LS;

    LS.push_front()


    return 0;
}
