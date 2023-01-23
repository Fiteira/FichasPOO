#include "Fabrica.h"
#include "Uteis.h"
#include <conio.h>
#include <algorithm>
#include <string.h>

#include "rapidxml.hpp"
#include "XMWriter.h"

/** \brief Construtor da Fabrica, sendo dado o USER actual
 *
 * \param   User autal
 * \author LD & GA
 * \return Fabrica
 *
 */
Fabrica::Fabrica(User *ut)
{
    Ut_Atual = ut;
    LUsers.push_back(ut);

    Rolex = new RelogioFabrica(100);

}

/** \brief Construtor da Fabrica, sendo dado o USER actual e todos os atributos da fabrica
 *
 * \param _nomeEmpresa _horaInicio, _horaFecho, _vizinhancaAviso, _dimensaoX, _dimensaoY, ME_verde_min, ME_verde_max, ME_amarelo_min, ME_amarelo_max, ME_vermelho_min,
 * \param ME_vermelho_max, ME_probAvaria, MC_verde_min, MC_verde_max, MC_amarelo_min, MC_amarelo_max, MC_vermelho_min, MC_vermelho_max, MC_probAvaria, MI_verde_min, MI_verde_max, MI_amarelo_min
 * \param MI_amarelo_max, MI_vermelho_min, MI_vermelho_max, MI_probAvaria
 * \author LD & GA
 * \return Fabrica
 *
 */
Fabrica::Fabrica(User *ut,string _nomeEmpresa,int _horaInicio,int _horaFecho,int _vizinhancaAviso,int _dimensaoX,
                 int _dimensaoY,int ME_verde_min,int ME_verde_max,int ME_amarelo_min,int ME_amarelo_max,
                 int ME_vermelho_min,int ME_vermelho_max,int ME_probAvaria,int MC_verde_min,int MC_verde_max,
                 int MC_amarelo_min,int MC_amarelo_max,int MC_vermelho_min,int MC_vermelho_max,int MC_probAvaria,
                 int MI_verde_min,int MI_verde_max,int MI_amarelo_min,int MI_amarelo_max,int MI_vermelho_min,
                 int MI_vermelho_max,int MI_probAvaria)
{

    Ut_Atual = ut;
    LUsers.push_back(ut);

    Rolex = new RelogioFabrica(200);

    NOME_EMPRESA=_nomeEmpresa;
    HORA_INICIO=_horaInicio;
    HORA_FECHO=_horaFecho;
    VIZINHANCA_AVISO=_vizinhancaAviso;
    DIMENSAO_FABRICA_X=_dimensaoX;
    DIMENSAO_FABRICA_Y=_dimensaoY;

    //DEFENICOES PARA O MOTOR ELETRICO
    DEFI_MELETRICO[0]=ME_verde_min;
    DEFI_MELETRICO[1]=ME_verde_max;
    DEFI_MELETRICO[2]=ME_amarelo_min;
    DEFI_MELETRICO[3]=ME_amarelo_max;
    DEFI_MELETRICO[4]=ME_vermelho_min;
    DEFI_MELETRICO[5]=ME_vermelho_max;
    DEFI_MELETRICO[6]=ME_probAvaria;

    //DEFENICOES PARA O MOTOR COMBUSTAO
    DEFI_MCOMBUSTAO[0]=MC_verde_min;
    DEFI_MCOMBUSTAO[1]=MC_verde_max;
    DEFI_MCOMBUSTAO[2]=MC_amarelo_min;
    DEFI_MCOMBUSTAO[3]=MC_amarelo_max;
    DEFI_MCOMBUSTAO[4]=MC_vermelho_min;
    DEFI_MCOMBUSTAO[5]=MC_vermelho_max;
    DEFI_MCOMBUSTAO[6]=MC_probAvaria;

    //DEFENICOES PARA O MOTOR INDUCAO
    DEFI_MINDUCAO[0]=MI_verde_min;
    DEFI_MINDUCAO[1]=MI_verde_max;
    DEFI_MINDUCAO[2]=MI_amarelo_min;
    DEFI_MINDUCAO[3]=MI_amarelo_max;
    DEFI_MINDUCAO[4]=MI_vermelho_min;
    DEFI_MINDUCAO[5]=MI_vermelho_max;
    DEFI_MINDUCAO[6]=MI_probAvaria;
}

/** \brief Destrutor da Fabrica
 *
 * \author LD & GA
 *
 */

Fabrica::~Fabrica()
{

    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    Uteis::LiberarMemoria(&LUsers);
    Uteis::LiberarMemoria(&LMotores);
    Uteis::LiberarMemoria(&LSensores);

    LMotoresAvariados.clear();
    LMotoresQuentes.clear();
    LSensoresAvariados.clear();
    LObjetos.clear();
    delete(Rolex);
}

/** \brief As configurações da Fábrica são dadas em ficheiro XML, com todas as informações
 *
 * \param ficheiro XML
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Load(const string &ficheiro)
{
    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }





    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return true;
}

/** \brief Adicionar Utilizadores (ter em atenção as regras!)
 *
 * \param User adicionado
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Add(User *ut)
{
    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }

    if(!ut)
    {
        cout << "Nao existe User!" << endl;
        return false;
    }

    LUsers.push_back(ut);
    return true;


}

/** \brief Adicionar Motores (Ver quem pode!)
 *
 * \param Motor adicionado
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Add(Motor *M)
{

    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }
    if(!M)
    {
        cout << "Nao existe Motor!" << endl;
        return false;
    }
    if(M->getPOSICAO_X()>getDIMENSAO_FABRICA_X() || M->getPOSICAO_X()>getDIMENSAO_FABRICA_X())
    {
        cout << "O motor nao pode ficar fora da fabrica" << endl;
        return false;
    }

    list<Objetos *>::iterator it;
    for (it = LObjetos.begin(); it != LObjetos.end(); ++it)
    {
        if((*it)->getPOSICAO_Y() == M->getPOSICAO_Y() && (*it)->getPOSICAO_X() == M->getPOSICAO_X())
        {
            cout << "Tem um objeto nessa posicao" << endl;
            return false;
        }
    }
    LObjetos.push_back(M);
    LMotores.push_back(M);
    return true;

}


/** \brief Adicionar Sensores (Ver quem pode!)
 *
 * \param Sensor adicionado
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Add(Sensor *S)
{

    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }
    if(!S)
    {
        cout << "Nao existe Sensor!" << endl;
        return false;
    }
    if(S->getPOSICAO_X()>getDIMENSAO_FABRICA_X() || S->getPOSICAO_X()>getDIMENSAO_FABRICA_X())
    {
        cout << "O sensor nao pode ficar fora da fabrica" << endl;
        return false;
    }

    list<Objetos *>::iterator it;
    for (it = LObjetos.begin(); it != LObjetos.end(); ++it)
    {
        if((*it)->getPOSICAO_Y() == S->getPOSICAO_Y() && (*it)->getPOSICAO_X() == S->getPOSICAO_X())
        {
            cout << "Tem um objeto nessa posicao" << endl;
            return false;
        }
    }
    LObjetos.push_back(S);
    LSensores.push_back(S);
    return true;

}

/** \brief Listar o estado atual da fábrica;
 *
 * \param output no &f
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::Listar(ostream &f)
{
    if(!Ut_Atual->PossoLISTAR())
        return;

    list<Objetos *>::iterator it;
    for (it = LObjetos.begin(); it != LObjetos.end(); ++it)
        (*it)->show(f);

    while(!kbhit());
    Menu();
}



/** \brief Desligar um motor especifico, dado o seu ID;
 *
 * \param ID Motor
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::Desligar(int id_motor)
{
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getID() == id_motor)
        {
            (*it)->setESTADO(ESTADO_PARADO);
            n=1;
        }
    }
    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
    }
}


/** \brief Saber o estado de um dado Motor, dado o seu ID;
 *
 * \param ID Motor
 * \author LD & GA
 * \return ESTADO_MOTOR
 *
 */
