#include "hashTable.hpp"
/**
 * Gera um número inteiro aleatório no intervalo [0, MAX_SIZE).
 * retorna Um número inteiro aleatório no intervalo especificado.
 */
int HashTable::randInt(){
  return (rand() % MAX_SIZE);
}

/**
 * Calcula o hash para uma chave de string utilizando uma abordagem de sondagem linear.
 * param chave A chave para calcular o hash.
 * return O índice calculado na tabela de dispersão.
 * Se a tabela estiver cheia, retorna o índice padrão definido pela VALOR_PADRAO.
 */
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
/**
 * Realiza a sondagem linear para encontrar o próximo índice disponível na tabela de dispersão.
 * param cont O valor do hash inicial.
 * param chave A chave a ser pesquisada.
 * return O próximo índice disponível na tabela de dispersão.
 */
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

/**
 * Verifica se a tabela de dispersão está cheia.
 * return true se a tabela estiver cheia, caso contrário retorna false.
 */
bool HashTable::cheia(){
  if(this->n_entradas == MAX_SIZE){
    return true;
  }
  return false;
}

/**
 * Construtor da classe HashTable.
 * Inicializa a tabela de dispersão e define o valor padrão para indicar entradas vazias.
 */
HashTable::HashTable(){
  this->VALOR_PADRAO.indice = -1;

  srand(time(nullptr));

  for(auto& e : this->tabela){
    e.indice = this->VALOR_PADRAO.indice;
  }
}

/**
 * Realiza uma busca na tabela de dispersão usando uma chave.
 * param chave A chave a ser pesquisada.
 * return O contato associado à chave, ou um contato vazio se a chave não for encontrada na tabela.
 */
Contato HashTable::busca(std::string chave){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return Contato();
  }

  return this->tabela[indice].valor;
}

/**
 * Insere um par chave-valor na tabela de dispersão.
 * param chave A chave a ser inserida.
 * param valor O valor associado à chave a ser inserido.
 * return true se a inserção for bem-sucedida, false se a tabela estiver cheia ou a chave já existir.
 */
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

/**
 * Atualiza o valor associado a uma chave existente na tabela de dispersão.
 * param chave A chave cujo valor será atualizado.
 * param valor O novo valor associado à chave.
 * return true se a atualização for bem-sucedida, false se a chave não existir na tabela.
 */
bool HashTable::atualiza(std::string chave, Contato valor){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return false;
  }

  this->tabela[indice].valor = valor;
  return true;
}

/**
 * Remove um par chave-valor da tabela de dispersão.
 * param chave A chave a ser removida.
 * return true se a remoção for bem-sucedida, false se a chave não existir na tabela.
 */
bool HashTable::remove(std::string chave){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return false;
  }

  this->tabela[indice] = this->VALOR_PADRAO;
  this->n_entradas--;
  return true;
}