#ifndef SFOGO_H
#define SFOGO_H

#include <Sensor.h>


class Sfogo : public Sensor
{
    private:

    protected:

    public:
        Sfogo(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Sfogo();
    bool Run();

    void show(ostream &f = std::cout)
    {
        f << "-----------------" << endl;
        f << Objetos::getTIPO() << endl;
        f << "-----------------" << endl;
        Sensor::show(f);
    }

};

#endif // SFOGO_H
