#ifndef SLUZ_H
#define SLUZ_H

#include <Sensor.h>

class Sluz : public Sensor
{
    private:

    protected:


    public:
        Sluz(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Sluz();
        bool Run();

    void show(ostream &f = std::cout)
    {
        f << "-----------------" << endl;
        f << Objetos::getTIPO() << endl;
        f << "-----------------" << endl;
        Sensor::show(f);
    }
};

#endif // SLUZ_H
