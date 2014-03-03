#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
  char piece;
  int (*get_move) (char* board, char piece, char other_piece);
} Player;

Player* create_player(char piece, int (*move_fn) (char* board, char piece, char other_piece));
void destroy_player(Player* player);

#endif
