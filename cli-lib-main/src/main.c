

// Tamanho da tela
#define WIDTH 40
#define HEIGHT 20

<<<<<<< Updated upstream
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
    
=======
// Posições e Velocidade da Bola
int ballX, ballY;
int ballVelX = 1, ballVelY = 1;

// Posições das Raquetes e Pontuações
int paddle1Y, paddle2Y;
int score1 = 0, score2 = 0;

// Configurações Iniciais
void setup() {
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    paddle1Y = HEIGHT / 2 - 2;
    paddle2Y = HEIGHT / 2 - 2;
>>>>>>> Stashed changes
}

// Função para desenhar a tela
void draw() {
    system("cls"); // Limpa a tela
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#"); // Borda esquerda
            if (i == ballY && j == ballX) printf("O"); // Bola
            else if (j == WIDTH - 1) printf("#"); // Borda direita
            else if (j == 1 && (i >= paddle1Y && i < paddle1Y + 4)) printf("|"); // Raquete 1
            else if (j == WIDTH - 2 && (i >= paddle2Y && i < paddle2Y + 4)) printf("|"); // Raquete 2
            else printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    printf("Jogador 1: %d   Jogador 2: %d\n", score1, score2);
}

// Função para capturar entrada do usuário
void input() {
    if (_kbhit()) { // Se uma tecla foi pressionada
        char key = _getch();
        // Controles do Jogador 1 (W e S)
        if (key == 'w' && paddle1Y > 0) paddle1Y--;
        if (key == 's' && paddle1Y < HEIGHT - 4) paddle1Y++;
        // Controles do Jogador 2 (I e K)
        if (key == 'i' && paddle2Y > 0) paddle2Y--;
        if (key == 'k' && paddle2Y < HEIGHT - 4) paddle2Y++;
    }
}

<<<<<<< Updated upstream



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
=======
// Função para atualizar a lógica do jogo
void update() {
    ballX += ballVelX;
    ballY += ballVelY;

    // Colisão com as bordas superior e inferior
    if (ballY <= 0 || ballY >= HEIGHT - 1) ballVelY = -ballVelY;

    // Colisão com as raquetes
    if (ballX == 2 && ballY >= paddle1Y && ballY < paddle1Y + 4) ballVelX = -ballVelX;
    if (ballX == WIDTH - 3 && ballY >= paddle2Y && ballY < paddle2Y + 4) ballVelX = -ballVelX;

    // Pontuação
    if (ballX <= 0) {
        score2++;
        setup();
    } else if (ballX >= WIDTH - 1) {
        score1++;
        setup();
>>>>>>> Stashed changes
    }
}

// Função principal
int main() {
    setup();
    while (1) {
        draw();
        input();
        update();
        Sleep(50); // Controle de velocidade do jogo
    }
    return 0;
}
