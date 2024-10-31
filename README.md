# Jogo Pong - Projeto de Programação em C

## 1. Membros da Equipe
- João Lucas 
- Messias Daniel
- Isabela Karla

## 2. Disciplina
Programação Imperativa Funcional - 2024.2

## 3. Instituição de Ensino
CESAR School

## 4. Nome do Jogo
Pong

## 5. Objetivo
Desenvolver uma versão simplificada do jogo Pong em modo texto utilizando a linguagem C e a biblioteca `CLI.lib`. O projeto busca aplicar conceitos de programação, como controle de fluxo, modularização e estruturas de dados.

## 6. Descrição do Jogo
O Jogo Pong é um clássico jogo de arcade onde dois jogadores controlam raquetes em cada lado da tela. O objetivo é rebater uma bola que se move entre os jogadores, acumulando pontos ao fazer a bola passar pela raquete do oponente. Os jogadores controlam suas raquetes com as teclas direcionais ou com as teclas 'W', 'S' e '<', '>' (Caso seja jogado multiplayer). O jogo pode ser jogado em modo multiplayer local ou contra um bot.

## 7. Funcionalidades Principais
- **Interface Visual**: Utiliza a biblioteca `CLI.lib` para criar uma interface visual delimitada com caracteres ASCII.
- **Controle de Raquete**: Cada jogador tem controle de sua raquete, e no modo single-player, um oponente controlado pelo bot está disponível.
- **Sistema de Pontuação**: Os pontos são atribuídos sempre que a bola ultrapassa a raquete do adversário.
- **Movimento da Bola**: A bola se move em trajetórias diagonais e muda de direção ao colidir com as raquetes ou bordas da tela.
- **Fim de Jogo**: A partida termina quando um jogador atinge um limite de pontos estabelecido.
