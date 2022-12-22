#include <iostream>
using namespace std;

#include "XMWriter.h"

int main()
{
    cout << "Hello world!" << endl;
    XMLWriter XX;
    XX.WriteStartDocument("FicheiroDados.xml");
    XX.WriteStartElement("DADOS");
    XX.WriteStartElement("PESSOA"); // Abre o Elemento “PESSOA”
    XX.WriteElementString("NOME","Jose Miguel");
    XX.WriteElementString("IDADE","18");
    XX.WriteStartElement("MORADA");
    XX.WriteElementString("CIDADE","Sao Paulo");
    XX.WriteEndElement();

 //       XX.WriteEndElement();
 //           XX.WriteEndElement();
 //               XX.WriteEndElement();

    XX.WriteEndElement(); // Fecha o Elemento “PESSOA”
    XX.WriteStartElement("PESSOA"); // Abre o Elemento “PESSOA”
    XX.WriteElementString("NOME","Pedrito De Portugal");
    XX.WriteElementString("IDADE","65");
    XX.WriteEndElement(); // Fecha o Elemento “PESSOA”
    XX.WriteEndElement(); // Fecha o Elemento “DADOS”
    XX.WriteEndDocument(); // Fecha o Elemento Documento
}
