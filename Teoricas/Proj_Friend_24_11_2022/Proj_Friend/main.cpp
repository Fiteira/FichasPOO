#include <iostream>
using namespace std;
//--------------------------------
class A {
private:
    int a;

public:
    A() { a = 0; }
    friend class B; // Friend Class

        // global friend function
    friend void FuncaoAmigaGlobal(A&);
};

//--------------------------------
class B {
private:
    int b;

public:
    void showA(A& x)
    {
        // Class B é AMIGA da class A, então pode ter acesso a
        // membros (atributos, métodos) da class A
       cout << "A::a=" << x.a << endl;

    }
};

void FuncaoAmigaGlobal(A &x)
{
    // FuncaoAmigaGlobal é AMIGA da class A, então pode ter acesso a
    // membros (atributos, métodos) da class A
    cout << "A::a=" << x.a << endl;
}
//----------------------- OUTRO EXEMPLO ------------------------
class Ponto {
	int   X, Y;
public:
	Ponto(int x=0, int y=0) { cout << "\nConstruir Ponto \n"; X=x; Y=y; }
	~Ponto() { cout << "\nDestruir Ponto \n"; }
    operator int() { return (X * Y); }     // Conversão para inteiro -   (int) p
    void Show() { cout << "Ponto=(" << X << ", " << Y << ")";}

	friend ostream &operator<<(ostream& os, const Ponto &p);//os<<p;
	friend void operator>>(istream& is, Ponto &p);    // is >> p;
	friend void MostrarAMIGO(Ponto &p);
};

void MostrarAMIGO(Ponto &p)
{
	cout << "Ponto=(" << p.X << ", " << p.Y << ") " << endl;
	p.X = -10;
}

ostream &operator<<(ostream& os, const Ponto &p) {
	os << "Ponto=(" << p.X << ", " << p.Y << ") " << endl;
	//p.X = -1;
	return os;
}

void operator>>(istream& is, Ponto &p)
{
    is >> p.X >> p.Y;
    p.Y --;
}
//--------------------------------
//--------------------------------
//--------------------------------
//--------------------------------
int main()
{
    /*
    A a;
    B b;
    b.showA(a);
    FuncaoAmigaGlobal(a);
    */
    //------------------
    Ponto X(20, 30);
    X.Show();
    cout << X << endl;

    MostrarAMIGO(X);
    X.Show();
    cin >> X;
    X.Show();

    return 0;
}
