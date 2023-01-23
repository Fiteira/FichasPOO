#ifndef LERXML_H_INCLUDED
#define LERXML_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"
#include "XML.h"
#include "Fabrica.h"
#include "Motor.h"
#include "Sensor.h"
#include "MCombustao.h"

bool Fabrica::Load(const string &fich_xml)
{
   xml_document<> doc;
	xml_node<> * root_node= NULL;

	ifstream theFile (ficheiro);
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]);

	root_node = doc.first_node("Dados");
	xml_node<> * DEFINICOES_node = root_node->first_node("DEFINICOES");
	xml_node<> * NOMEFABRICA_node = DEFINICOES_node->first_node("NOME_FABRICA");
	set_nomeEmpresa(NOMEFABRICA_node->value());

	xml_node<> * HORAINICIO_node = DEFINICOES_node->first_node("HORA_INICIO");
	set_horaInicio(HORAINICIO_node->value());

	xml_node<> * HORAFECHO_node = DEFINICOES_node->first_node("HORA_FECHO");
	set_horaFecho(HORAFECHO_node->value());

	xml_node<> * VIZAVISO_node = DEFINICOES_node->first_node("VIZINHANCA_AVISO");
	set_vizinhancaAviso(VIZAVISO_node->value());

	xml_node<> * DIMFAB_node = DEFINICOES_node->first_node("DIMENSAO_FABRICA");
	set_dimensaoX(DIMFAB_node->value());
    // DEFNICOES MOTOR COMBUSTAO
	xml_node<> * MOTORCOMBUSTAO_node = DEFINICOES_node->first_node("MCOMBUSTAO");
	//verde combustao
    xml_node<> * CVERDE_node = MOTORCOMBUSTAO_node->first_node("VERDE");
    string VERDE= CVERDE_node->value();
    string VERDEMIN;
    string VERDEMAX;

    Uteis::SepararStr(VERDE, VERDEMIN, VERDEMAX);

    DEFI_MCOMBUSTAO(MC_verde_min)= atoi (VERDEMIN);
    DEFI_MCOMBUSTAO(MC_verde_max)= atoi (VERDEMAX);
    //amarelo combustao
	xml_node<> * CAMARELO_node = MOTORCOMBUSTAO_node->first_node("AMARELO");
	string AMARELO= CAMARELO_node->value();
    string AMARELOMIN;
    string AMARELOMAX;

    Uteis::SepararStr(AMARELO, AMARELOMIN, AMARELOMAX);

    DEFI_MCOMBUSTAO(MC_amarelo_min)= atoi (AMARELOMIN);
    DEFI_MCOMBUSTAO(MC_amarelo_max)= atoi (AMARELOMAX);
    //vermelho combustao
	xml_node<> * CVERMELHO_node = MOTORCOMBUSTAO_node->first_node("VERMELHO");
	string VERMELHO= CVERMELHO_node->value();
    string VERMELHOMIN;
    string VERMELHOMAX;

    Uteis::SepararStr(VERMELHO, VERMELHOMIN, VERMELHOMAX);

    DEFI_MCOMBUSTAO(MC_vermelho_min)= atoi (VERMELHOMIN);
    DEFI_MCOMBUSTAO(MC_vermelho_max)= atoi (VERMELHOMAX);
    //prob avaria combustao
	xml_node<> * PROBAVARIA_node = MOTORCOMBUSTAO_node->first_node("PROB_AVARIA");
	//POR TERMINAR PROB AVARIA COMB

    //DEFINICOES MOTOR ELETRICO
    xml_node<> * MOTORELETRICO_node = DEFINICOES_node->first_node("MELETRICO");
    //verde eletrico
    xml_node<> * EVERDE_node = MOTORELETRICO_node->first_node("VERDE");
    string VERDE= EVERDE_node->value();
    string VERDEMIN;
    string VERDEMAX;

    Uteis::SepararStr(VERDE, VERDEMIN, VERDEMAX);

    DEFI_MELETRICO(ME_verde_min)= atoi (VERDEMIN);
    DEFI_MELETRICO(ME_verde_max)= atoi (VERDEMAX);
    //amarelo eletrico
	xml_node<> * EAMARELO_node = MOTORELETRICO_node->first_node("AMARELO");
	string AMARELO= EAMARELO_node->value();
    string AMARELOMIN;
    string AMARELOMAX;

    Uteis::SepararStr(AMARELO, AMARELOMIN, AMARELOMAX);

    DEFI_MELETRICO(ME_amarelo_min)= atoi (AMARELOMIN);
    DEFI_MELETRICO(ME_amarelo_max)= atoi (AMARELOMAX);
    //vermelho eletrico
	xml_node<> * EVERMELHO_node = MOTORELETRICO_node->first_node("VERMELHO");
	string VERMELHO= EVERMELHO_node->value();
    string VERMELHOMIN;
    string VERMELHOMAX;

    Uteis::SepararStr(VERMELHO, VERMELHOMIN, VERMELHOMAX);

    DEFI_MELETRICO(ME_vermelho_min)= atoi (VERMELHOMIN);
    DEFI_MELETRICO(ME_vermelho_max)= atoi (VERMELHOMAX);
    //prob avaria eletrico
	xml_node<> * PROBAVARIA_node = MOTORELETRICO_node->first_node("PROB_AVARIA");
	//POR TERMINAR PROB AVARIA ELET

    //DEFINICOES MOTOR INDUCAO
    xml_node<> * MOTORINDUCAO_node = DEFINICOES_node->first_node("MINDUCAO");
    //verde inducao
    xml_node<> * IVERDE_node = MOTORINDUCAO_node->first_node("VERDE");
    string VERDE= IVERDE_node->value();
    string VERDEMIN;
    string VERDEMAX;

    Uteis::SepararStr(VERDE, VERDEMIN, VERDEMAX);

    DEFI_MINDUCAO(MI_verde_min)= atoi (VERDEMIN);
    DEFI_MINDUCAO(MI_verde_max)= atoi (VERDEMAX);
    //amarelo inducao
	xml_node<> * IAMARELO_node = MOTORINDUCAO_node->first_node("AMARELO");
	string AMARELO= IAMARELO_node->value();
    string AMARELOMIN;
    string AMARELOMAX;

    Uteis::SepararStr(AMARELO, AMARELOMIN, AMARELOMAX);

    DEFI_MINDUCAO(MI_amarelo_min)= atoi (AMARELOMIN);
    DEFI_MINDUCAO(MI_amarelo_max)= atoi (AMARELOMAX);
    //vermelho inducao
	xml_node<> * IVERMELHO_node = MOTORINDUCAO_node->first_node("VERMELHO");
	string VERMELHO= IVERMELHO_node->value();
    string VERMELHOMIN;
    string VERMELHOMAX;

    Uteis::SepararStr(VERMELHO, VERMELHOMIN, VERMELHOMAX);

    DEFI_MINDUCAO(MI_vermelho_min)= atoi (VERMELHOMIN);
    DEFI_MINDUCAO(MI_vermelho_max)= atoi (VERMELHOMAX);
    //prob avaria inducao
	xml_node<> * PROBAVARIA_node = MOTORINDUCAO_node->first_node("PROB_AVARIA");
	//POR TERMINAR PROB AVARIA INDUC
    //SO FALTA AVARIA

	//fors
	//motores
	xml_node<> * MOTORES_node = root_node->first_node("MOTORES");
	for (xml_node<> * MCOMBUSTAO_node = MOTORES_node->first_node("MCOMBUSTAO"); MCOMBUSTAO_node; MCOMBUSTAO_node = MCOMBUSTAO_node->next_sibling("MCOMBUSTAO"))
    {
        xml_node<> * IDCOMBUSTAO_node = MCOMBUSTAO_node->first_node("ID");
        int _id=atoi(IDCOMBUSTAO_node->value());

        xml_node<> * MARCACOMBUSTAO_node = MCOMBUSTAO_node->first_node("MARCA");
        string _marca=MARCACOMBUSTAO_node->value();

        xml_node<> * CONSUMOHCOMBUSTAO_node = MCOMBUSTAO_node->first_node("CONSUMO_HORA");
        int _consumoHora= atoi(CONSUMOHCOMBUSTAO_node->value());

        xml_node<> * POSICAOCOMBUSTAO_node = MCOMBUSTAO_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOCOMBUSTAO_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);


        Motor *m= new MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,this);
        Add(m);
    }
    for (xml_node<> * MELETRICO_node = MOTORES_node->first_node("MELETRICO"); MELETRICO_node; MELETRICO_node = MELETRICO_node->next_sibling("MELETRICO"))
    {
        xml_node<> * IDELETRICO_node = MELETRICO_node->first_node("ID");
        int _id=atoi(IDELETRICO_node->value());

        xml_node<> * MARCAELETRICO_node = MELETRICO_node->first_node("MARCA");
        string _marca=MARCAELETRICO_node->value();

        xml_node<> * CONSUMOHELETRICO_node = MELETRICO_node->first_node("CONSUMO_HORA");
        int _consumoHora= atoi(CONSUMOHELETRICO_node->value());

        xml_node<> * POSICAOELETRICO_node = MELETRICO_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOELETRICO_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);


        Motor *m= new MEletrico(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,this);
        Add(m);
    }
    for (xml_node<> * MINDUCAO_node = MOTORES_node->first_node("MINDUCAO"); MINDUCAO_node; MINDUCAO_node = MINDUCAO_node->next_sibling("MINDUCAO"))
    {
        xml_node<> * IDINDUCAO_node = MINDUCAO_node->first_node("ID");
        int _id=atoi(IDINDUCAO_node->value());

        xml_node<> * MARCAINDUCAO_node = MINDUCAO_node->first_node("MARCA");
        string _marca=MARCAINDUCAO_node->value();

        xml_node<> * CONSUMOHINDUCAO_node = MINDUCAO_node->first_node("CONSUMO_HORA");
        int _consumoHora= atoi(CONSUMOHINDUCAO_node->value());

        xml_node<> * POSICAOINDUCAO_node = MINDUCAO_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOINDUCAO_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);


        Motor *m= new MInducao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,this);
        Add(m);
    }
