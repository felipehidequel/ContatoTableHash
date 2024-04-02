# lista-contato-hash

### Motivação 
o uso de tabelas hash em um programa de lista de contatos em C pode resultar em um desempenho eficiente, acesso rápido aos dados e uma experiência melhor para os usuários,especialmente quando lidamos com grandes conjuntos de dados

##

### Objetivo
O uso da tabela hash no programa de lista de contatos se refere principalmente as principais vantagens como :

* Pesquisa Eficiente: Com uma tabela hash você pode realizar operações de pesquisa o que é muito eficiente, especialmente quando lidamos com projetos que são necessário lidar com um grande número de dados como é o caso da lista de contatos

* Inserção e Remoção Eficientes: Inserir e remover contatos podem ser operações rápidas em uma tabela hash bem implementada. Isso é fundamental em aplicativos de lista de contatos por ser uma função muito utilizada

* Gerenciamento de Colisões: A implementação correta da tabela hash inclui maneiras de lidar com colisões no sentido de quando 2 contatos possuem o mesmo valor hash dentro da tabela,controlar colisões é essencial para garantir a integridade e eficiência da tabela

* Acesso Rápido: Uma vez que você tenha o hash de um contato, o acesso se torna direto à sua posição na tabela

* Economia de Memória: Uma tabela hash bem otimizada pode economizar memória em comparação com outras estruturas de dados , principalmente se deseja 

* Flexibilidade: Tabelas hash podem ser ajustadas para atender às necessidades especificas dentro do programa no sentido que pode deixar da sua preferência o tamanho da tabela, a função de hash a ser usada e a estratégia de tratamento de colisões

##

### Metodologia 
A metodologia utilizada no projeto de lista de contatos foi a técnica de hashing por multiplicação. Além disso, foi aplicada a técnica de sondagem linear para lidar com colisões. A sondagem linear encontra a próxima posição disponível na tabela quando duas chaves hash, no caso os nomes dos contatos, possuem o mesmo valor de hash e tentam ser inseridas na mesma posição. Essa combinação de técnicas permite um acesso eficiente aos dados e um gerenciamento adequado de colisões na tabela hash.

#### Método da Multiplicação

```c++
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
```

A função começa verificando se a tabela hash está cheia. Se estiver cheia, ela retorna o índice padrão definido pela constante VALOR_PADRAO. Caso contrário, ela continua o cálculo do valor hash. A variável cont é inicializada com o valor zero e será usada para acumular o resultado do cálculo do valor hash. A variável i é inicializada com o valor 1 e será usada para multiplicar cada caractere da chave. Em seguida, a função itera sobre cada caractere da chave usando um loop for-each. Para cada caractere, o valor inteiro correspondente é multiplicado pelo valor de i e adicionado ao valor acumulado em cont. O valor de i é incrementado a cada iteração.  Após o loop, o valor acumulado em cont é retornado como o valor hash calculado. No entanto, antes de retornar, a função chama outro método chamado sondagemLinear passando o valor hash e a chave como argumentos. Esse método é responsável por lidar com colisões na tabela hash e determinar a posição final da chave na tabela.

#### Sondagem Linear

```c++
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
```

A função recebe dois parâmetros: cont, que representa um contador utilizado para calcular o índice inicial, e chave, que é a chave que estamos procurando na tabela de hash. A primeira linha do método calcula o índice inicial usando o operador % (módulo) para garantir que o índice esteja dentro dos limites da tabela de hash. O valor de cont é convertido para um int usando static_cast e então é calculado o resto da divisão por MAX_SIZE, que é o tamanho máximo da tabela. Em seguida, temos um loop while que verifica se o índice atual na tabela de hash não está vazio. Se o índice estiver vazio, significa que a chave não está presente na tabela e retornamos o índice atual. Dentro do loop, verificamos se a chave na posição atual da tabela é igual à chave que estamos procurando. Se for, encontramos a chave e retornamos o índice atual. Caso contrário, incrementamos o índice usando o operador ++ e, em seguida, calculamos o resto da divisão por MAX_SIZE novamente. Isso garante que o índice seja atualizado corretamente e que não ultrapasse os limites da tabela. Se o loop while terminar sem encontrar a chave, retornamos o índice atual como uma indicação de que a chave não está presente na tabela.

#### Remoção

```c++
bool HashTable::remove(std::string chave){
  int indice = this->hash(chave);

  if (indice == this->VALOR_PADRAO.indice){
    return false;
  }

  this->tabela[indice] = this->VALOR_PADRAO;
  this->n_entradas--;
  return true;
}
```

Primeiro, a função calcula o índice da tabela de hash usando o método hash da classe, passando a chave como argumento. Em seguida, verifica se o índice calculado é igual ao valor padrão de índice (VALOR_PADRAO.indice). Se for igual, isso significa que o elemento não está presente na tabela de hash e a função retorna false. Caso contrário, a função prossegue e atribui o valor padrão (VALOR_PADRAO) ao elemento da tabela de hash no índice calculado. Além disso, decrementa o número de entradas (n_entradas) na tabela de hash. Por fim, a função retorna true para indicar que a remoção foi bem-sucedida.






