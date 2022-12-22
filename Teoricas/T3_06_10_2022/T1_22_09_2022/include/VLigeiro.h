#ifndef VLIGEIRO_H
#define VLIGEIRO_H

#include <Veiculo.h>


class VLigeiro : public Veiculo
{
    public:
        VLigeiro();
        VLigeiro(string _m, int _a);
        virtual ~VLigeiro();

};

#endif // VLIGEIRO_H
