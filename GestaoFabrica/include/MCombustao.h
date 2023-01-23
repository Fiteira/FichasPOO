#ifndef MCOMBUSTAO_H
#define MCOMBUSTAO_H

#include "Motor.h"


class MCombustao : public Motor
{
    private:

    protected:

    public:
        MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt);
        virtual ~MCombustao();
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

#endif // MCOMBUSTAO_H