//sensores
	xml_node<> * SENSORES_node = root_node->first_node("SENSORES");
	for (xml_node<> * STEMP_node = SENSORES_node->first_node("STEMPERATURA"); STEMP_node; STEMP_node = STEMP_node->next_sibling("STEMPERATURA"))
    {
        xml_node<> * IDTEMP_node = STEMP_node->first_node("ID");
        int _id=atoi(IDTEMP_node->value());

        xml_node<> * MARCATEMP_node = STEMP_node->first_node("MARCA");
        string _marca=MARCATEMP_node->value();

        xml_node<> * VALAVISOTEMP_node = STEMP_node->first_node("VALOR_AVISO");
        int _valorAviso= atoi(VALAVISOTEMP_node->value());

        xml_node<> * POSICAOTEMP_node = STEMP_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOTEMP_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);

        xml_node<> * PROBAVARIATEMP_node = STEMP_node->first_node("PROB_AVARIA");
        int _probAvaria= atoi(PROBAVARIATEMP_node->value());

        Sensor *s= new Stemperatura(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso, this)
        Add(s);
    }
    for (xml_node<> * SLUZ_node = SENSORES_node->first_node("SLUZ"); SLUZ_node; SLUZ_node = SLUZ_node->next_sibling("SLUZ"))
    {
        xml_node<> * IDLUZ_node = SLUZ_node->first_node("ID");
        int _id=atoi(IDLUZ_node->value());

        xml_node<> * MARCALUZ_node = SLUZ_node->first_node("MARCA");
        string _marca=MARCALUZ_node->value();

        xml_node<> * VALAVISOLUZ_node = SLUZ_node->first_node("VALOR_AVISO");
        int _valorAviso= atoi(VALAVISOLUZ_node->value());

        xml_node<> * POSICAOLUZ_node = SLUZ_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOLUZ_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);

        xml_node<> * PROBAVARIALUZ_node = SLUZ_node->first_node("PROB_AVARIA");
        int _probAvaria= atoi(PROBAVARIALUZ_node->value());

        Sensor *s= new Sluz(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso, this)
        Add(s);
    }
    for (xml_node<> * SFOGO_node = SENSORES_node->first_node("SFOGO"); SFOGO_node; SFOGO_node = SFOGO_node->next_sibling("SFOGO"))
    {
        xml_node<> * IDFOGO_node = SFOGO_node->first_node("ID");
        int _id=atoi(IDFOGO_node->value());

        xml_node<> * MARCAFOGO_node = SFOGO_node->first_node("MARCA");
        string _marca=MARCAFOGO_node->value();

        xml_node<> * VALAVISOFOGO_node = SFOGO_node->first_node("VALOR_AVISO");
        int _valorAviso= atoi(VALAVISOFOGO_node->value());

        xml_node<> * POSICAOFOGO_node = SFOGO_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOFOGO_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);

        xml_node<> * PROBAVARIAFOGO_node = SFOGO_node->first_node("PROB_AVARIA");
        int _probAvaria= atoi(PROBAVARIAFOGO_node->value());

        Sensor *s= new Sfogo(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso, this)
        Add(s);
    }
    for (xml_node<> * SMISSEL_node = SENSORES_node->first_node("SMISSEL"); SMISSEL_node; SMISSEL_node = SMISSEL_node->next_sibling("SMISSEL"))
    {
        xml_node<> * IDMISSEL_node = SMISSEL_node->first_node("ID");
        int _id=atoi(IDMISSEL_node->value());

        xml_node<> * MARCAMISSEL_node = SMISSEL_node->first_node("MARCA");
        string _marca=MARCAMISSEL_node->value();

        xml_node<> * VALAVISOMISSEL_node = SMISSEL_node->first_node("VALOR_AVISO");
        int _valorAviso= atoi(VALAVISOMISSEL_node->value());

        xml_node<> * POSICAOMISSEL_node = SMISSEL_node->first_node("POSICAO");
        string tempX, tempY;
        Uteis::SepararStr(POSICAOMISSEL_node->value(), tempX, tempY);
        int _posicaoX= atoi(tempX);
        int _posicaoY= atoi (tempY);

        xml_node<> * PROBAVARIAMISSEL_node = SMISSEL_node->first_node("PROB_AVARIA");
        int _probAvaria= atoi(PROBAVARIAMISSEL_node->value());

        Sensor *s= new Smissel(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso, this)
        Add(s);
    }

}
#endif // LERXML_H_INCLUDED
