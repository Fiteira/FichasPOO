#ifndef IMAGEM_H
#define IMAGEM_H
#include <string>
using namespace std;
#include "PixelRGB.h"

class Imagem
{
    string NOME;
    int W,H;

    PixelRGB *Dados;
    public:
        Imagem(string _nome,int w,int h);
        virtual ~Imagem();

    protected:

    private:
};

#endif // IMAGEM_H
