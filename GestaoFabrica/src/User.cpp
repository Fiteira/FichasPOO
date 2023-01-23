#include "User.h"

/** \brief Construtor do User
 *
 * \param  int ID string Nome
 * \author LD & GA
 * \return User
 *
 */
User::User(int _id,string _nome)
{
  ID=_id;
  NOME=_nome;
}

/** \brief Destrutor do User
 *
 * \author LD & GA
 *
 */
User::~User()
{
//      cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}
