#ifndef STEMPERATURA_H
#define STEMPERATURA_H

#include <Sensor.h>


class Stemperatura : public Sensor
{
    private:

    protected:

    public:
        Stemperatura(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Stemperatura();
    bool Run();

    void show(ostream &f = std::cout)
    {
        f << "-----------------" << endl;
        f << Objetos::getTIPO() << endl;
        f << "-----------------" << endl;
        Sensor::show(f);
    }
};

#endif // STEMPERATURA_H
