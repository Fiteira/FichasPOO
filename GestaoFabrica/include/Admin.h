#ifndef ADMIN_H
#define ADMIN_H

#include <User.h>


class Admin : public User
{
    private:

    protected:

    public:
        Admin(int _id,string _nome);
        virtual ~Admin();
        bool PossoLISTAR() {return true;}
        bool PossoMANUTENCAO() { return true; }
        bool PossoRUN() { return true; }
        bool PossoREMOVER() { return true; }
        bool PossoADD() { return true; }


};

#endif // ADMIN_H
