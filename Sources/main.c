#include <stdio.h>
#include <stdlib.h>
#include "snakegame.h"

int main() {
    // Create Ground Matrix
    char** ground = (char**) malloc(20 * sizeof(char*));
    if (ground == NULL) {
        printf("Allocation Failed..!\n");
        exit(1);
    }
    else {
        for (int i = 0; i < 20; i++) {
            *(ground + i) = (char*) malloc(60 * sizeof(char));
            for (int j = 0; j < 60; j++) *(*(ground + i) + j) = ' ';
        }
    }
    int score = 0, lives = 0;
    point snake, food;
    snake.x = 10;
    snake.y = 30;
    food.x = rand() % 20;
    food.y = rand() % 60;
    *(*(ground + snake.x) + snake.y) = '#';
    *(*(ground + food.x) + food.y) = '*';
    displayGround(ground, score, lives);
    for (;;) {
        moveSnake(ground, &snake, &food, &score, &food);
        system("cls");
        displayGround(ground, score, lives);
    }
    return 0;
}
