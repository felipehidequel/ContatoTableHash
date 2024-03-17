#include "./src/contato.cpp"
#include "./src/hashTable.cpp"
#include <iostream>
#include <fstream>
#include <string>


void lerContatos(HashTable& tabela, const std::string& nomeArquivo) {
  std::ifstream arquivo(nomeArquivo);
  std::cout << "Lendo contatos do arquivo " << nomeArquivo << std::endl;
  if (arquivo.is_open()) {
      std::string nome, email, telefone, discard;
      Contato c1;
      while (tabela.cheia() == false && std::getline(arquivo, discard, ':') && std::getline(arquivo, nome) && std::getline(arquivo, discard, ':') && std::getline(arquivo, telefone) && std::getline(arquivo, discard, ':') && std::getline(arquivo, email)){
          c1.setNome(nome.substr(1));
          c1.setEmail(email.substr(1));
          c1.setTelefone(telefone.substr(1));
          c1.imprime();
          tabela.insere(c1.getNome(), c1);
      }
      arquivo.close();
  } else {
      std::cout << "Erro ao abrir o arquivo." << std::endl;
  }
  std::cout << "Fim da leitura do arquivo." << std::endl;
}

int main() {
  HashTable tabela;
  // Abrir arquivo txt com os contatos
  lerContatos(tabela, "contatos.txt");

  return 0;
}


