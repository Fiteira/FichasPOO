#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "Pessoa.h"
#include "Conta.h"

class Banco
{
    list<Pessoa *> LP;
    list<Conta *> LC;
    string NOME;
    public:
        Banco(string _nome = "??");
        virtual ~Banco();
        void Show();
        void ShowClientes();
        void ShowContas();
        void Add(Pessoa *P);
        void Add(Conta *C);
        bool RemoverConta(Conta *C);
        bool RemoverConta(string bi);
        Conta *PesquisarContaMaisGordinha();
        list<Conta *> *ContasSaldoInferior(float valor);
        void ExportarXML(string nf);
        void LimparBanco();
        Pessoa *PesquisarPessoa(string bi);
        Conta *PesquisarConta(Pessoa *P);
        void Depositar(string bi, float dep);


};

#endif // BANCO_H
