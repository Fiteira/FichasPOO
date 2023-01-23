#include "MEletrico.h"
#include "Fabrica.h"

/** \brief Construtor do MEletrico
 *
 * \param  int ID, string marca , int posicao Y, int posicao X,int consumoHora e ponteiro Fabrica
 * \author LD & GA
 * \return MEletrico
 *
 */
MEletrico::MEletrico(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Motor(_id,_marca,_posicaoY,_posicaoX,_consumoHora,Pt)
{
    Motor::setTIPO("MEletrico");
    setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
    int minVerde=getPt_Fabrica()->getDefinicaoMEletrico(0);
    int maxVerde=getPt_Fabrica()->getDefinicaoMEletrico(1);
    TEMPERATURA=Uteis::AleatorioDouble((double)minVerde,(double)maxVerde);
}

/** \brief Destrutor da MEletrico
 *
 * \author LD & GA
 *
 */
MEletrico::~MEletrico()
{

}

/** \brief RUN
 *
 * \param
 * \author LD & GA
 * \return true/false
 *
 */
bool MEletrico::RUN()
{
    if(getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << getTIPO()<< "\t" << getID();

        if(getESTADO() == 0)
            cout << "\t" << "PARADO";
        else if (getESTADO() == 1)
            cout << "\t" << "RUN";
        else if (getESTADO() == 2)
            cout << "\t" << "AVARIADO";
        else
            cout << "\t" << "SEM_ESTADO";


        if(getCOR_MOTOR() == 0)
            cout << "\t" << "VERDE";
        else if (getCOR_MOTOR() == 1)
            cout << "\t" << "AMARELO";
        else
            cout << "\t" << "VERMELHO";

        cout << endl;

        if(getPt_Fabrica()->UmaHora())
            getPt_Fabrica()->Manutencao();

        Uteis::Delay(100);
        return false;
    }

    int minAmarelo=getPt_Fabrica()->getDefinicaoMEletrico(2);
    int minVermelho=getPt_Fabrica()->getDefinicaoMEletrico(4);
    int proAvaria=getPt_Fabrica()->getDefinicaoMEletrico(6);


    if(getPt_Fabrica()->UmaHora())
    {
        int consumoHora=getCONSUMO_HORA();
        int consumo=getCONSUMO();

        consumo=consumo+consumoHora;
        setCONSUMO(consumo);

        HORAS_TRABALHO++;

        if(Uteis::ProbabilidadeAcerto(proAvaria))
        {
            setESTADO(ESTADO_AVARIADO);
            ESTOU_AVARIADO();
            int nAvarias=getNumeroDeAvarias();
            nAvarias++;
            setNumeroDeAvarias(nAvarias);
        }
    }

    if(TEMPERATURA >= minAmarelo)
    {
        setCOR_MOTOR(AMARELO);
        ESTOU_QUENTE();
    }

    if(TEMPERATURA >= minVermelho)
    {
        setCOR_MOTOR(VERMELHO);
        STOP();
    }

    cout << getTIPO();
    cout << "\t" << getID();

    if(getESTADO() == 0)
        cout << "\t" << "PARADO";
    else if (getESTADO() == 1)
        cout << "\t" << "RUN";
    else if (getESTADO() == 2)
        cout << "\t" << "AVARIADO";
    else
        cout << "\t" << "SEM_ESTADO";


    if(getCOR_MOTOR() == 0)
        cout << "\t" << "VERDE";
    else if (getCOR_MOTOR() == 1)
        cout << "\t" << "AMARELO";
    else
        cout << "\t" << "VERMELHO";


    cout << fixed;
    cout.precision(2);
    cout << "\t\t" << TEMPERATURA<<endl;
    TEMPERATURA += Uteis::AleatorioDouble(0.1,2);
    Uteis::Delay(100);

    return true;
}

/** \brief START
 *
 * \param
 * \author LD & GA
 * \return true/false
 *
 */
bool MEletrico::START()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
//        cout << getTIPO() <<" ID=[" << getID() << "] START" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        return true;
    }
    else
        cout << getTIPO() <<" ID=[" << getID() << "] Ja esta RUN" << endl;
    return false;
}

/** \brief RESTART
 *
 * \param
 * \author LD & GA
 * \return true/false
 *
 */
bool MEletrico::RESTART()
{
    if (getESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << getTIPO() <<" ID=[" << getID() << "] RUN" << endl;
        cout << getTIPO() <<" ID=[" << getID() << "] INICIAR RESTART" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        cout << getTIPO() <<" ID=[" << getID() << "] PARADO" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        cout << getTIPO() <<" ID=[" << getID() << "] RUN NOVAMENTE" << endl;
        return true;
    }
    else
        cout << getTIPO() <<" ID=[" << getID() << "] Ja esta PARADO" << endl;
    return false;
}

/** \brief RESTART
 *
 * \param
 * \author LD & GA
 * \return true/false
 *
 */
bool MEletrico::STOP()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_PARADO)
    {
//        cout << getTIPO() <<" ID=[" << getID() << "] STOP" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        return true;
    }
    else
    {
        cout << getTIPO() <<" ID=[" << getID() << "] Ja esta parado" << endl;
        return false;
    }
}
