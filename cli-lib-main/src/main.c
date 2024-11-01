/**
 * main.h
 * Created on Aug, 23th 2023
 * Author: Tiago Barros
 * Based on "From C to C++ course - 2002"
*/

#include <string.h>

#include "screen.h"
#include "keyboard.h"
#include "timer.h"

int pontoJogador1 = 0, pontoJogador2 = 0;
int posicaoXRaquete = 5, posicaoYRaquete = MAXY/2;
int x = 34, y = 12;
int incX = 1, incY = 1;

void mostrarBolinha(int nextX, int nextY)
{
    screenSetColor(WHITE, WHITE);
    screenGotoxy(x, y);
    printf(" ");
    x = nextX;
    y = nextY;
    screenGotoxy(x, y);
    printf("O");
}

void mostrarPlacar()
{
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(10, 2);
    printf("Jogador 1 : %d ", pontoJogador1);

}


void mostrarPlacar2()
{
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(55, 2);
    printf("Jogador 2 : %d", pontoJogador2);
 
}

void raquete1(int nextXRaquete, int nextYRaquete)
{
    screenSetColor(BLUE, BLUE);     
    screenGotoxy(posicaoXRaquete, posicaoYRaquete);
    printf(" ");
    posicaoXRaquete = nextXRaquete;
    posicaoYRaquete = nextYRaquete;
    screenGotoxy(posicaoXRaquete, posicaoYRaquete);
    printf("I");
}

void calcularPlacar(){

    if(x == MAXX - strlen("  ")){

        pontoJogador1 += 1;
        screenGotoxy(x, y);
        printf(" ");
        x = MAXX/2; 
        y = MAXY/2;
        
    } else if (x == MINX + strlen("  "))
    {
        pontoJogador2 += 1;
        screenGotoxy(x,y);
        printf(" ");
        x = MAXX/2; 
        y = MAXY/2;
       
    }
    
}

void printKey(int ch)
{
    screenSetColor(YELLOW, DARKGRAY);
    screenGotoxy(35, 22);
    printf("Key code :");

    screenGotoxy(34, 23);
    printf("            ");
    
    if (ch == 27) screenGotoxy(36, 23);
    else screenGotoxy(39, 23);

    printf("%d ", ch);
    while (keyhit())
    {
        printf("%d ", readch());
    }
}




int main() 
{
    static int ch = 0;

    screenInit(1);
    keyboardInit();
    timerInit(50);
    printkey(ch);
    mostrarBolinha(x, y);
    screenUpdate();

    while (ch != 10) //enter
    {
        // Handle user input
        if (keyhit()) 
        {
            ch = readch();
            mostrarPlacar(ch);
            mostrarPlacar2(ch);
            calcularPlacar();
            printkey(ch);
            screenUpdate();
        }

        // Update game state (move elements, verify collision, etc)
        if (timerTimeOver() == 1)
        {
            int newX = x + incX;
            if (newX >= (MAXX -strlen("O") -1) || newX <= MINX+1) incX = -incX;
            int newY = y + incY;
            if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;

            int newXRaquete = x + incX;
            if (newX >= (MAXX -strlen("O") -1) || newX <= MINX+1) incX = -incX;
            int newYRaquete = y + incY;
            if (newY >= MAXY-1 || newY <= MINY+1) incY = -incY;

            mostrarPlacar(ch);
            mostrarPlacar2(ch);
            mostrarBolinha(newX, newY);
            calcularPlacar();
            printkey(ch);
            screenUpdate();
        }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

    return 0;
}
