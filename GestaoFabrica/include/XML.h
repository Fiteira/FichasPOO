#ifndef XML_H
#define XML_H
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#include <fstream>
#include <list>
#include <map>




class XML
{
    string TITULO;
    map<string, string> DADOS;
    list<XML *> LFilhos;

    string Tabulacao(int n)
    {
        string s = "";
        for (int i = 0; i < n; i++)
            s += "\t";
        return s;
    }
public:

    XML(string tit)
    {
        TITULO = tit;
    }

    void Add(XML *X)
    {
        LFilhos.push_back(X);
    }

    void Add(string tag, string valor)
    {
        DADOS[tag] = valor;
    }

    string GetAtributo(string tag)
    {
        auto iter = DADOS.find(tag);
        if (iter != DADOS.end())
            return iter->second;
        return "";
    }

    string GetTitulo() { return TITULO; }


    void Show(int ntab = 0)
    {
        string tab = Tabulacao(ntab);
       cout << tab << "[" << TITULO << "]" << endl;
        for(map<string, string>::const_iterator it = DADOS.begin(); it != DADOS.end(); ++it)
            cout << tab << "\t[" << it->first << "] = [" << it->second << "]" << endl;
        for (list<XML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
        {
            (*it)->Show(ntab + 1);
        }
        cout << tab << "[/" << TITULO << "]" << endl;
    }

    ~XML()
    {
        DADOS.clear();
        for (list<XML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
            delete (*it);
        LFilhos.clear();
    }

    XML *GetNode(string tit)
    {
        if (TITULO.compare(tit) == 0) return this;
        for (list<XML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
        {
            XML *F = *it;
            if (F->GetTitulo().compare(tit) == 0)
                return F;
        }
        return NULL;
    }


    int GetNodes(string tit, list<XML *> &lnodes)
    {
        if (TITULO.compare(tit) == 0) lnodes.push_back(this);
        for (list<XML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
        {
            XML *F = *it;
            if (F->GetTitulo().compare(tit) == 0)
                lnodes.push_back(F);
            F->GetNodes(tit, lnodes);
        }
        return lnodes.size();
    }


    static int PartirString(const char *linhaSTR, char *StarTAG, char *TEX, char *EndTAG)
    {
        strcpy(StarTAG, "");
        strcpy(TEX, "");
        strcpy(EndTAG, "");
        int ret = sscanf(linhaSTR, "\t<%[^>]>%[^</]</%[^>]>",StarTAG, TEX, EndTAG);
        return ret;
    }


    static XML* Processar_Parser(string fich)
    {
        ifstream F(fich);
        if (!F.is_open()) return NULL;
        list<XML *> Pilha;
        string Linha;
        char StartTAG[50];
        char EndTAG[50];
        char Conteudo[250];
        XML *Raiz = NULL;
        XML *Obj_Corrente = NULL;
        while (!F.eof())
        {
            getline(F, Linha);
            int res = XML::PartirString(Linha.c_str(), StartTAG, Conteudo, EndTAG);

            if (res == 1)
            {
                char *pch= strchr(StartTAG,'/');
                if (pch == NULL)
                {
                    XML *Filho = new XML(StartTAG);
                    if (Obj_Corrente)
                    {
                        Obj_Corrente->Add(Filho);
                    }else
                    {
                        Raiz = Filho;
                    }
                    Obj_Corrente = Filho;
                    Pilha.push_front(Obj_Corrente);
                }
                else
                {
                    Pilha.pop_front();
                    Obj_Corrente = Pilha.front();
                }
            }
            else
                Obj_Corrente->Add(StartTAG, Conteudo);
        }
        Pilha.clear();
        F.close();
        return Raiz;
    }

};



#endif // XML_H
