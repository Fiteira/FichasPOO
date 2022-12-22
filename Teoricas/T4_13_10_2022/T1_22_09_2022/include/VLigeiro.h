#ifndef VLIGEIRO_H
#define VLIGEIRO_H

#include <Veiculo.h>


class VLigeiro : public Veiculo
{
    public:
        VLigeiro();
        VLigeiro(string _m, int _a);
        virtual ~VLigeiro();

        string Get_TIPO() { return "VLIGEIRO"; }
        void Run();

};

#endif // VLIGEIRO_H
