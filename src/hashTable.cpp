#include "hashTable.hpp"

int HashTable::randInt(){
  return (rand() % MAX_SIZE);
}

int HashTable::hash(std::string chave){
  if(this->cheia()){
    return this->VALOR_PADRAO.indice;
  }

  int cont = 0;

  int i = 1;
  for (char c : chave){
    cont += i++ * int(c);  
  }

  return this->sondagemLinear(cont, chave);
}

int HashTable::sondagemLinear(const int cont, const std::string chave){
  int indice = static_cast<int>(cont % MAX_SIZE);

  while (this->tabela[indice].indice != this->VALOR_PADRAO.indice){
    if (this->tabela[indice].chave == chave){
      return indice;
    }

    indice = ++indice % MAX_SIZE;
  }
  return indice;
}

bool HashTable::cheia(){
  if(this->n_entradas == MAX_SIZE){
    return true;
  }
  return false;
}

HashTable::HashTable(){
  this->VALOR_PADRAO.indice = -1;

  srand(time(nullptr));

  for(auto& e : this->tabela){
    e.indice = this->VALOR_PADRAO.indice;
  }
}

Contato HashTable::busca(std::string chave){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return Contato();
  }

  return this->tabela[indice].valor;
}

bool HashTable::insere(std::string chave, Contato valor){
  if(this->cheia()){
    std::cout << "Tabela cheia!" << std::endl;
    return false;
  }

  int indice = this->hash(chave);

  if (this->tabela[indice].chave == chave){
    std::cout << "Chave já existe!" << std::endl;
    return false;
  }

  struct Entrada *entrada = new Entrada();
  if(entrada == nullptr){
    std::cout << "Erro ao alocar memória!" << std::endl;
    return false;
  }
  
  entrada->indice = indice;
  entrada->chave = chave;
  entrada->valor = valor;
  this->tabela[indice] = *entrada;
  this->n_entradas++;

  return true;
}

bool HashTable::atualiza(std::string chave, Contato valor){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return false;
  }

  this->tabela[indice].valor = valor;
  return true;
}

bool HashTable::remove(std::string chave){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return false;
  }

  this->tabela[indice] = this->VALOR_PADRAO;
  this->n_entradas--;
  return true;
}