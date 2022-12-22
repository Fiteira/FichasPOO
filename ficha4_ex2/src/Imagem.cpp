#include "Imagem.h"

Imagem::Imagem(string _nome,int _w,int _h)
{
    NOME = _nome;
    W = _w;
    H = _h;
   // Dados=new PixelRGB[_w*_h];
}

Imagem::~Imagem()
{
    delete [] Dados;
}
