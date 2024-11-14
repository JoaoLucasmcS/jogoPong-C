#include <stdio.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Variáveis globais do jogo
int pontoJogador1 = 0, pontoJogador2 = 0;
int posicaoXRaquete1 = 5, posicaoYRaquete1 = MAXY / 2;
int posicaoXRaquete2 = MAXX - 5, posicaoYRaquete2 = MAXY / 2;
int x = MAXX / 2, y = MAXY / 2;
int incX = 1, incY = 1;

// Funções auxiliares
void mostrarBolinha(int nextX, int nextY) {
    screenSetColor(WHITE, WHITE);
    screenGotoxy(x, y);
    printf(" ");
    x = nextX;
    y = nextY;
    screenGotoxy(x, y);
    printf("O");
}

void mostrarPlacar() {
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(10, 2);
    printf("Jogador 1: %d", pontoJogador1);
    screenGotoxy(55, 2);
    printf("Jogador 2: %d", pontoJogador2);
}

void raquete(int xRaquete, int yRaquete, int newXRaquete, int newYRaquete) {
    screenSetColor(BLUE, BLUE);
    for (int i = -1; i <= 1; i++) {
        screenGotoxy(xRaquete, yRaquete + i);
        printf(" ");
    }
    for (int i = -1; i <= 1; i++) {
        screenGotoxy(newXRaquete, newYRaquete + i);
        printf("|");
    }
}

void calcularPlacar() {
    if (x >= MAXX - 1) {
        pontoJogador1++;
        x = MAXX / 2; y = MAXY / 2;
    } else if (x <= 1) {
        pontoJogador2++;
        x = MAXX / 2; y = MAXY / 2;
    }
}

void moverRaquetes(int ch) {
    if (ch == 'w' && posicaoYRaquete1 > MINY + 1) posicaoYRaquete1--;
    if (ch == 's' && posicaoYRaquete1 < MAXY - 2) posicaoYRaquete1++;
    if (ch == 'i' && posicaoYRaquete2 > MINY + 1) posicaoYRaquete2--;
    if (ch == 'k' && posicaoYRaquete2 < MAXY - 2) posicaoYRaquete2++;
}

int colisaoRaquete() {
    if (x == posicaoXRaquete1 + 1 && y >= posicaoYRaquete1 - 1 && y <= posicaoYRaquete1 + 1) return -1;
    if (x == posicaoXRaquete2 - 1 && y >= posicaoYRaquete2 - 1 && y <= posicaoYRaquete2 + 1) return -1;
    return 1;
}

int main() {
    int ch = 0;
    screenInit(1);
    keyboardInit();
    timerInit(50);

    while (ch != 10) { // Pressione Enter para sair
        if (keyhit()) {
            ch = readch();
            moverRaquetes(ch);
        }

        if (timerTimeOver() == 1) {
            int newX = x + incX;
            int newY = y + incY;

            // Colisão com bordas e raquetes
            if (newY >= MAXY - 1 || newY <= MINY + 1) incY = -incY;
            incX *= colisaoRaquete();

            // Movimentos da bola e raquetes
            mostrarBolinha(newX, newY);
            raquete(posicaoXRaquete1, posicaoYRaquete1, posicaoXRaquete1, posicaoYRaquete1);
            raquete(posicaoXRaquete2, posicaoYRaquete2, posicaoXRaquete2, posicaoYRaquete2);
            calcularPlacar();
            mostrarPlacar();
            screenUpdate();
        }
    }

    // Encerrar o jogo e limpar a tela
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}
