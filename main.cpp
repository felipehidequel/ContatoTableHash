#include "./src/contato.cpp"
#include "./src/hashTable.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void lerContatos(HashTable &tabela, const std::string &nomeArquivo)
{
  std::ifstream arquivo(nomeArquivo);
  std::cout << "Lendo contatos do arquivo " << nomeArquivo << std::endl;
  if (arquivo.is_open())
  {
    std::string nome, email, telefone, discard;
    Contato c1;
    while (tabela.cheia() == false && std::getline(arquivo, discard, ':') && std::getline(arquivo, nome) && std::getline(arquivo, discard, ':') && std::getline(arquivo, telefone) && std::getline(arquivo, discard, ':') && std::getline(arquivo, email))
    {
      c1.setNome(nome.substr(1));
      c1.setEmail(email.substr(1));
      c1.setTelefone(telefone.substr(1));
      tabela.insere(c1.getNome(), c1);
    }
    arquivo.close();
  }
  else
  {
    std::cout << "Erro ao abrir o arquivo." << std::endl;
  }
  std::cout << "Fim da leitura do arquivo." << std::endl;
}

void criarNovoContato(HashTable &tabela, const std::string &nome, const std::string &email, const std::string &telefone)
{
  Contato novoContato;
  novoContato.setNome(nome);
  novoContato.setEmail(email);
  novoContato.setTelefone(telefone);

  tabela.insere(novoContato.getNome(), novoContato);
}

void buscarContato(HashTable &tabela, const std::string &nome)
{
  Contato contatoBuscado = tabela.busca(nome);
  if (contatoBuscado.getNome() != "")
  {
    std::cout << "Contato encontrado:" << std::endl;
    contatoBuscado.imprime();
  }
  else
  {
    std::cout << "Contato não encontrado." << std::endl;
  }
}

void deletarContato(HashTable &tabela, const std::string &nome)
{
  if (tabela.remove(nome))
  {
    std::cout << "Contato removido com sucesso!" << std::endl;
  }
  else
  {
    std::cout << "Contato não encontrado." << std::endl;
  }
}

int main()
{
  std::string nome, email, telefone;
  HashTable tabela;
  // Abrir arquivo txt com os contatos
  lerContatos(tabela, "aqueles_contatos.txt");
  int opcao = 0;
  while (opcao != 5)
  {
    std::cout << "\nEscolha uma opção:" << std::endl;
    std::cout << "1. Criar contato" << std::endl;
    std::cout << "2. Buscar contato" << std::endl;
    std::cout << "3. Deletar contato" << std::endl;
    std::cout << "4. Listar Cotatos" << std::endl;
    std::cout << "5. Sair" << std::endl;
    std::cout << "Opção: ";
    std::cin >> opcao;

    switch (opcao)
    {

    case 1:
    {
      std::cout << "Digite o nome do novo contato: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, nome);

      std::cout << "Digite o email do novo contato: ";
      std::getline(std::cin, email);

      std::cout << "Digite o telefone do novo contato: ";
      std::getline(std::cin, telefone);
    }
      criarNovoContato(tabela, nome, email, telefone);

      break;
    case 2:
    {
      std::cout << "Digite o contato que deseja buscar: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, nome);
    }
      buscarContato(tabela, nome);
      break;
    case 3:
    {
      std::cout << "Digite o contato que deseja Deletar: ";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::getline(std::cin, nome);
    }
      deletarContato(tabela, nome);
      break;
    case 4:
      tabela.listarContatos();
      break;
    case 5:
      tabela.gravarContatos();
      std::cout << "Saindo..." << std::endl;
      break;
    default:
      std::cout << "Opção inválida. Tente novamente." << std::endl;
      break;
    }
  }

  return 0;
}
