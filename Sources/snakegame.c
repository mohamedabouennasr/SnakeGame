#include "snakegame.h"
#include <stdio.h>
#include <stdlib.h>

void displayGround(char** ground, int score, int lives) {
    printf("+------------------------------------------------------------+\n");
    for (int i = 0; i < 20; i++) {
        printf("|");
        for (int j = 0; j < 60; j++) printf("%c", *(*(ground + i) + j));
        printf("|\n");
    }
    printf("+------------------------------------------------------------+\n");
    printf("Score: %.2d                                            Lives: %.2d\n", score, lives);
}

void moveSnake(char** ground, point* snake, point* food, int* score, int* lives) {
    char choice;
    do {
        scanf(" %c", &choice);
    } while (choice != 'z' && choice != 'q' && choice != 's' && choice != 'd');
    *(*(ground + snake->x) + snake->y) = ' ';
    switch (choice) {
        case 'z':
            snake->x--;
            break;
        case 'q':
            snake->y--;
            break;
        case 's':
            snake->x++;
            break;
        case 'd':
            snake->y++;
            break;
    }
    *(*(ground + snake->x) + snake->y) = '#';
    if (food->x == snake->x && food->y == snake->y) {
        (*score)++;
        food->x = rand() % 20;
        food->y = rand() % 60;
    }
    *(*(ground + food->x) + food->y) = '*';
    if (snake->x == -1 || snake->x == 20 || snake->y < 0 || snake->y == 60) {
        (*lives)--;
        *(*(ground + snake->x) + snake->y) = ' ';
        snake->x = 10;
        snake->y = 30;
        *(*(ground + snake->x) + snake->y) = '#';
    }
}
