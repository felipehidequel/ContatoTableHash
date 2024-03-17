#include "./src/contato.cpp"
#include "./src/hashTable.cpp"

int main(){
HashTable tabela;
Contato c1;
Contato c2;
c1.setNome("Joao");
c1.setEmail("felipehidequel@gmail.com");
c1.setTelefone("999999999");
c2.setNome("Joao batista");
c2.setEmail("hidequel@gmail.com");
c2.setTelefone("3423546346");
tabela.insere(c1.getNome(), c1);
tabela.remove(c1.getNome());
tabela.insere(c1.getNome(), c1);
tabela.insere(c2.getNome(), c2);
}