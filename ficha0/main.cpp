#include <iostream>

using namespace std;



 int inv_numero(int x)
{
    int res;

    while(x>0)
    {
        int alg=x%10;
        x=x/10;
        res=res * 10 + alg;
    }
        return res;
}



int main()
{
    int x;
    int alg;
    cout << "Numeros para o Histograma:" << endl;
    cin >> x;
    int xINV=inv_numero(x);
    for(int linha=9;linha>=1;linha--)
    {
        int n=x;
      while(n>0){
            alg=n%10; //634 % 10 =>4
            n=n/10; //634/10 =>63
            if(alg>=linha)
                    cout << "*";
                else
                    cout << "-";
            //cout <<endl;
       }
        cout <<endl;

    }
    cout<<xINV;
    return 0;

}
