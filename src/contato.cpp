#include "contato.hpp"

// Definição da classe de contato
Contato::Contato(){
  this->nome = "";
  this->email = "";
  this->telefone = "";
}
//Define o nome do contato
void  Contato::setNome(std::string nome) {
  this->nome = nome;
}
// Define o email do contato
void Contato::setEmail(std::string email){
  this->email = email;
}
//Define o telefone do contato
void Contato::setTelefone(std::string telefone){
  this->telefone = telefone;
}
//Imprime as informações do contato
void Contato::imprime() const{
  std::cout << "Nome: " << nome << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Telefone: " << telefone << std::endl;
}

/**
 * Sobrecarga do operador de igualdade (==) para comparar dois contatos.
 * Verifica se as informações de dois contatos são iguais.
 * param outro O contato a ser comparado com o contato atual.
 * return true se os contatos forem iguais, caso contrário, retorna false.
 */
bool Contato::operator==(Contato outro){
  if (this->nome == outro.nome && this->email == outro.email && this->telefone == outro.telefone){
    return true;
  } else {
    return false;
  }
}

/**
 * Sobrecarga do operador de atribuição (=) para copiar informações de um contato para outro.
 * Atribui as informações de um contato para outro contato.
 * param outro O contato cujas informações serão copiadas.
 * return Uma referência para o contato atual após a atribuição.
 */
bool Contato::operator=(Contato outro){
  this->nome = outro.nome;
  this->email = outro.email;
  this->telefone = outro.telefone;
  return true;
}