#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "contato.hpp"

class HashTable{
private:
  struct Entrada {
    int indice;
    std::string chave;
    Contato valor;
  };

  unsigned int n_entradas = 0;
  static const int MAX_SIZE = 35;

  struct Entrada VALOR_PADRAO;
  struct Entrada tabela[MAX_SIZE];

  int randInt();
  int hash(std::string chave);
  int sondagemLinear(const int cont, const std::string chave);
  bool cheia();
public:
  HashTable();
  Contato busca(std::string chave);
  bool insere(std::string chave, Contato valor);
  bool atualiza(std::string chave, Contato valor);
  bool remove(std::string chave);
};
// Path: hashTable.cpp