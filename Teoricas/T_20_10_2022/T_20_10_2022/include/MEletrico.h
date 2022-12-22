#ifndef MELETRICO_H
#define MELETRICO_H

#include <Motor.h>


class MEletrico : public Motor
{
    public:
        MEletrico(Gestao *pg);
        virtual ~MEletrico();

        bool RUN();
        bool STOP();
        bool START();
};

#endif // MELETRICO_H
