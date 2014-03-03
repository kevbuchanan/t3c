#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

typedef struct Player {
  char piece;
  int (*get_move) (Board* board, char piece, char other_piece);
} Player;

Player* create_player(char piece, int (*move_fn) (Board* board, char piece, char other_piece));
void destroy_player(Player* player);

#endif
