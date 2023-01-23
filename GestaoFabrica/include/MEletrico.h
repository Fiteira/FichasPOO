#ifndef MELETRICO_H
#define MELETRICO_H

#include "Motor.h"


class MEletrico : public Motor
{
    private:

    protected:

    public:
        MEletrico(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt);
        virtual ~MEletrico();
        bool RUN();
        bool START();
        bool RESTART();
        bool STOP();

        void show(ostream &f = std::cout)
        {
            f << "-----------------" << endl;
            f << Objetos::getTIPO() << endl;
            f << "-----------------" << endl;
            Motor::show(f);
        }

};

#endif // MELETRICO_H
