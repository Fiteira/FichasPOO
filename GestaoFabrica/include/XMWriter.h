#ifndef XMWRITER_H
#define XMWRITER_H

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <fstream>
#include "XML.h"

class XMLWriter
{
    string NOME_FICHEIRO;
    list<string> LTAGS;

    string Tabulacao(int n);
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
