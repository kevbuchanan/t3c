#ifndef TTT_AI_H
#define TTT_AI_H

#include "board.h"

int hard_move(Board* board, char piece, char other_piece);
int medium_move(Board* board, char piece, char other_piece);
int easy_move(Board* board, char piece, char other_piece);

#endif
