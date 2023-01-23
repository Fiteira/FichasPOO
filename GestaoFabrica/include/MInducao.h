#ifndef MINDUCAO_H
#define MINDUCAO_H

#include "Motor.h"


class MInducao : public Motor
{
    private:

    protected:

    public:
        MInducao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt);
        virtual ~MInducao();
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

#endif // MINDUCAO_H
