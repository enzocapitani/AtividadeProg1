#include <stdio.h>
#include <math.h>

// Dimensões do console (ajuste conforme o tamanho do seu terminal)
#define WIDTH 120
#define HEIGHT 80
#define PI 3.14159265359

char screen[HEIGHT][WIDTH];
double turtle_x, turtle_y, turtle_angle;

// Preenche a tela com espaços em branco
void init_screen() {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

// Desenha um "pixel" na tela de caracteres
void draw_point(int x, int y) {
    // Como os caracteres do terminal costumam ser mais altos do que largos,
    // multiplicamos o y por 0.5 para corrigir a distorção da proporção.
    int adjusted_y = y / 2; 
    
    if (x >= 0 && x < WIDTH && adjusted_y >= 0 && adjusted_y < HEIGHT) {
        screen[adjusted_y][x] = '#';
    }
}

// Move a tartaruga para frente e desenha a linha
void move_forward(double length) {
    int steps = (int)(length * 2); // Resolução do traço
    if (steps < 1) steps = 1;
    
    double dx = cos(turtle_angle) * length / steps;
    double dy = sin(turtle_angle) * length / steps;

    for (int i = 0; i <= steps; i++) {
        draw_point((int)round(turtle_x), (int)round(turtle_y));
        turtle_x += dx;
        turtle_y += dy;
    }
}

// Gira a tartaruga
void turn(double degrees) {
    turtle_angle += degrees * PI / 180.0;
}

// Função recursiva para gerar uma das 3 curvas do floco
void koch_curve(int order, double length) {
    if (order == 0) {
        move_forward(length);
    } else {
        length /= 3.0;
        koch_curve(order - 1, length);
        turn(-60);
        koch_curve(order - 1, length);
        turn(120);
        koch_curve(order - 1, length);
        turn(-60);
        koch_curve(order - 1, length);
    }
}

int main() {
    init_screen();

    // Posição inicial (ajustada para centralizar o desenho)
    turtle_x = 15.0;
    turtle_y = 50.0;
    turtle_angle = 0.0; // Apontando para a direita

    int order = 3;        // Nível de recursão (tente 2, 3 ou 4)
    double length = 50.0; // Tamanho do lado do triângulo inicial

    // O Floco de Koch é composto por 3 curvas de Koch formando um triângulo fechado
    koch_curve(order, length);
    turn(120);
    koch_curve(order, length);
    turn(120);
    koch_curve(order, length);

    // Imprime a matriz no console
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }

    return 0;
}