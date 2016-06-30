Caio Ramos - NUSP 9292991 - IME USP 2016

Para executar o jogo, deve-se ter previamente instalado a biblioteca padrão Allegro 5.
Um bom tutorial para isto é: 
http://www.rafaeltoledo.net/compilando-e-instalando-a-biblioteca-allegro-5-no-ubuntu/
Executar o Makefile com o comando 'make' para montar todos os arquivos.
Para executar o teste do jogo, rodar o comando 'make run'. Sera usado o
argumento 0.017 e o arquivo 1.in.

As teclas WASD e as setas comandam as naves. As teclas G e L atiram projeteis para cada
uma das naves, respectivamente. O jogo termina quando as naves se colidem, quando 
uma delas se colide com o planeta ou quando uma é atingida por um dos projeteis. Cada nave 
tem direito a 1 projetil por vez. Só podera lançar o próximo quando o atual "morrer" (Por tempo ou 
colidindo com o planeta). Os projeteis seram lançados com a mesma velocidade que a nave está no momento
do lançamento. Os projeteis não têm dono, isto é, podem atingir qualquer umas das duas naves.