ESTADO_MOTOR Fabrica::Get_ESTADO(int id_motor)
{
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {

        if((*it)->getID() == id_motor)
            return (*it)->getESTADO();
    }

    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
        return ESTADO_MOTOR::SEM_ESTADO;
    }
    return ESTADO_MOTOR::SEM_ESTADO;
}


/** \brief Listar e devolver todos os Motores de um dado Tipo;
 *
 * \param string Tipo e output no &f
 * \author LD & GA
 * \return lista Motores
 *
 */
list<Motor *> Fabrica::Listar_Tipo(string Tipo, ostream &f)
{
    list<Motor *> listaMotores;

    if(!Ut_Atual->PossoLISTAR())
        return listaMotores;

    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getTIPO().compare(Tipo) == 0)
        {
            listaMotores.push_back((*it));
            (*it)->show(f);
        }
    }
    if (listaMotores.empty())
        cout << "Nao tem nenhum Motor com esse tipo" << endl;
    return listaMotores;
}

/** \brief Manutenção de todos os dispositivos (Motores e Sensores!), A manutenção de um motor poderá ser
 *         por exemplo alterar a temperatura para um valor (aleatório) dentro da temperatura VERDE do motor;
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Manutencao()
{
    system("cls");
    if (LMotoresQuentes.empty())
        cout << "Nao tem nenhum Motor Quente" << endl;
    if (LMotoresAvariados.empty())
        cout << "Nao tem nenhum Motor Avariados" << endl;
    if (LSensoresAvariados.empty())
        cout << "Nao tem nenhum Sensores Avariados" << endl;

    list<Motor *>::iterator it;
    for (it = LMotoresQuentes.begin(); it != LMotoresQuentes.end(); ++it)
    {
        cout << "Arrefecer Motor ID: "<< (*it)->getID() << endl;
        (*it)->setCOR_MOTOR(VERDE);
        double temperatura=Uteis::AleatorioDouble((double)getDefinicaoMCombustao(0),(double)getDefinicaoMCombustao(1));
        (*it)->setTEMPERATURA(temperatura);
        (*it)->setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        Uteis::Wait(2);
    }
    LMotoresQuentes.clear();


    list<Motor *>::iterator it1;
    for (it1 = LMotoresAvariados.begin(); it1 != LMotoresAvariados.end(); ++it1)
    {
        cout << "Arranjar Motor ID: "<< (*it1)->getID() << endl;
        (*it1)->setCOR_MOTOR(VERDE);
        double temperatura;

        if((*it1)->getTIPO()=="MCombustao")
            temperatura=Uteis::AleatorioDouble((double)getDefinicaoMCombustao(0),(double)getDefinicaoMCombustao(1));
        else if((*it1)->getTIPO()=="MEletrico")
            temperatura=Uteis::AleatorioDouble((double)getDefinicaoMEletrico(0),(double)getDefinicaoMEletrico(1));
        else if((*it1)->getTIPO()=="MInducao")
            temperatura=Uteis::AleatorioDouble((double)getDefinicaoMInducao(0),(double)getDefinicaoMInducao(1));

        (*it1)->setTEMPERATURA(temperatura);
        (*it1)->setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        Uteis::Wait(2);
    }
    LMotoresAvariados.clear();


    list<Sensor *>::iterator it2;
    for (it2 = LSensoresAvariados.begin(); it2 != LSensoresAvariados.end(); ++it2)
    {
        cout << "Arranjar Sensor ID: "<< (*it2)->getID() << endl;

        (*it2)->setESTADO(ESTADO_SENSOR::RUN);
        Uteis::Wait(2);
    }
    LSensoresAvariados.clear();

    Uteis::Wait(1);
    system("cls");
    return true;
}




/** \brief Quais as Marcas de motores/sensores que mais avariam, deve devolver uma lista (ordenada) do que
 *          mais avaria para o mais fiável
 * \param
 * \author LD & GA
 * \return lista das Marcas de motores/sensores
 *
 */
list<string> Fabrica::Ranking_Dos_Fracos()
{

    list<Objetos *> listaObjetos;

    list<string> listMarcas;

    if(!Ut_Atual->PossoLISTAR())

        for (list<Objetos *>::iterator it = LObjetos.begin(); it != LObjetos.end(); ++it)
        {

            listaObjetos.push_back(*it);

        }

    listaObjetos.assign(LObjetos.begin(),LObjetos.end());

    listaObjetos.sort([](Objetos *o1, Objetos *o2)
    {
        return o1->getNumeroDeAvarias() > o2->getNumeroDeAvarias();
    });


    for (list<Objetos *>::iterator it = listaObjetos.begin(); it != listaObjetos.end(); ++it)
    {

        cout << "TIPO: " << (*it)->getTIPO();
        cout << "| ID: " << (*it)->getID();
        cout << "| MARCA: " << (*it)->getMARCA();
        cout << "| NUMERO DE AVARIAS: " << (*it)->getNumeroDeAvarias() << endl;

        listMarcas.push_back((*it)->getMARCA());
    }

    while(!kbhit());
    system("cls");
    return listMarcas;
}

/** \brief Quais motores que mais trabalharam, deve devolver uma lista (ordenada);
 *
 * \param
 * \author LD & GA
 * \return lista dos Motores
 *
 */
list<Motor *> Fabrica::Ranking_Dos_Mais_Trabalhadores()
{

    list<Motor *> listaMotores;


    if(!Ut_Atual->PossoLISTAR())

        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
        {

            listaMotores.push_back(*it);

        }

    listaMotores.assign(LMotores.begin(),LMotores.end());

    listaMotores.sort([](Motor *m1, Motor *m2)
    {
        return m1->getHorasTrabalho() > m2->getHorasTrabalho();
    });

    for (list<Motor *>::iterator it = listaMotores.begin(); it != listaMotores.end(); ++it)
    {

        cout << "TIPO: " << (*it)->getTIPO();
        cout << "| ID: " << (*it)->getID();
        cout << "| MARCA: " << (*it)->getMARCA();
        cout << "| HORAS TRABALHADAS: " << (*it)->getHorasTrabalho() << endl;

    }

    while(!kbhit());
    system("cls");

    return listaMotores;
}


/** \brief Enviar um relatório em XML, do estado da fábrica;
 *          O relatório deverá ter a informação do total de consumo (do motor) nesse dia;
 * \param
 * \author LD & GA
 * \return
 *
 */
