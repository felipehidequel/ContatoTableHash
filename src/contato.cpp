#include "contato.hpp"

Contato::Contato(){
  this->nome = "";
  this->email = "";
  this->telefone = "";
}
void  Contato::setNome(std::string nome) {
  this->nome = nome;
}
void Contato::setEmail(std::string email){
  this->email = email;
}
void Contato::setTelefone(std::string telefone){
  this->telefone = telefone;
}

void Contato::imprime() const{
  std::cout << "Nome: " << nome << std::endl;
  std::cout << "Email: " << email << std::endl;
  std::cout << "Telefone: " << telefone << std::endl;
}
bool Contato::operator==(Contato outro){
  if (this->nome == outro.nome && this->email == outro.email && this->telefone == outro.telefone){
    return true;
  } else {
    return false;
  }
}
bool Contato::operator=(Contato outro){
  this->nome = outro.nome;
  this->email = outro.email;
  this->telefone = outro.telefone;
  return true;
}