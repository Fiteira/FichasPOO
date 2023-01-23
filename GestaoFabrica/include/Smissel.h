#ifndef SMISSEL_H
#define SMISSEL_H

#include <Sensor.h>


class Smissel : public Sensor
{
    private:

    protected:

    public:
        Smissel(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Smissel();
    bool Run();

    void show(ostream &f = std::cout)
    {
        f << "-----------------" << endl;
        f << Objetos::getTIPO() << endl;
        f << "-----------------" << endl;
        Sensor::show(f);
    }
};

#endif // SMISSEL_H