void Fabrica::Relatorio(string fich_xml)
{

//        using namespace rapidxml;
//
//        xml_document<> doc;
//        xml_node<>* DADOS=doc.allocate_node(node_element, "RELATORIO");
//        doc.append_node(DADOS);
//
//
//        xml_node<>* DEFINICOES=doc.allocate_node(node_element, "DEFINICOES");
//        DADOS->append_node(DEFINICOES);
//
//        XMLWriter XML;
//        XML.WriteStartDocument("RelatorioDaFabrica.xml");
//        XML.WriteStartElement("DADOS");
//        XML.WriteStartElement("DEFINICOES");
//
//        xml_node<>* NOME_EMPRESA=doc.allocate_node(node_element, "NOME_EMPRESA");
//        DEFINICOES->append_node(NOME_EMPRESA);
//        string nomeEmpresa= getNOME_EMPRESA();
//
//        xml_node<>* HORA_INICIO=doc.allocate_node(node_element, "HORA_INICIO");
//        DEFINICOES->append_node(HORA_INICIO);
//        int horaInicio= getHoraInicio();
//
//
//        xml_node<>* HORA_FECHO=doc.allocate_node(node_element, "HORA_FECHO");
//        DEFINICOES->append_node(HORA_FECHO);
//        int horaFecho= getHoraFecho();
//
//        xml_node<>* VIZINHANCA_AVISO=doc.allocate_node(node_element, "VIZINHANCA_AVISO");
//        DEFINICOES->append_node(VIZINHANCA_AVISO);
//        int vizinhancaAviso= getVIZINHANCA_AVISO();
//
//        xml_node<>* DIMENSAO_FABRICA=doc.allocate_node(node_element, "DIMENSAO_FABRICA");
//        DEFINICOES->append_node(DIMENSAO_FABRICA);
//        int dimensaoFabricaX= getDIMENSAO_FABRICA_X();
//        int dimensaoFabricaY= getDIMENSAO_FABRICA_Y();
//        ELETRICO
//        xml_node<>* MELETRICO=doc.allocate_node(node_element, "MELETRICO");
//        DEFINICOES->append_node(MELETRICO);
//
//        xml_node<>* VERDEELEC=doc.allocate_node(node_element, "VERDE");
//        MELETRICO->append_node(VERDEELEC);
//        int verdeEletricoMin=getDefinicaoMEletrico(0);
//        int verdeEletricoMax=getDefinicaoMEletrico(1);
//
//        xml_node<>* AMARELOELEC=doc.allocate_node(node_element, "AMARELO");
//        MELETRICO->append_node(AMARELOELEC);
//        int amareloEletricoMin=getDefinicaoMEletrico(2);
//        int amareloEletricoMax=getDefinicaoMEletrico(3);
//
//        xml_node<>* VERMELHOELEC=doc.allocate_node(node_element, "VERMELHO");
//        MELETRICO->append_node(VERMELHOELEC);
//        int vermelhoEletricoMin=getDefinicaoMEletrico(4);
//        int vermelhoEletricoMax=getDefinicaoMEletrico(5);
//
//        xml_node<>* PROBAVARIAELEC=doc.allocate_node(node_element, "PROB_AVARIA");
//        MELETRICO->append_node(PROBAVARIAELEC);
//        float probAvariaEletrico=getDefinicaoMEletrico(6);
//
//        COMBUSTAO
//        xml_node<>* MCOMBUSTAO=doc.allocate_node(node_element, "MCOMBUSTAO");
//        DEFINICOES->append_node(MCOMBUSTAO);
//
//        xml_node<>* VERDECOMB=doc.allocate_node(node_element, "VERDE");
//        MCOMBUSTAO->append_node(VERDECOMB);
//        int verdeCombustaoMin=getDefinicaoMCombustao(0);
//        int verdeCombustaoMax=getDefinicaoMCombustao(1);
//
//        xml_node<>* AMARELOCOMB=doc.allocate_node(node_element, "AMARELO");
//        MCOMBUSTAO->append_node(AMARELOCOMB);
//        int amareloCombustaoMin=getDefinicaoMCombustao(2);
//        int amareloCombustaoMax=getDefinicaoMCombustao(3);
//
//        xml_node<>* VERMELHOCOMB=doc.allocate_node(node_element, "VERMELHO");
//        MCOMBUSTAO->append_node(VERMELHOCOMB);
//        int vermelhoCombustaoMin=getDefinicaoMCombustao(4);
//        int vermelhoCombustaoMax=getDefinicaoMCombustao(5);
//
//        xml_node<>* PROBAVARIACOMB=doc.allocate_node(node_element, "PROB_AVARIA");
//        MCOMBUSTAO->append_node(PROBAVARIACOMB);
//        float probAvariaCombustao=getDefinicaoMCombustao(6);
//
//        INDUCAO
//        xml_node<>* MINDUCAO=doc.allocate_node(node_element, "MINDUCAO");
//        DEFINICOES->append_node(MINDUCAO);
//
//        xml_node<>* VERDEIND=doc.allocate_node(node_element, "VERDE");
//        MINDUCAO->append_node(VERDEIND);
//        int verdeInducaoMin=getDefinicaoMInducao(0);
//        int verdeInducaoMax=getDefinicaoMInducao(1);
//
//        xml_node<>* AMARELOIND=doc.allocate_node(node_element, "AMARELO");
//        MINDUCAO->append_node(AMARELOIND);
//        int amareloInducaoMin=getDefinicaoMInducao(2);
//        int amareloInducaoMax=getDefinicaoMInducao(3);
//
//        xml_node<>* VERMELHOIND=doc.allocate_node(node_element, "VERMELHO");
//        MINDUCAO->append_node(VERMELHOIND);
//        int vermelhoInducaoMin=getDefinicaoMInducao(4);
//        int vermelhoInducaoMax=getDefinicaoMInducao(5);
//
//        xml_node<>* PROBAVARIAIND=doc.allocate_node(node_element, "PROB_AVARIA");
//        MINDUCAO->append_node(PROBAVARIAIND);
//        float probAvariaInducao=getDefinicaoMInducao(6);
//
//        XML.WriteElementString("NOME_EMPRESA", nomeEmpresa);
//        XML.WriteElementString("HORA_INICIO", to_string(horaInicio));
//        XML.WriteElementString("HORA_FECHO", to_string(horaFecho));
//        XML.WriteElementString("VIZINHANCA_AVISO", to_string(vizinhancaAviso));
//        XML.WriteElementString("DIMENSAO_FABRICA", to_string(dimensaoFabricaX)+","+ to_string(dimensaoFabricaY));
//        XML.WriteStartElement("MELETRICO");
//        XML.WriteElementString("VERDE", to_string(verdeEletricoMin)+","+ to_string(verdeEletricoMax));
//        XML.WriteElementString("AMARELO", to_string(amareloEletricoMin)+","+ to_string(amareloEletricoMax));
//        XML.WriteElementString("VERMELHO", to_string(vermelhoEletricoMin)+","+ to_string(vermelhoEletricoMax));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaEletrico));
//        XML.WriteEndElement();
//        XML.WriteStartElement("MCOMBUSTAO");
//        XML.WriteElementString("VERDE", to_string(verdeCombustaoMin)+","+ to_string(verdeCombustaoMax));
//        XML.WriteElementString("AMARELO", to_string(amareloCombustaoMin)+","+ to_string(amareloCombustaoMax));
//        XML.WriteElementString("VERMELHO", to_string(vermelhoCombustaoMin)+","+ to_string(vermelhoCombustaoMax));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaCombustao));
//        XML.WriteEndElement();
//        XML.WriteStartElement("MINDUCAO");
//        XML.WriteElementString("VERDE", to_string(verdeInducaoMin)+","+ to_string(verdeInducaoMax));
//        XML.WriteElementString("AMARELO", to_string(amareloInducaoMin)+","+ to_string(amareloInducaoMax));
//        XML.WriteElementString("VERMELHO", to_string(vermelhoInducaoMin)+","+ to_string(vermelhoInducaoMax));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaInducao));
//        XML.WriteEndElement();
//        XML.WriteEndElement();
//
//
//
//        MOTORES
//        xml_node<>* MOTORES_node=doc.allocate_node(node_element, "MOTORES");
//        DADOS->append_node(MOTORES_node);
//
//        XML.WriteStartElement("MOTORES");
//
//        list<Motor *>::iterator it;
//        for (it = LMotores.begin(); it != LMotores.end(); ++it)
//        {
//        if((*it)->getTIPO().compare("MCombustao") == 0) //MOTORES COMBUSTAO
//        {
//        xml_node<> * MCOMBUSTAO_node = doc.allocate_node(node_element, "MCOMBUSTAO");
//        MOTORES_node->append_node(MCOMBUSTAO_node);
//
//        XML.WriteStartElement("MCOMBUSTAO");
//
//        int idCombustao= (*it)->getID(); //ID COMB
//        xml_node<>* IDCOMB=doc.allocate_node(node_element, "ID", to_string(idCombustao).c_str());
//        MCOMBUSTAO_node->append_node(IDCOMB);
//
//        string marcaCombustao= (*it)->getMARCA(); //MARCA COMB
//        xml_node<>* MARCACOMB=doc.allocate_node(node_element, "MARCA", marcaCombustao.c_str());
//        MCOMBUSTAO_node->append_node(MARCACOMB);
//
//        int consumoHoraCombustao= (*it)->getCONSUMO_HORA(); //CONSUMO POR HORA COMB
//        xml_node<>* CONSUMOCOMB=doc.allocate_node(node_element, "CONSUMO_HORA", to_string(consumoHoraCombustao).c_str());
//        MCOMBUSTAO_node->append_node(CONSUMOCOMB);
//
//        int consumoTotalCombustao= (*it)->getCONSUMO(); //total consumido
//        xml_node<>* CONSUMOTOTALCOMB=doc.allocate_node(node_element, "CONSUMO_TOTAL", to_string(consumoTotalCombustao).c_str());
//        MCOMBUSTAO_node->append_node(CONSUMOTOTALCOMB);
//
//
//        xml_node<>* POSICAOCOMB=doc.allocate_node(node_element, "POSICAO"); //POSICAO COMB
//        MCOMBUSTAO_node->append_node(POSICAOCOMB);
//        int posicaoXCombustao=(*it)->getPOSICAO_X();
//        int posicaoYCombustao=(*it)->getPOSICAO_Y();
//
//
//        XML.WriteElementString("ID", to_string(idCombustao));
//        XML.WriteElementString("MARCA", marcaCombustao);
//        XML.WriteElementString("CONSUMO_HORA", to_string(consumoHoraCombustao));
//        XML.WriteElementString("CONSUMO_TOTAL", to_string(consumoTotalCombustao));
//        XML.WriteElementString("POSICAO", to_string(posicaoXCombustao)+","+ to_string(posicaoYCombustao));
//        XML.WriteEndElement();
//        }
//        if((*it)->getTIPO().compare("MEletrico") == 0) //MOTORES ELETRICOS
//        {
//        xml_node<> * MELETRICO_node = doc.allocate_node(node_element, "MELETRICO");
//        MOTORES_node->append_node(MELETRICO_node);
//
//        XML.WriteStartElement("MELETRICO");
//
//        int idEletrico= (*it)->getID(); //ID ELETRICO
//        xml_node<>* IDELEC=doc.allocate_node(node_element, "ID", to_string(idEletrico).c_str());
//        MELETRICO_node->append_node(IDELEC);
//
//        string marcaEletrico= (*it)->getMARCA(); //MARCA ELETRICO
//        xml_node<>* MARCAELEC=doc.allocate_node(node_element, "MARCA", marcaEletrico.c_str());
//        MELETRICO_node->append_node(MARCAELEC);
//
//        int consumoHoraEletrico= (*it)->getCONSUMO_HORA(); //consumo por hora
//        xml_node<>* CONSUMOELEC=doc.allocate_node(node_element, "CONSUMO_HORA", to_string(consumoHoraEletrico).c_str());
//        MELETRICO_node->append_node(CONSUMOELEC);
//
//        int consumoTotalEletrico= (*it)->getCONSUMO(); //total consumido
//        xml_node<>* CONSUMOTOTALELEC=doc.allocate_node(node_element, "CONSUMO_TOTAL", to_string(consumoTotalEletrico).c_str());
//        MELETRICO_node->append_node(CONSUMOTOTALELEC);
//
//        xml_node<>* POSICAOELEC=doc.allocate_node(node_element, "POSICAO"); //POSICAO ELETRICO
//        MELETRICO_node->append_node(POSICAOELEC);
//        int posicaoXEletrico=(*it)->getPOSICAO_X();
//        int posicaoYEletrico=(*it)->getPOSICAO_Y();
//
//
//        XML.WriteElementString("ID", to_string(idEletrico));
//        XML.WriteElementString("MARCA", marcaEletrico);
//        XML.WriteElementString("CONSUMO_HORA", to_string(consumoHoraEletrico));
//        XML.WriteElementString("CONSUMO_TOTAL", to_string(consumoTotalEletrico));
//        XML.WriteElementString("POSICAO", to_string(posicaoXEletrico)+","+ to_string(posicaoYEletrico));
//        XML.WriteEndElement();
//        }
//        if((*it)->getTIPO().compare("MInducao") == 0) //MOTORES INDUCAO
//        {
//        xml_node<> * MINDUCAO_node = doc.allocate_node(node_element, "MINDUCAO");
//        MOTORES_node->append_node(MINDUCAO_node);
//
//        XML.WriteStartElement("MINDUCAO");
//
//        int idInducao= (*it)->getID(); //ID IND
//        xml_node<>* IDIND=doc.allocate_node(node_element, "ID", to_string(idInducao).c_str());
//        MINDUCAO_node->append_node(IDIND);
//
//        string marcaInducao= (*it)->getMARCA(); //MARCA IND
//        xml_node<>* MARCAIND=doc.allocate_node(node_element, "MARCA", marcaInducao.c_str());
//        MINDUCAO_node->append_node(MARCAIND);
//
//        int consumoHoraInducao= (*it)->getCONSUMO_HORA(); //consumo por hora do motor de inducao
//        xml_node<>* CONSUMOIND=doc.allocate_node(node_element, "CONSUMO_HORA", to_string(consumoHoraInducao).c_str());
//        MINDUCAO_node->append_node(CONSUMOIND);
//
//        int consumoTotalInducao= (*it)->getCONSUMO(); //total consumido
//        xml_node<>* CONSUMOTOTALIND=doc.allocate_node(node_element, "CONSUMO_TOTAL", to_string(consumoTotalInducao).c_str());
//        MINDUCAO_node->append_node(CONSUMOTOTALIND);
//
//        xml_node<>* POSICAOIND=doc.allocate_node(node_element, "POSICAO"); //POSICAO IND
//        MINDUCAO_node->append_node(POSICAOIND);
//        int posicaoXInducao=(*it)->getPOSICAO_X();
//        int posicaoYInducao=(*it)->getPOSICAO_Y();
//
//
//        XML.WriteElementString("ID", to_string(idInducao));
//        XML.WriteElementString("MARCA", marcaInducao);
//        XML.WriteElementString("CONSUMO_HORA", to_string(consumoHoraInducao));
//        XML.WriteElementString("CONSUMO_TOTAL", to_string(consumoTotalInducao));
//        XML.WriteElementString("POSICAO", to_string(posicaoXInducao)+","+ to_string(posicaoYInducao));
//        XML.WriteEndElement();
//        }
//        }
//        XML.WriteEndElement();
//        SENSORES
//        xml_node<>* SENSORES_node=doc.allocate_node(node_element, "SENSORES");
//        DADOS->append_node(SENSORES_node);
//
//        XML.WriteStartElement("SENSORES");
//
//        list<Sensor *>::iterator sit;
//        for (sit = LSensores.begin(); sit != LSensores.end(); ++sit)
//        {
//        if((*sit)->getTIPO().compare("Sluz") == 0) //SENSOR LUZ
//        {
//        xml_node<> * SLUZ_node = doc.allocate_node(node_element, "SLUZ");
//        SENSORES_node->append_node(SLUZ_node);
//
//        XML.WriteStartElement("SLUZ");
//
//        int idLuz= (*sit)-> getID(); //ID LUZ
//        xml_node<>* IDLUZ=doc.allocate_node(node_element, "ID", to_string(idLuz).c_str());
//        SLUZ_node->append_node(IDLUZ);
//
//        string marcaLuz= (*sit)->getMARCA(); //MARCA LUZ
//        xml_node<>* MARCALUZ=doc.allocate_node(node_element, "MARCA", marcaLuz.c_str());
//        SLUZ_node->append_node(MARCALUZ);
//
//        int valAvisoLuz= (*sit)->getVALOR_AVISO(); //VALOR AVISO LUZ
//        xml_node<>* VALOR_AVISOLUZ=doc.allocate_node(node_element, "VALOR_AVISO", to_string(valAvisoLuz).c_str());
//        SLUZ_node->append_node(VALOR_AVISOLUZ);
//
//
//        xml_node<>* POSICAOLUZ=doc.allocate_node(node_element, "POSICAO"); //POSICAO LUZ
//        SLUZ_node->append_node(POSICAOLUZ);
//        int posicaoXLuz=(*sit)->getPOSICAO_X();
//        int posicaoYLuz=(*sit)->getPOSICAO_Y();
//
//        float probAvariaLuz= (*sit)->getProbAvaria(); //PROB AVARIA LUZ
//        xml_node<>* PROB_AVARIALUZ=doc.allocate_node(node_element, "PROB_AVARIA", to_string(probAvariaLuz).c_str());
//        SLUZ_node->append_node(PROB_AVARIALUZ);
//
//
//        XML.WriteElementString("ID", to_string(idLuz));
//        XML.WriteElementString("MARCA", marcaLuz);
//        XML.WriteElementString("VALOR_AVISO", to_string(valAvisoLuz));
//        XML.WriteElementString("POSICAO", to_string(posicaoXLuz)+","+ to_string(posicaoYLuz));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaLuz));
//        XML.WriteEndElement();
//        }
//        if((*sit)->getTIPO().compare("Stemperatura") == 0) //SENSOR TEMPERATURA
//        {
//        xml_node<> * STEMP_node = doc.allocate_node(node_element, "STEMPERATURA");
//        SENSORES_node->append_node(STEMP_node);
//
//        XML.WriteStartElement("STEMPERATURA");
//
//        int idTemp= (*sit)-> getID(); //ID TEMP
//        xml_node<>* IDTEMP=doc.allocate_node(node_element, "ID", to_string(idTemp).c_str());
//        STEMP_node->append_node(IDTEMP);
//
//        string marcaTemp= (*sit)->getMARCA(); //MARCA TEMP
//        xml_node<>* MARCATEMP=doc.allocate_node(node_element, "MARCA", marcaTemp.c_str());
//        STEMP_node->append_node(MARCATEMP);
//
//        int valAvisoTemp= (*sit)->getVALOR_AVISO(); //VALOR AVISO TEMP
//        xml_node<>* VALOR_AVISOTEMP=doc.allocate_node(node_element, "VALOR_AVISO", to_string(valAvisoTemp).c_str());
//        STEMP_node->append_node(VALOR_AVISOTEMP);
//
//
//        xml_node<>* POSICAOTEMP=doc.allocate_node(node_element, "POSICAO"); //POSICAO TEMP
//        STEMP_node->append_node(POSICAOTEMP);
//        int posicaoXTemp=(*sit)->getPOSICAO_X();
//        int posicaoYTemp=(*sit)->getPOSICAO_Y();
//
//        float probAvariaTemp= (*sit)->getProbAvaria(); //PROB AVARIA TEMP
//        xml_node<>* PROB_AVARIATEMP=doc.allocate_node(node_element, "PROB_AVARIA", to_string(probAvariaTemp).c_str());
//        STEMP_node->append_node(PROB_AVARIATEMP);
//
//
//        XML.WriteElementString("ID", to_string(idTemp));
//        XML.WriteElementString("MARCA", marcaTemp);
//        XML.WriteElementString("VALOR_AVISO", to_string(valAvisoTemp));
//        XML.WriteElementString("POSICAO", to_string(posicaoXTemp)+","+ to_string(posicaoYTemp));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaTemp));
//        XML.WriteEndElement();
//        }
//
//        if((*sit)->getTIPO().compare("Sfogo") == 0) //SENSOR FOGO
//        {
//        xml_node<> * SFOGO_node = doc.allocate_node(node_element, "SFOGO");
//        SENSORES_node->append_node(SFOGO_node);
//
//        XML.WriteStartElement("SFOGO");
//
//        int idFogo= (*sit)->getID(); //ID FOGO
//        xml_node<>* IDFOGO=doc.allocate_node(node_element, "ID", to_string(idFogo).c_str());
//        SFOGO_node->append_node(IDFOGO);
//
//        string marcaFogo= (*sit)->getMARCA(); //MARCA FOGO
//        xml_node<>* MARCAFOGO=doc.allocate_node(node_element, "MARCA", marcaFogo.c_str());
//        SFOGO_node->append_node(MARCAFOGO);
//
//        int valAvisoFogo= (*sit)->getVALOR_AVISO(); //VALOR AVISO FOGO
//        xml_node<>* VALOR_AVISOFOGO=doc.allocate_node(node_element, "VALOR_AVISO", to_string(valAvisoFogo).c_str());
//        SFOGO_node->append_node(VALOR_AVISOFOGO);
//
//
//        xml_node<>* POSICAOFOGO=doc.allocate_node(node_element, "POSICAO"); //POSICAO FOGO
//        SFOGO_node->append_node(POSICAOFOGO);
//        int posicaoXFogo=(*sit)->getPOSICAO_X();
//        int posicaoYFogo=(*sit)->getPOSICAO_Y();
//
//        float probAvariaFogo= (*sit)->getProbAvaria(); //PROB AVARIA FOGO
//        xml_node<>* PROB_AVARIAFOGO=doc.allocate_node(node_element, "PROB_AVARIA", to_string(probAvariaFogo).c_str());
//        SFOGO_node->append_node(PROB_AVARIAFOGO);
//
//
//        XML.WriteElementString("ID", to_string(idFogo));
//        XML.WriteElementString("MARCA", marcaFogo);
//        XML.WriteElementString("VALOR_AVISO", to_string(valAvisoFogo));
//        XML.WriteElementString("POSICAO", to_string(posicaoXFogo)+","+ to_string(posicaoYFogo));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaFogo));
//        XML.WriteEndElement();
//        }
//        if((*sit)->getTIPO().compare("Smissel") == 0) //SENSOR MISSEL
//        {
//        xml_node<> * SMISSEL_node = doc.allocate_node(node_element, "SMISSEL");
//        SENSORES_node->append_node(SMISSEL_node);
//
//        XML.WriteStartElement("SMISSEL");
//
//        int idMissel= (*sit)->getID(); //ID MISSEL
//        xml_node<>* IDMISSEL=doc.allocate_node(node_element, "ID", to_string(idMissel).c_str());
//        SMISSEL_node->append_node(IDMISSEL);
//
//        string marcaMissel= (*sit)->getMARCA(); //MARCA MISSEL
//        xml_node<>* MARCAMISSEL=doc.allocate_node(node_element, "MARCA", marcaMissel.c_str());
//        SMISSEL_node->append_node(MARCAMISSEL);
//
//        int valAvisoMissel= (*sit)->getVALOR_AVISO(); //VALOR AVISO MISSEL
//        xml_node<>* VALOR_AVISOFOGO=doc.allocate_node(node_element, "VALOR_AVISO", to_string(valAvisoMissel).c_str());
//        SMISSEL_node->append_node(VALOR_AVISOFOGO);
//
//
//        xml_node<>* POSICAOMISSEL=doc.allocate_node(node_element, "POSICAO"); //POSICAO MISSEL
//        SMISSEL_node->append_node(POSICAOMISSEL);
//        int posicaoXMissel=(*sit)->getPOSICAO_X();
//        int posicaoYMissel=(*sit)->getPOSICAO_Y();
//
//        float probAvariaMissel= (*sit)->getProbAvaria(); //PROB AVARIA MISSEL
//        xml_node<>* PROB_AVARIAMISSEL=doc.allocate_node(node_element, "PROB_AVARIA", to_string(probAvariaMissel).c_str());
//        SMISSEL_node->append_node(PROB_AVARIAMISSEL);
//
//
//        XML.WriteElementString("ID", to_string(idMissel));
//        XML.WriteElementString("MARCA", marcaMissel);
//        XML.WriteElementString("VALOR_AVISO", to_string(valAvisoMissel));
//        XML.WriteElementString("POSICAO", to_string(posicaoXMissel)+","+ to_string(posicaoYMissel));
//        XML.WriteElementString("PROB_AVARIA", to_string(probAvariaMissel));
//        XML.WriteEndElement();
//        }
//        }
//        XML.WriteEndElement(); // encerra sensores
//        XML.WriteEndElement(); //encerra dados
//        XML.WriteEndDocument(); //encerra o ficheiro


}


