#ifndef VISITANTE_H
#define VISITANTE_H

#include <User.h>


class Visitante : public User
{

    private:

    protected:

    public:
        Visitante(int _id,string _nome);
        virtual ~Visitante();
        virtual bool PossoLISTAR() {return true;}


};

#endif // VISITANTE_H
