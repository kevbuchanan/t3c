#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>

#define EMPTY '-'

typedef struct _Board Board;

Board* new_board();
int get_size(Board* board);
char get_space(Board* board, int space);
void destroy_board(Board* board);
int make_move(Board* board, int space, char piece);
void unset_move(Board* board, int space);
bool is_valid_move(Board* board, int space);
bool is_full(Board* board);
bool is_empty(Board* board);
bool is_won(Board* board);
bool is_done(Board* board);
bool is_draw(Board* board);
char winner(Board* board);

#endif
