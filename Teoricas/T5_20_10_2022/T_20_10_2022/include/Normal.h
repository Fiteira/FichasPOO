#ifndef NORMAL_H
#define NORMAL_H

#include <User.h>


class Normal : public User
{
    public:
        Normal();
        virtual ~Normal();
        bool PossoADD() { return true; }

};

#endif // NORMAL_H
