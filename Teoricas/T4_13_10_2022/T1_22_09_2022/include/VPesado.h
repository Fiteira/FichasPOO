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

        string Get_TIPO() { return "VPESADO"; }

        virtual ~VPesado();
        void Run();
};

#endif // VPESADO_H
