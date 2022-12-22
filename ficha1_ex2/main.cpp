#include <iostream>
#include<string>
#include<list>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

void mostrarLista(list<string>&lista){

    list<string>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
        cout << *it << endl;

}

void mostrarListaInversa(list<string>&lista){

    list<string>::iterator it=lista.end();
    for (--it; it != lista.begin(); --it)
        cout << *it << endl;
    cout << *it << endl;
}

void lerFicheiro(list<string>&lista, string nome_fich)
{
    ifstream F(nome_fich);
    if (!F.is_open())
        return;

    string word;

    while (F >> word)
        lista.push_back(word);
}

void contarPalavras(list<string> &lista)
{
    cout << "Tem " << lista.size() << " Palaras" <<endl;
}
void eliminarPalavraDada(list<string>&lista,string palavra)
{
    lista.remove(palavra);
}

void eliminarPalavraPosicao(list<string>&lista,int posicao)
{
   list<string>::iterator it;
    it=lista.begin();
    advance(it,posicao);
    lista.erase(it);
}

int contarPalavrasInferior(list<string> &lista,int tam=5)
{
    int cont=0;
    list<string>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        if(it->size() < tam)
            cont++;
    }
    return cont;
}

bool existemRepetidos(list<string>lista)
{
     list<string>::iterator it,it2,it_aux;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        it_aux =it;
        for (it2 = ++it_aux; it2 != lista.end(); ++it2)
        {
            if(it->compare(*it2) == 0)
                return true;
        }
    }
    return false;
}

void palavraMaiusculas(list<string>&lista){
    list<string>::iterator it;
       for (it = lista.begin(); it != lista.end(); ++it)
              for (int x = 0; x <(*it).length(); x++)
               if((*it)[x] <= 'z' && (*it)[x] >= 'a')
                (*it)[x] = (*it)[x] - ('a' - 'A');

}

void gravarNoFicheiroPorTam(list<string>&lista1, string nome_ficheiro, int tam = 10){

    ofstream F1;
    F1.open(nome_ficheiro);
    list<string>::iterator it = lista1.end();
    for (it = lista1.begin(); it != lista1.end(); ++it){
        if ((*it).size()<= tam){
            F1 << (*it) << " ";

        }
    }
    F1.close();

}

int main()
{
    list <string> L;
    lerFicheiro(L,"texto.txt");
    cout << "---------------------"<< endl;
    cout << "mostrarLista"<<endl;
    cout << "---------------------"<< endl;
    mostrarLista(L);
    cout << "---------------------"<< endl;
    cout << "MostrarLista Inversa" <<endl;
    cout << "---------------------"<< endl;
    mostrarListaInversa(L);
    cout << "---------------------"<< endl;
    contarPalavras(L);
    cout << "---------------------"<< endl;
    cout << "Tem "<<contarPalavrasInferior(L) << " palavras inferior a 5" << endl;
    cout << "---------------------"<< endl;
    eliminarPalavraDada(L,"qwd");
    mostrarLista(L);
    eliminarPalavraPosicao(L,3);
    cout << "---------------------"<< endl;
    mostrarLista(L);
    return 0;
}
