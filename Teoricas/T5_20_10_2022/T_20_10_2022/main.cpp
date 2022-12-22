#include <iostream>
using namespace std;
#include "Gestao.h"


int main()
{
    cout << "Hello world!" << endl;
    //User *U = new Visitante();
    User *U = new Admin();
    Gestao GVis(U);

    MEletrico *ME = new MEletrico(&GVis);
    GVis.Add(ME);
    MCombustao *M = new MCombustao(&GVis);
    GVis.Add(M);

    GVis.Run();

    return 0;
}
