#include "Sfogo.h"
#include "Fabrica.h"


/** \brief Construtor do Sfogo
 *
 * \param  int ID, string marca , int posicao Y, int posicao X ,int probabilidade de avaria , int valor aviso e ponteiro para Fabrica
 * \author LD & GA
 * \return Sfogo
 *
 */
Sfogo::Sfogo(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt)
    :Sensor(_id,_marca,_posicaoY,_posicaoX,_probAvaria,_valorAviso,Pt)
{
    Objetos::setTIPO("Sfogo");

}

/** \brief Destrutor do Sfogo
 *
 * \author LD & GA
 *
 */
Sfogo::~Sfogo()
{

}

/** \brief Run
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Sfogo::Run()
{
    int proAvaria=getProbAvaria();

    if(getESTADO() != ESTADO_SENSOR::RUN)
    {
        if(getPt_Fabrica()->UmaHora())
            getPt_Fabrica()->Manutencao();

        cout << getTIPO();
        cout << "\t" << getID();

        if(getESTADO() == 0)
            cout << "\t" << "RUN";
        else if (getESTADO() == 1)
            cout << "\t" << "AVARIADO";
        else
            cout << "\t" << "SEM_ESTADO";

        cout << "\t  " << getVALOR_AVISO();
        cout << "\t\t    " << getVALOR_ATUAL();

        cout << endl;
        Uteis::Delay(100);

        return false;
    }

    int valorAtual=Uteis::Aleatorio(1,100);
//    int valorAtual=Uteis::Aleatorio(1,10);
    setVALOR_ATUAL(valorAtual);

    if(valorAtual == getVALOR_AVISO())
    {

        system("cls");
        list<Motor *> listaMotores;

        getPt_Fabrica()->Aviso_Fumo(listaMotores, "avisoFumo.mp4");

         cout << "Sensor de fogo ativo ID: " << getID() << endl << endl;

        listaMotores.clear();

        while(!kbhit());
        getPt_Fabrica()->Menu();

        return false;
    }


    if(getPt_Fabrica()->UmaHora())
    {
        if(Uteis::ProbabilidadeAcerto(proAvaria))
        {
            setESTADO(AVARIADO);
            ESTOU_AVARIADO();
            int nAvarias=getNumeroDeAvarias();
            nAvarias++;
            setNumeroDeAvarias(nAvarias);
        }
    }

    cout << getTIPO();
    cout << "\t\t" << getID();

    if(getESTADO() == 0)
        cout << "\t" << "RUN";
    else if (getESTADO() == 1)
        cout << "\t" << "AVARIADO";
    else
        cout << "\t" << "SEM_ESTADO";

    cout << "\t  " << getVALOR_AVISO();
    cout << "\t\t    " << getVALOR_ATUAL();

    cout << endl;
    Uteis::Delay(100);

    return true;
}
