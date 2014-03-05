#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

#include "player.h"

typedef enum {
  computer,
  human
} PlayerType;

Player* build_player(char piece, PlayerType type);

#endif

