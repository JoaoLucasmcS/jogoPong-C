#include <stdio.h>
#include "../include/screen.h"
#include "../include/keyboard.h"
#include "../include/timer.h"

#define TAMANHO_RAQUETE 1

int pontoJogador1 = 0, pontoJogador2 = 0;
int posicaoXRaquete1 = 5, posicaoYRaquete1 = MAXY / 2;
int posicaoXRaquete2 = MAXX - 5, posicaoYRaquete2 = MAXY / 2;
int x = MAXX / 2, y = MAXY / 2;
int incX = 1, incY = 1;

void inicializarJogo() {
    screenInit(1);
    keyboardInit();
    timerInit(90);
}

void resetarBolinha() {
    x = MAXX / 2;
    y = MAXY / 2;
    incX = -incX;
}

void mostrarBolinha(int nextX, int nextY) {
    screenSetColor(DARKGRAY, DARKGRAY);
    screenGotoxy(x, y);
    printf(" ");

    x = nextX;
    y = nextY;

    screenSetColor(WHITE, DARKGRAY);
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

void desenharRaquete(int xRaquete, int yRaquete, int tamanhoRaquete) {
    screenSetColor(DARKGRAY, DARKGRAY);
    for (int i = -tamanhoRaquete; i <= tamanhoRaquete; i++) {
        screenGotoxy(xRaquete, yRaquete + i);
        printf(" ");
    }

    screenSetColor(BLUE, DARKGRAY);
    for (int i = -tamanhoRaquete; i <= tamanhoRaquete; i++) {
        screenGotoxy(xRaquete, yRaquete + i);
        printf("|");
    }
}

void calcularPlacar() {
    if (x >= MAXX - 1) {
        pontoJogador1++;
        resetarBolinha();
        screenDrawBorders();
    } else if (x <= 1) {
        pontoJogador2++;
        resetarBolinha();
        screenDrawBorders();
    }
}   

void moverRaquetes(int ch) {
    if (ch == 'w' && posicaoYRaquete1 > MINY + 1) posicaoYRaquete1--;
    if (ch == 's' && posicaoYRaquete1 < MAXY - 2) posicaoYRaquete1++;

    if (ch == 'i' && posicaoYRaquete2 > MINY + 1) posicaoYRaquete2--;
    if (ch == 'k' && posicaoYRaquete2 < MAXY - 2) posicaoYRaquete2++;
}

int verificarColisaoRaquete() {
    if (x == posicaoXRaquete1 + 1 && y >= posicaoYRaquete1 - TAMANHO_RAQUETE && y <= posicaoYRaquete1 + TAMANHO_RAQUETE) {
        return -incX;
    }

    if (x == posicaoXRaquete2 - 1 && y >= posicaoYRaquete2 - TAMANHO_RAQUETE && y <= posicaoYRaquete2 + TAMANHO_RAQUETE) {
        return -incX;
    }

    return incX;
}

void limparRaquetes() {
    screenGotoxy(posicaoXRaquete1, posicaoYRaquete1);
    printf(" ");
    screenGotoxy(posicaoXRaquete1, posicaoYRaquete1 + 1);
    printf(" ");
    screenGotoxy(posicaoXRaquete1, posicaoYRaquete1 - 1);
    printf(" ");

    screenGotoxy(posicaoXRaquete2, posicaoYRaquete2);
    printf(" ");
    screenGotoxy(posicaoXRaquete2, posicaoYRaquete2 + 1);
    printf(" ");
    screenGotoxy(posicaoXRaquete2, posicaoYRaquete2 - 1);
    printf(" ");
    
}

int main() {
    int ch = 0;
    inicializarJogo();

    while (ch != 10) {
        if (keyhit()) {
            ch = readch();
            moverRaquetes(ch);
        }

        if (timerTimeOver() == 1) {
            int newX = x + incX;
            int newY = y + incY;

            if (newY >= MAXY - 1 || newY <= MINY + 1) {
                incY = -incY;
            }

            incX = verificarColisaoRaquete();

            mostrarBolinha(newX, newY);
            desenharRaquete(posicaoXRaquete1, posicaoYRaquete1, TAMANHO_RAQUETE);
            desenharRaquete(posicaoXRaquete2, posicaoYRaquete2, TAMANHO_RAQUETE);
            calcularPlacar();
            mostrarPlacar();
            screenUpdate();
            limparRaquetes();
        }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();
    return 0;
}
