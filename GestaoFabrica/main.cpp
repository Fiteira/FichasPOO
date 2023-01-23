#include <iostream>
#include <sstream>
using namespace std;
#include <ctime>

#include "Fabrica.h"


void teste()
{
    User *U;

    U=new Admin(0,"Admin");

    Fabrica *F=new Fabrica(U,"Empresa-da-Minha-Terra",8,16,10,50,80,0,80,81,100,101,500,1,0,80,81,100,101,250,10,0,50,51,70,71,100,1);
    U=new Normal(1,"Normal");
    F->Add(U);

    U=new Visitante(2,"Visitante");
    F->Add(U);


    Motor *M=new MCombustao(100,"Roy",20,10,5,F);
    F->Add(M);
    M=new MCombustao(101,"HIRTH-SOLO",10,0,3,F);
    F->Add(M);
    M=new MCombustao(102,"F200",22,15,4,F);
    F->Add(M);
    M=new MEletrico(103,"EFACEC",18,10,1250,F);
    F->Add(M);
    M=new MEletrico(104,"EFACEC1",19,11,1250,F);
    F->Add(M);
    M=new MInducao(105,"XPTO4",11,13,50,F);
    F->Add(M);


//    Sensor *S=new Stemperatura(200,"M1",20,12,1,50,F);
//    F->Add(S);
//    S=new Stemperatura(201,"M1",10,12,5,51,F);
//    F->Add(S);
//    S=new Sfogo(202,"M1",4,2,15,1,F);
//    F->Add(S);
//    S=new Smissel(203,"Molotof-Expresso",79,49,3,1,F);
//    F->Add(S);

//    S=new Sluz(204,"XPTO8",1,8,4,1,F);
//    F->Add(S);



    F->LigarMotores();

    F->Run();

    delete(F);
}

int main()
{
    teste();
//
//    User *U;
//    U=new Admin(0,"Admin");
//    Fabrica *F=new Fabrica(U)
//    F->Add(U);
//    F->Load("Empresa1XML.xml");
//    delete(F);


    return 0;
}