/** \brief Quando um sensor de Humidade envia um aviso, todos os motores que estão numa dada vizinhança
*           (X) dele devem ser desligados!, o método deve devolver (por parametro) a lista dos Motores que
*            foram desligados, também deve devolver o número de motores que foram desligados;
* \param   devolver a lista dos Motores e dada um X,Y do sensor
* \author LD & GA
* \return int
*
*/
int Fabrica::Aviso_Humidade(list<Motor *> &lm,int x,int y,int nVizinhanca)
{
    int numMotores=0;

    int x1,x2,y1,y2;

    x1=x+nVizinhanca;
    x2=x-nVizinhanca;

    y1=y+nVizinhanca;
    y2=y-nVizinhanca;

    if(x2 < 0)
        x2=0;

    if(y2 < 0)
        y2=0;

//    cout << "x1:" << x1 << " x2:" << x2 << " --- y1:" << y1 << " y2:" << y2 << endl;
    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {


        if( ( (*it)->getPOSICAO_X()>=x2 && (*it)->getPOSICAO_X()<=x1 ) && ( (*it)->getPOSICAO_Y()>=y2 && (*it)->getPOSICAO_Y()<=y1 ))
        {
            (*it)->STOP();
            numMotores++;
            lm.push_back(*it);
        }
    }

    return numMotores;
}


