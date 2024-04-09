#ifndef SNAKEGAME_H_INCLUDED
#define SNAKEGAME_H_INCLUDED

typedef struct {
    int x;
    int y;
} point;

void displayGround(char** ground, int score, int lives);
void moveSnake(char** ground, point* snake, point* food, int* score, int* lives);

#endif // SNAKEGAME_H_INCLUDED
