#ifndef UTEIS_H
#define UTEIS_H
#include <iostream>
#include <string>
using namespace std;
#include <list>
#include <time.h>
#include <math.h>
#include<unistd.h>

class Uteis
{
    public:
        Uteis();
        virtual ~Uteis();
        static void DELAY(int ms)
        {
            int microsecond = 1000;
            usleep(ms * microsecond);

        }
        static int Aleatorio(int _min,int _max)
        {
            return _min + rand()%(_max - _min + 1);
        }
};

#endif // UTEIS_H
