#include <stdlib.h>

#include "player.h"

Player* create_player(char piece, int (*move_fn) (char* board, char piece, char other_piece)) {
  Player* player = (Player*)malloc(sizeof(Player));
  player->piece = piece;
  player->get_move = move_fn;
  return player;
}

void destroy_player(Player* player) {
  free(player);
}
