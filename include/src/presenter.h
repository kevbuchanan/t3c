#ifndef PRESENTER_H
#define PRESENTER_H

#include "board.h"

void show_board(Board* board);
void show_message(char* message);
void show_messagef(char* message, char sub);
int ask_for_move(Board* board, char piece, char other_piece);

#endif
