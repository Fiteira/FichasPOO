#include "Objetos.h"

/** \brief Construtor do Objetos
 *
 * \param  int ID, string marca , int posicao Y, int posicao X e ponteiro Fabrica
 * \author LD & GA
 * \return Objetos
 *
 */
Objetos::Objetos(int _id,string _marca,int _posicaoY,int _posicaoX,Fabrica *F)
{
    ID=_id;
    MARCA=_marca;
    POSICAO_Y=_posicaoY;
    POSICAO_X=_posicaoX;
    Pt_Fabrica=F;
    numeroDeAvarias=0;
}

/** \brief Destrutor da Objetos
 *
 * \author LD & GA
 *
 */
Objetos::~Objetos()
{
//      cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}

/** \brief show
 *
 * \param  ostream tipo de saida
 * \author LD & GA
 * \return void
 *
 */
void Objetos::show(ostream &f)
{
    f << "ID: " << ID << endl;
    f << "MARCA: " << MARCA << endl;
    f << "POSICAO_Y: " << POSICAO_Y << endl;
    f << "POSICAO_X: " << POSICAO_X << endl;
}
