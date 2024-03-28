#pragma once

#include <iostream>
#include <string>
//funções utilizadas
class Contato{
private:
  std::string nome;
  std::string email;
  std::string telefone;
public:
  Contato();
  void setNome(std::string nome);
  void setEmail(std::string email);
  void setTelefone(std::string telefone);
  std::string getNome() {return nome;}
  std::string getEmail() {return email;}
  std::string getTelefone() {return telefone;}
  void imprime() const;
  bool operator==(Contato outro);
  bool operator=(Contato outro);
};
// Path: contato.cpp