/** \brief Quando um sensor de FUMO envia um aviso, todos os motores devem ser desligados e deve ser
 *           invocado um video mostrando as zonas de saída da fábrica;
 * \param   devolver a lista dos Motores e video
 * \author LD & GA
 * \return int
 *
 */
int Fabrica::Aviso_Fumo(list<Motor *> &lm, string fich_video)
{
    int numMotores=0;
    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        (*it)->STOP();
        numMotores++;
        lm.push_back(*it);
    }
    system(fich_video.c_str());
    return numMotores;
}

/** \brief No caso de o sensor de LUZ enviar um aviso (por exemplo quando a luz é inferior a um dado valor!)
 *           deve passar um video desejando um bom regresso a casa!, pois o tempo está a escurecer e aproximase a
 *           hora de dormir.
 * \param   video
 * \author LD & GA
 * \return int
 *
 */
int Fabrica::Aviso_Luz(string fich_video)
{

    system("cls");
    cout << "BOM REGRESSO A CASA" << endl;
    system(fich_video.c_str());
    Uteis::Wait(2);
    Stop();
    return 0;
}

/** \brief No caso de o sensor de MÍSSEL enviar um aviso (por exemplo quando o valor for 1) deve passar um
 *   video mostrando os abrigos e a fábrica deve desligar-se completamente, guardando o estado atual!.
 *
 * \param   video, ficheiro de testo
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::Aviso_Missel(string fvideo, string festado)
{
    system(fvideo.c_str());
    Stop();

    ofstream f;
    f.open(festado);
    Listar(f);
    f.close();
}



//-----------------------Funcoes Extras------------------------//

/** \brief Desligar motores
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Stop()
{
    if(!Ut_Atual->PossoRUN())
        return false;
    cout << "Fabrica a desligar Motores" << endl;
    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
        (*it)->STOP();

    while(!kbhit());
    system("cls");
    return true;
}

/** \brief Ligar motores
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::LigarMotores()
{
    if(!Ut_Atual->PossoRUN())
        return false;
    cout << "Fabrica a Ligar todos os Motores" << endl;
    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
        (*it)->START();

    Uteis::Wait(1);
    system("cls");
    return true;
}

/** \brief Ligar sensor
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::LigarSensores()
{
    if(!Ut_Atual->PossoRUN())
        return false;
    cout << "Fabrica a Ligar todos os Sensores" << endl;
    list<Sensor *>::iterator it;
    for (it = LSensores.begin(); it != LSensores.end(); ++it)
    {
        (*it)->setESTADO(RUN);
        cout << "Motor ID: [" << (*it)->getID() << "] esta a ligar"<< endl;
    }

    while(!kbhit());
    system("cls");

    return true;
}

//-----------------------Funcoes Extras------------------------//

/** \brief Run motores
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Run()
{
    if(!Ut_Atual->PossoRUN())
        return false;

//    if(!TempoFabrica())
//    {
//        //ir para o menu
//        return false;
//    }

    do
    {
        MostrarHoraAtual();
        cout << "---------------------------MOTORES--------------------------" << endl;
        cout << "TIPO\t       ID\tESTADO\t ESTADO_COR\tTEMPERATURA" << endl;
        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
        {
            (*it)->RUN();
        }
        cout << "--------------------------SENSORES-------------------------" << endl;
        cout << "TIPO\t       ID\tESTADO\t VALOR AVISO\t VALOR ATUAL" << endl;
        for (list<Sensor *>::iterator it = LSensores.begin(); it != LSensores.end(); ++it)
        {
            (*it)->Run();
        }
        Uteis::Delay(200);
        system("cls");
    }
    while(!kbhit());
    Menu();
//    printf( "\ntecla clicada '%c' \n", _getch());
    return true;
}


/** \brief Ligar motor
 *
 * \param id motor
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::Ligar(int id_motor)
{
    if(!Ut_Atual->PossoRUN())
        return;
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getID() == id_motor)
        {
            (*it)->setESTADO(ESTADO_RUN);
            cout << "Motor ID: [" << id_motor << "] esta a ligar"<< endl;
            n=1;
        }
    }
    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
    }
}

/** \brief Motor ESTOU_QUENTE meter o motor na lista de motores quentes
 *
 * \param objeto motor
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::ESTOU_QUENTE(Motor *M)
{

    list<Motor *>::iterator it;
    for (it = LMotoresQuentes.begin(); it != LMotoresQuentes.end(); ++it)
    {
        if((*it)->getID() == M->getID())
            return false;
    }
    LMotoresQuentes.push_back(M);
    return true;
}


/** \brief Motor ESTOU_AVARUADO meter o motor na lista de motores avariados
 *
 * \param objeto motor
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::ESTOU_AVARIADO_MOTOR(Motor *M)
{


    list<Motor *>::iterator it;
    for (it = LMotoresAvariados.begin(); it != LMotoresAvariados.end(); ++it)
    {
        if((*it)->getID() == M->getID())
            return false;
    }
    LMotoresAvariados.push_back(M);

    return true;
}

/** \brief Motor ESTOU_AVARUADO meter o sensor na lista de motores avariados
 *
 * \param objeto sensor
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::ESTOU_AVARIADO_SENSOR(Sensor *S)
{

    list<Sensor *>::iterator it;
    for (it = LSensoresAvariados.begin(); it != LSensoresAvariados.end(); ++it)
    {
        if((*it)->getID() == S->getID())
            return false;
    }
    LSensoresAvariados.push_back(S);

    return true;
}


/** \brief MostarHoraAtual
 *
 * \param
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::MostrarHoraAtual()
{
    time_t hora_atual = Rolex->GetTime();
    tm* now = localtime(&hora_atual);
    int hora=now->tm_hour;
    int minutos=now->tm_min;
    int segundos=now->tm_sec;
    cout << "Hora atual = " << hora << ":" << minutos << ":" << segundos << endl;
}


/** \brief Tempo atual
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::TempoFabrica()
{
    time_t hora_atual = Rolex->GetTime();
    tm* now = localtime(&hora_atual);
    int hora=now->tm_hour;
//    int hora;
//    Uteis::HoraAtual(hora);

    if(hora<=getHoraInicio() || hora>=getHoraFecho())
    {
        system("cls");
        cout << "FABRICA A FECHAR" << endl;
        Stop();
        return false;
    }
    else
        return true;
}

/** \brief Se passar uma hora retorna true se nao false
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::UmaHora()
{
    time_t hora_atual = Rolex->GetTime();
    tm* now = localtime(&hora_atual);
    int minutos=now->tm_min;

    //int segundos=now->tm_sec;
    // devia de ser 0 min e 0 seg mas como estamos numa simulacao pode nao chegar a esses valores

    if(minutos == 0 || minutos <=2)
    {
//        system("cls");
//        cout << "1 HORA" << endl;
//        Uteis::Wait(1);
        return true;
    }

    else
        return false;
}



/** \brief Desligar Motor dado um Id
 *
 * \param   id motor
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::DesligarMotor(int id_motor)
{
    if(!Ut_Atual->PossoRUN())
        return;
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getID() == id_motor)
        {
            (*it)->setESTADO(ESTADO_PARADO);
            cout << "Motor ID: [" << id_motor << "] esta a desligar"<< endl;
            n=1;
        }
    }
    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
    }
}




//---------------------------Menu----------------------------//

/** \brief Menu principal
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Menu()
{
    system("cls");
    do
    {
        int opcao;
        cout << "********************************************************************" << endl;
        cout << "*                                                                  *" << endl;
        cout << "*                         Menu Fabrica                             *" << endl;
        cout << "*                                                                  *" << endl;
        cout << "********************************************************************" << endl;
        cout << endl;
        cout << endl;
        cout << " 1 - RUN Fabrica" << endl;
        cout << " 2 - Add User" << endl;
        cout << " 3 - Add Motor" << endl;
        cout << " 4 - Add Sensor" << endl;
        cout << " 5 - Listar" << endl;
        cout << " 6 - Listar Tipo Motor" << endl;
        cout << " 7 - Ligar Motores" << endl;
        cout << " 8 - Ligar Motor por ID" << endl;
        cout << " 9 - Ligar Sensores" << endl;
        cout << " 10 - Desligar motores" << endl;
        cout << " 11 - Desligar Motor por ID" << endl;
        cout << " 12 - Manutencao" << endl;
        cout << " 13 - Ranking Dos Fracos" << endl;
        cout << " 14 - Ranking Dos Mais Trabalhadores" << endl;
        cout << " 15 - Relatorio" << endl;

        cout << " 0 - Sair" << endl;

        cout << "Selecione uma opcao: ";
        cin >> opcao;
        switch(opcao)
        {
        case 1:
            system("cls");
            Run();
            break;
        case 2:
            system("cls");
            MenuAddUser();
            break;
        case 3:
            system("cls");
            MenuAddMotor();
            break;
        case 4:
            system("cls");
            MenuAddSensor();
            break;
        case 5:
            system("cls");
            Listar();
            break;
        case 6:
            system("cls");
            MenuListarMotorTipo();
            break;
        case 7:
            system("cls");
            LigarMotores();
            break;
        case 8:
            system("cls");
            MenuLigarMotorID();
            break;
        case 9:
            system("cls");
            LigarSensores();
            break;
        case 10:
            system("cls");
            Stop();
            break;
        case 11:
            system("cls");
            MenuDesligarMotorID();
            break;
        case 12:
            system("cls");
            Manutencao();
            break;
        case 13:
            system("cls");
            Ranking_Dos_Fracos();
            break;
        case 14:
            system("cls");
            Ranking_Dos_Mais_Trabalhadores();
            break;
        case 15:
            system("cls");
            Relatorio("XML.xml");
            break;
        case 0:
            return true;
            break;
        default:
            system("cls");
            Menu();
            break;
        }
    }
    while(1);
    return true;
}


/** \brief Menu Add User
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::MenuAddUser()
{
    system("cls");
    if(!Ut_Atual->PossoADD())
    {
        cout << "Não tem permissao!" << endl;
        Menu();
        return false;
    }
    int opcao;
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                         Menu Add User                            *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << " 1 - ADD Admin" << endl;
    cout << " 2 - ADD Normal" << endl;
    cout << " 3 - ADD Visitante" << endl;

    cout << "Selecione uma opcao: ";
    cin >> opcao;

    if(opcao < 1 || opcao > 3)
    {
        MenuAddUser();
    }

    int id=LUsers.back()->getId();
    id++;

    User *U;
    string nome;
    if(opcao == 1)
    {
        cout << "Nome do Admin: ";
        cin >> nome;

        U=new Admin(id,nome);
        Add(U);
        system("cls");
    }
    else if(opcao == 2)
    {
        cout << "Nome do Normal: ";
        cin >> nome;

        U=new Normal(id,nome);
        Add(U);
        system("cls");
    }
    else if(opcao == 3)
    {
        cout << "Nome do Visitante: ";
        cin >> nome;

        U=new Visitante(id,nome);
        Add(U);
        system("cls");
    }
    cout << "Guardado Com Sucesso!!" << endl;
    Uteis::Wait(2);
    system("cls");
    return true;
}

/** \brief Menu Add Motor
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::MenuAddMotor()
{
    system("cls");
    if(!Ut_Atual->PossoADD())
    {
        cout << "Não tem permissao!" << endl;
        Menu();
        return false;
    }
    int opcao;
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                         Menu Add Motor                           *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << " 1 - ADD MCombustao" << endl;
    cout << " 2 - ADD MEletrico" << endl;
    cout << " 3 - ADD MInducao" << endl;

    cout << "Selecione uma opcao: ";
    cin >> opcao;

    if(opcao < 1 || opcao > 3)
    {
        MenuAddMotor();
    }

    int id=LObjetos.back()->getID();
    id++;

    Motor *M;

    string marca;
    int posicaoX;
    int posicaoY;
    int consumo;

    if(opcao == 1)
    {
        cout << "---MCombustao---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nConsumo por hora: ";
        cin >> consumo;

        M=new MCombustao(id,marca,posicaoY,posicaoX,consumo,this);
        Add(M);

        system("cls");
    }
    else if(opcao == 2)
    {
        cout << "---MEletrico---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nConsumo por hora: ";
        cin >> consumo;

        M=new MEletrico(id,marca,posicaoY,posicaoX,consumo,this);
        Add(M);

        system("cls");
    }
    else if(opcao == 3)
    {
        cout << "---MInducao---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nConsumo por hora: ";
        cin >> consumo;

        M=new MInducao(id,marca,posicaoY,posicaoX,consumo,this);
        Add(M);

        system("cls");
    }
    cout << "Guardado Com Sucesso!!" << endl;
    Uteis::Wait(2);
    system("cls");
    return true;
}

/** \brief Menu Add Sensor
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::MenuAddSensor()
{
    system("cls");
    if(!Ut_Atual->PossoADD())
    {
        cout << "Não tem permissao!" << endl;
        Menu();
        return false;
    }
    int opcao;
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                         Menu Add Sensor                          *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << " 1 - ADD Sfogo" << endl;
    cout << " 2 - ADD Sluz" << endl;
    cout << " 3 - ADD Smissel" << endl;
    cout << " 4 - ADD Stemperatura" << endl;

    cout << "Selecione uma opcao: ";
    cin >> opcao;

    if(opcao < 1 || opcao > 4)
    {
        MenuAddSensor();
    }

    int id=LObjetos.back()->getID();
    id++;

    Sensor *S;
    string marca;
    int posicaoX;
    int posicaoY;
    int probAvaria;
    int valorAviso;

    if(opcao == 1)
    {
        cout << "---Sfogo---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nProbabilidade de avaria: ";
        cin >> probAvaria;
        cout << "\nValor Aviso: ";
        cin >> valorAviso;

        S=new Sfogo(id,marca,posicaoY,posicaoX,probAvaria,valorAviso,this);
        Add(S);

        system("cls");
    }
    else if(opcao == 2)
    {
        cout << "---Sluz---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nProbabilidade de avaria: ";
        cin >> probAvaria;
        cout << "\nValor Aviso: ";
        cin >> valorAviso;

        S=new Sluz(id,marca,posicaoY,posicaoX,probAvaria,valorAviso,this);
        Add(S);

        system("cls");
        system("cls");
    }
    else if(opcao == 3)
    {
        cout << "---Smissel---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nProbabilidade de avaria: ";
        cin >> probAvaria;
        cout << "\nValor Aviso: ";
        cin >> valorAviso;

        S=new Smissel(id,marca,posicaoY,posicaoX,probAvaria,valorAviso,this);
        Add(S);

        system("cls");
    }
    else if(opcao == 4)
    {
        cout << "---Stemperatura---" << endl;
        cout << "Posicao Fabrica X:" << getDIMENSAO_FABRICA_X() << " Y:" << getDIMENSAO_FABRICA_Y() << endl;
        cout << endl;

        cout << "Marca: ";
        cin >> marca;
        cout << "\nPosicao Y: ";
        cin >> posicaoY;
        cout << "\nPosicao X: ";
        cin >> posicaoX;
        cout << "\nProbabilidade de avaria: ";
        cin >> probAvaria;
        cout << "\nValor Aviso: ";
        cin >> valorAviso;

        S=new Stemperatura(id,marca,posicaoY,posicaoX,probAvaria,valorAviso,this);
        Add(S);

        system("cls");
    }


    cout << "Guardado Com Sucesso!!" << endl;
    Uteis::Wait(2);
    system("cls");
    return true;
}

/** \brief Menu Listar Motor Por Tipo
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::MenuListarMotorTipo()
{
    system("cls");
    if(!Ut_Atual->PossoLISTAR())
    {
        cout << "Não tem permissao!" << endl;
        Menu();
        return false;
    }
    int opcao;
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                   Menu Listar Motor Por Tipo                     *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << " 1 - Litar Tipo MCombustao" << endl;
    cout << " 2 - Litar Tipo MEletrico" << endl;
    cout << " 3 - Litar Tipo MInducao" << endl;

    cout << "Selecione uma opcao: ";
    cin >> opcao;

    if(opcao < 1 || opcao > 3)
    {
        MenuListarMotorTipo();
    }

    if(opcao == 1)
    {
        system("cls");
        Listar_Tipo("MCombustao",cout);

    }
    else if(opcao == 2)
    {
        system("cls");
        Listar_Tipo("MEletrico",cout);
    }
    else if(opcao == 3)
    {
        system("cls");
        Listar_Tipo("MInducao",cout);
    }

    while(!kbhit());
    system("cls");

    Menu();
    return true;
}

/** \brief Menu Ligar Motor ID
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::MenuLigarMotorID()
{

    int ID;
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                   Menu Ligar Motor Pelo ID                       *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "ID do Motor: ";
    cin >> ID;

    Ligar(ID);

    while(!kbhit());
    system("cls");

    return true;
}


/** \brief Menu Desligar Motor ID
 *
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::MenuDesligarMotorID()
{

    int ID;
    cout << "********************************************************************" << endl;
    cout << "*                                                                  *" << endl;
    cout << "*                   Menu Desligar Motor Pelo ID                    *" << endl;
    cout << "*                                                                  *" << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "ID do Motor: ";
    cin >> ID;

    DesligarMotor(ID);

    while(!kbhit());
    system("cls");

    return true;
}

