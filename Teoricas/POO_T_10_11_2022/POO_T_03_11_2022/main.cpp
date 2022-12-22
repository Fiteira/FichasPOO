#include <iostream>
using namespace std;
#include <ostream>
#include <fstream>
#include <string>
#include <list>

class Sensor
{
    int ID;
    string MARCA;
    int VALOR;
public:
    Sensor(int _id, string _m, int _v = 0)
    {
        ID = _id;
        MARCA = _m;
        VALOR = _v;
    }
    void Show()
    {
        cout << "Sensor: " << ID << " : " << MARCA << endl;
    }
    bool operator==(int idsss)
    {
        return ID == idsss;
    }
    int GetID()
    {
        return ID;
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
    void Show()
    {
        NO<T> *P = Inicio;
        while (P)
        {
            P->Info->Show();
            P = P->Prox;
        }
    }
    T *Search(int id)
    {
        NO<T> *P = Inicio;
        while (P)
        {
            T *obj = P->Info;
            if (*obj == id)
                return obj;
            P = P->Prox;
        }
    }
    T *Search(string id, bool (fcomp)(T *, string))
    {
        NO<T> *P = Inicio;
        while (P)
        {
            T *obj = P->Info;
            if (fcomp(obj, id))
                return obj;
            P = P->Prox;
        }
    }

    void PercorrerListaExecuta(void (func)(T *))
    {
        NO<T> *P = Inicio;
        while (P)
        {
            T *obj = P->Info;
            func(obj);
            P = P->Prox;
        }
    }
};

bool Fcomp_ID(Sensor *S, string id)
{
    //return S->GetID() == id;
    // to_string()
    return true;
}

bool Fcomp_MARCA(Sensor *S, string id)
{
   // return S->GetMARCA() == id;
    return true;
}

int main()
{
    cout << "Hello world!" << endl;
    ListaFM<Sensor> LS;
    Sensor *S1 = new Sensor(1, "S1");
    LS.push_front(S1);
    S1 = new Sensor(2, "S2");
    LS.push_front(S1);

    LS.Show();

    LS.Search("1", Fcomp_ID);
    LS.Search("XPTO", Fcomp_MARCA);

    return 0;
}
