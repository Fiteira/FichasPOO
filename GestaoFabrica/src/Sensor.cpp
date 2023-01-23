#include "Sensor.h"
#include "Fabrica.h"

/** \brief Construtor do Sensor
 *
 * \param  int ID, string marca , int posicao Y, int posicao X ,int probabilidade de avaria , int valor aviso e ponteiro para Fabrica
 * \author LD & GA
 * \return Sensor
 *
 */
Sensor::Sensor(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt)
:Objetos(_id,_marca,_posicaoY,_posicaoX,Pt)
{
    PROB_AVARIA=_probAvaria;
    VALOR_AVISO=_valorAviso;
    VALOR_ATUAL=0;
}


/** \brief Destrutor da Sensor
 *
 * \author LD & GA
 *
 */
Sensor::~Sensor()
{

}

/** \brief ESTOU_AVARIADO envia para a fabirca o sensor que esta avariado e a fabrica decide o que fazer com ele
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Sensor::ESTOU_AVARIADO()
{
    if (!getPt_Fabrica())
        return false;

    getPt_Fabrica()->ESTOU_AVARIADO_SENSOR(this);
    return true;

}
