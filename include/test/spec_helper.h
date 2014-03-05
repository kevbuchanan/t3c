#ifndef SPEC_HELPER_H
#define SPEC_HELPER_H

#include "board.h"

void success(void);
void show_results(void);
extern int current_move;
int fake_move(Board* board, char piece, char other_piece);
int incrementing_move(Board* board, char piece, char other_piece);
Board* draw_board(void);

#endif
