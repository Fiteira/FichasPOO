#ifndef MCOMBUSTAO_H
#define MCOMBUSTAO_H

#include <Motor.h>


class MCombustao : public Motor
{
    public:
        MCombustao(Gestao *pg);
        virtual ~MCombustao();

        bool RUN();
        bool STOP();
        bool START();
};

#endif // MCOMBUSTAO_H
