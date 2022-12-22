#ifndef XMWRITER_H
#define XMWRITER_H

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <fstream>

class XMLWriter
{
    string NOME_FICHEIRO;
    list<string> LTAGS;

    string Tabulacoes(int N);
public:
    XMLWriter();
    ~XMLWriter();
    void WriteStartDocument(string ficheiro);
    void WriteEndDocument();
    void WriteElementString(string el, string valor);
    void WriteStartElement(string el);
    void WriteEndElement();
};

#endif // XMWRITER_H
