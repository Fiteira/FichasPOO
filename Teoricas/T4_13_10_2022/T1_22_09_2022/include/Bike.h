#ifndef BIKE_H
#define BIKE_H

#include <Veiculo.h>


class Bike : public Veiculo
{
    public:
        Bike();
        virtual ~Bike();

        string Get_TIPO() { return "BIKE"; }
        void Run();
        void Parar()
        {
            cout << "Implementado o metodo <" << __FUNCTION__ << ">\n";
            cout << "na classe: " << Get_TIPO() << endl;
        }
};

#endif // BIKE_H
