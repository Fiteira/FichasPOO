#include <iostream>
using namespace std;

#include "Peixe.h"
#include "Aquario.h"
#include <time.h>

void Start()
{
    srand(time(NULL));
}

int main()
{
    cout << "Hello world!" << endl;
    Start();

    int NSERIE_PEIXE=500;
    Aquario *AQ;
    AQ = new Aquario();

    Peixe *P1 = new Peixe("Sardinha",NSERIE_PEIXE++,15);
    AQ->ADD(P1);
    P1 = new Peixe("Carapau", NSERIE_PEIXE++, 150);
    AQ->ADD(P1);

    AQ->RUN();
    delete AQ;

    return 0;
}
