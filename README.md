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
A metodologia usada no projeto de lista de contatos foi multiplicação para inserção é uma técnica de hashing que utiliza a multiplicação de um valor-chave pela fração parte de uma constante, seguido pelo uso da parte inteira desse resultado para ajustar o índice na tabela hash , juntamente com o uso da sondagem  linear que serve para quando ocorre uma colisão, isto é, quando duas chaves hash que no caso a chave utilizada nesse projeto é uma string no caso os nomes dos usuários possuirem o mesmo valor de hash e tentarem serem inseridas na mesma posição da tabela hash, nessa situação a sondagem linear é uma técnica que irá encontrar a próxima posição disponível na tabela
