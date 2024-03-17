#include "contato.cpp"
#include "hashTable.cpp"

int main(){
    HashTable tabela;
    Contato c1;
    c1.setNome("Joao");
    c1.setEmail("felipehidequel@gmail.com");
    c1.setTelefone("999999999");
    tabela.insere(c1.getNome(), c1);
    tabela.insere(c1.getNome(), c1);
}