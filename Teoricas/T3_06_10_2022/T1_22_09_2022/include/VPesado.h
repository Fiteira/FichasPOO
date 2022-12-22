#ifndef VPESADO_H
#define VPESADO_H

#include <Veiculo.h>


class VPesado : public Veiculo
{
    bool TACOGRAFO;
    public:
        VPesado();
        VPesado(string _m, int _a, bool tac = false);

        void Show();

        virtual ~VPesado();

};

#endif // VPESADO_H
