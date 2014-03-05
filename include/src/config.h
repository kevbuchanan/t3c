#ifndef CONFIG_H
#define CONFIG_H

#include "player_factory.h"

typedef struct _Config {
  int size;
  int difficulty;
  char p1_piece;
  PlayerType p1_type;
  char p2_piece;
  PlayerType p2_type;
} Config;

Config initialize_config(int argc, char* argv[]);

#endif
