#include <iostream>
#include <string>
using namespace std;
/*
class Produto
{
    static int IVA;
    string NOME;
public:
    Produto(string x = "nada")
    {
        NOME = x;
    }
    void Show()
    {
        cout << "Produto: " << NOME << endl;
        cout << "IVA = " << IVA << endl;
    }
    static void UpdateIVA(int x)
    {
        IVA = x;
    }
};

int Produto::IVA = 10;
int main()
{
    cout << "Variáveis estaticas" << endl;
    Produto P("Maca");
    P.Show();

    Produto VP[5];
    for (int i = 0; i < 5; i++)
        VP[i].Show();

    //Produto::IVA = 15;
    Produto::UpdateIVA(20);
    for (int i = 0; i < 5; i++)
        VP[i].Show();

    return 0;
}
*/


class Complexo
{
    float Im, Re;
public:

    /** \brief const por copia
     *
     * \param C const Complexo&
     *
     */
    Complexo(const Complexo &C)
    {
        cout << "Metodo<" << __FUNCTION__ << "(Complexo &C)>" << endl;
        Re = C.Get_Re();
        Im = C.Get_Im();
    }

    /** \brief Constructor onde é dado a parte real e imaginária
     *
     * \param r float
     * \param i float
     * \return retorna o complexo
     * \author FM & Alunos de POO
     * \date 13/12/2022
     */
    Complexo(float r = 0, float i = 0)
    {
        cout << "Metodo<" << __FUNCTION__ << "(float, float)>" << endl;
        Re = r;
        Im = i;
    }
    void Show()
    {
        cout << Re << "+" << Im << "i" << endl;
    }

    float Get_Re() const { return Re; }
    float Get_Im() const { return Im; }
    void Set_Re(float r) { Re = r; }
    void Set_Im(float i) { Im = i; }

    void operator=(const Complexo &C)
    {
        cout << "Metodo<" << __FUNCTION__ << "(float, float)>" << endl;
        Set_Re(C.Get_Re());
        Set_Im(C.Get_Im());
    }
    Complexo operator+(const Complexo &C)
    {
        cout << "Metodo<" << __FUNCTION__ << "(float, float)>" << endl;
        float nr = Re + C.Get_Re();
        return Complexo(nr, Im + C.Get_Im());
    }
    Complexo operator*(const Complexo &C)
    {
        cout << "Metodo<" << __FUNCTION__ << "(float, float)>" << endl;
        float R = Re * C.Get_Re() - Im * C.Get_Im();
        float I = Re * C.Get_Im() + C.Get_Re() * Im;
        return Complexo(R, I);
    }
    float MODULO(float x)
    {
        if (x < 0) return -x;
        return x;
    }
    bool ZERO(float x, float TOL = 0.000001f)
    {
        return MODULO(x) < TOL;
    }
    bool operator==(const Complexo &C)
    {
        return (ZERO(Re-C.Get_Re())) && (ZERO(Im - C.Get_Im()));
    }
    /*
    Complexo operator^(int N)
    {

    }
    */
};


int main()
{
    Complexo A(1, 2);
    A.Show();
    Complexo B(A);
    B.Show();

    B = A;

    cout << "Vamos multiplicar" << endl;
    Complexo Res;
    Res = A * B;
    Res.Show();

    return 0;
}

