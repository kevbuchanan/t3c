#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>

#include "board.h"
#include "game.h"
#include "player.h"
#include "player_factory.h"
#include "config.h"

void term(int signum) {
  puts("\n\nLater\n");
  exit(0);
}

int main(int argc, char* argv[]) {
  srand(time(NULL));
  signal(SIGINT, term);

  Config config = initialize_config(argc, argv);

  Board* board = new_board(config.size);

  Player* player1 = build_player(config.p1_piece, config.p1_type);
  Player* player2 = build_player(config.p2_piece, config.p2_type);

  start_game(board, player1, player2);

  destroy_player(player1);
  destroy_player(player2);
  destroy_board(board);

  return 0;
}
