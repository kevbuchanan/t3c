#include <stdlib.h>

#include "player.h"
#include "board.h"

Player* create_player(char piece, MoveHandler move_fn) {
  Player* player = malloc(sizeof(Player));
  player->piece = piece;
  player->get_move = move_fn;
  return player;
}

void destroy_player(Player* player) {
  free(player);
}
