#include "Motor.h"
#include "Fabrica.h"


/** \brief Construtor do Motor
 *
 * \param  int ID, string marca , int posicao Y, int posicao X,int consumoHora e ponteiro Fabrica
 * \author LD & GA
 * \return Motor
 *
 */
Motor::Motor(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Objetos(_id,_marca,_posicaoY,_posicaoX,Pt)
{
    CONSUMO_HORA=_consumoHora;
    HORAS_TRABALHO=0;
    CONSUMO=0;
}

/** \brief Destrutor da Motor
 *
 * \author LD & GA
 *
 */
Motor::~Motor()
{
//      cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
/** \brief ESTOU_QUENTE envia para a fabirca o motor que esta quente e a fabrica decide o que fazer com ele
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Motor::ESTOU_QUENTE()
{
    if (!getPt_Fabrica())
        return false;

    getPt_Fabrica()->ESTOU_QUENTE(this);
    return true;
}

/** \brief ESTOU_AVARIADO envia para a fabirca o motor que esta avariado e a fabrica decide o que fazer com ele
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Motor::ESTOU_AVARIADO()
{
    if (!getPt_Fabrica())
        return false;

    getPt_Fabrica()->ESTOU_AVARIADO_MOTOR(this);
    return true;

}
