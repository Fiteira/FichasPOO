#ifndef ADMIN_H
#define ADMIN_H

#include <User.h>


class Admin : public User
{
    public:
        Admin();
        virtual ~Admin();
        bool PossoADD() { return true; }
        bool PossoREM() { return true; }
};

#endif // ADMIN_H
