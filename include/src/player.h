#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef int (*MoveHandler)(Board* board, char piece, char other_piece);

typedef struct Player {
  char piece;
  MoveHandler get_move;
} Player;

Player* create_player(char piece, MoveHandler move_fn);
void destroy_player(Player* player);

#endif
