#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define SIZE 9
#define FACTOR 3
#define EMPTY '-'

char* new_board();
int make_move(char* board, int space, char piece);
bool is_full(char* board);
bool is_empty(char* board);
bool is_won(char* board);
bool is_done(char* board);
bool is_draw(char* board);
char winner(char* board);

#endif
