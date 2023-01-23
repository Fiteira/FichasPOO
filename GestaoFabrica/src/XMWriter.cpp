#include "XMWriter.h"

XMLWriter::XMLWriter()
{

}

XMLWriter::~XMLWriter()
{

}

string XMLWriter::Tabulacao(int n)
{
    string st = "";
    for (int i = 0; i < n; i++)
        st += "\t";
    return st;
}
void XMLWriter::WriteStartDocument(string ficheiro)
{
    NOME_FICHEIRO = ficheiro;
    ofstream F(NOME_FICHEIRO);
    F.close();
}
void XMLWriter::WriteEndDocument()
{

}
void XMLWriter::WriteElementString(string el, string valor)
{
    ofstream F(NOME_FICHEIRO, ios::app);
    F << Tabulacao(LTAGS.size()) << "<" << el << ">" << valor << "</" << el << ">" << endl;
    F.close();
}
void XMLWriter::WriteStartElement(string el)
{
    LTAGS.push_front(el);
    ofstream F(NOME_FICHEIRO, ios::app);
    F << Tabulacao(LTAGS.size()-1) << "<" << el << ">" << endl;
    F.close();
}

void XMLWriter::WriteEndElement()
{
    if (LTAGS.size() > 0)
    {
        string el = LTAGS.front();
        ofstream F(NOME_FICHEIRO, ios::app);
        F << Tabulacao(LTAGS.size()-1) << "</" << el << ">" << endl;
        F.close();
        LTAGS.pop_front();
    }
    else
        cout << "Algo esta errado" << endl;
}
