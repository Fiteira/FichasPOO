#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#include <fstream>
#include <list>
#include <map>
    #include <conio.h>

int PartirString(const char *linhaSTR, char *StarTAG, char *TEX, char *EndTAG)
{
    //cout << "Linha = [" << linhaSTR << "]"<< endl;
    strcpy(StarTAG, "");
    strcpy(TEX, "");
    strcpy(EndTAG, "");
    int ret = sscanf(linhaSTR, "\t<%[^>]>%[^</]</%[^>]>",StarTAG, TEX, EndTAG);
    //cout << "RET = " << ret << endl;
    //cout << "StarTAG = ["<<StarTAG<<"]" << endl;
    //cout << "TEX = ["<<TEX<<"]" << endl;
    //cout << "EndTAG = ["<<EndTAG<<"]" << endl;
    return ret;
}

/** \brief Class de Nos XML, a ideia base é ter um nó Raiz com atributos
*  Depois esse nó pode ter mais sub-nós aninhados...
*  Algoritmo recursivo muito eficiente
*/
class ObjectoXML
{
    string TITULO;
    map<string, string> DADOS;
    list<ObjectoXML *> LFilhos;

    string Tabulacao(int n)
    {
        string s = "";
        for (int i = 0; i < n; i++)
            s += "\t";
        return s;
    }
public:
    /** \brief Cria um NO XML com uma dado titulo
     *
     * \param tit string
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    ObjectoXML(string tit)
    {
        TITULO = tit;
    }
    /** \brief Adiciona o NO XML ao No Corrente
     *
     * \param X ObjectoXML*
     * \return void
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    void Add(ObjectoXML *X)
    {
        LFilhos.push_back(X);
    }

    /** \brief Adiciona um atributo ao NO EXML
     *
     * \param tag string
     * \param valor string
     * \return void
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    void Add(string tag, string valor)
    {
        DADOS[tag] = valor;
    }

    /** \brief Devolve o Valor de uma dado atributo identificado por tag
     *         No caso de não existir devolve string vazia
     *
     * \param tag string
     * \return string
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    string GetAtributo(string tag)
    {
        auto iter = DADOS.find(tag);
        if (iter != DADOS.end())
            return iter->second;
        return "";
    }

    /** \brief Devolve o nome do NO
     *
     * \return string
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    string GetTitulo() { return TITULO; }

    /** \brief Permite mostrar toda a árvore dos NOS, por vezes designado como XDocument
     *
     * \param 0 int ntab=
     * \return void
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    void Show(int ntab = 0)
    {
        string tab = Tabulacao(ntab);
        cout << tab << "[" << TITULO << "]" << endl;
        for(map<string, string>::const_iterator it = DADOS.begin(); it != DADOS.end(); ++it)
            cout << tab << "\t[" << it->first << "] = [" << it->second << "]" << endl;
        for (list<ObjectoXML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
            (*it)->Show(ntab + 1);
        cout << tab << "[" << TITULO << "]" << endl;
    }

    /** \brief Destructor do NO XML, permite libertar a memória alocada
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    ~ObjectoXML()
    {
        DADOS.clear();
        for (list<ObjectoXML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
            delete (*it);
        LFilhos.clear();
    }

    /** \brief Devolve um NO com um dado titulo (tit)
     *
     * \param tit string
     * \return ObjectoXML*
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    ObjectoXML *GetNode(string tit)
    {
        if (TITULO.compare(tit) == 0) return this;
        for (list<ObjectoXML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
        {
            ObjectoXML *F = *it;
            if (F->GetTitulo().compare(tit) == 0)
                return F;
        }
        return NULL;
    }

    /** \brief Devolve (por parametro) todos os NOS com um dado 'tit'
     *
     * \param tit string
     * \param lnodes list<ObjectoXML *>&
     * \return int devolve o número de nós
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    int GetNodes(string tit, list<ObjectoXML *> &lnodes)
    {
        if (TITULO.compare(tit) == 0) lnodes.push_back(this);
        for (list<ObjectoXML *>::iterator it = LFilhos.begin(); it != LFilhos.end(); ++it)
        {
            ObjectoXML *F = *it;
            if (F->GetTitulo().compare(tit) == 0)
                lnodes.push_back(F);
            F->GetNodes(tit, lnodes);
        }
        return lnodes.size();
    }
    /** \brief Função que permite criar criar toda a árvore de Nós XML
     *
     * \param fich string
     * \return ObjectoXML*
     * \authors Docentes de POO
     * \version 1.0 a versao 2.0 sera feita pelos alunos de POO
     * \date 14/11/2022
     */
    static ObjectoXML *Processar_Parser(string fich)
    {
        ifstream F(fich);
        if (!F.is_open()) return NULL;
        list<ObjectoXML *> Pilha;
        string Linha;
        char StartTAG[50];
        char EndTAG[50];
        char Conteudo[250];
        ObjectoXML *Raiz = NULL;
        ObjectoXML *Obj_Corrente = NULL;
        while (!F.eof())
        {
            getline(F, Linha);
            int res = PartirString(Linha.c_str(), StartTAG, Conteudo, EndTAG);
    /*
            cout << "RES = " << res << endl;
            cout << "\t StartTAG = [" << StartTAG << "]" << endl;
            cout << "\t Conteudo = [" << Conteudo << "]" << endl;
            cout << "\t EndTAG = [" << EndTAG << "]" << endl;
    */
            if (res == 1)
            {
                char *pch= strchr(StartTAG,'/');
                if (pch == NULL)
                {
                    ObjectoXML *Filho = new ObjectoXML(StartTAG);
                    if (Obj_Corrente)
                        Obj_Corrente->Add(Filho);
                    else
                        Raiz = Filho;

                    Obj_Corrente = Filho;
                    Pilha.push_front(Obj_Corrente);
                }
                else
                { // ACIDENTALMENTE O PROF. APAGOU 2 LINHAS QUE AQUI FALTAM!
                    // PEDE-SE AOS ALUNOS QUE AJUDEM NA RECUPERAÇÃO DAS LINHAS!!!!!!

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


/** \brief Esta função foi para experimentar a função de PartirString
 *
 * \return void
 *
 */
void Experiencia_Partir_String()
{
    char StartTAG[50];
    char EndTAG[50];
    char Conteudo[50];

    //string s = "<NOME_EMPRESA>Empresa da Minha Terra</NOME_EMPRESA>";
    string s = "</MCOMBUSTAO>";
    int res = PartirString(s.c_str(), StartTAG, Conteudo, EndTAG);

    cout << "RES = " << res << endl;
    cout << "StartTAG = [" << StartTAG << "]" << endl;
    cout << "Conteudo = [" << Conteudo << "]" << endl;
    cout << "EndTAG = [" << EndTAG << "]" << endl;
}

/** \brief Funcao feita a pedido de alunos..., pois tinham dificuldade em pesquisar na NET!!!!
 *
 * \return void
 *
 */
void Experiencia_KBHit()
{
    int i = 0;
    char ch;
    while (1)
    {
        if ( kbhit() ) {
            ch = getchar();
            cout << "Caracter = [" << ch << "]" << endl;
        }
        cout << i++ << endl;
    }
}

int main()
{
    cout << "Parser de um XML: deve ser dado o ficheiro por linhas!" << endl;
    cout << "O parser ainda esta em modo de teste" << endl;
    cout << "Seria interessante os alunos acrescentarem validacoes" << endl;
    cout << "Por ex. o formato pode estar errado!" << endl;
    cout << "Tags que não estão na ordem correcta (abertura e fecho)" << endl;
    ObjectoXML *XML = ObjectoXML::Processar_Parser("Empresa1XML.xml");
    if (XML)
        XML->Show(0);
    else
        cout << "XML e NULLLLL" << endl;

    ObjectoXML *X = XML->GetNode("DEFINICOES");
    X->Show();

    cout << "GetAtributo(DIMENSAO_FABRICA) = " << X->GetAtributo("DIMENSAO_FABRICA") << endl;

    list<ObjectoXML *> lm;
    XML->GetNodes("MCOMBUSTAO", lm);
    for (list<ObjectoXML *>::iterator it = lm.begin(); it != lm.end(); ++it)
       (*it)->Show();

    delete XML;
    return 0;
}
