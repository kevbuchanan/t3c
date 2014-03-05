#include "board.h"
#include "game.h"
#include "player.h"
#include "player_factory.h"
#include "config.h"

int main(int argc, char* argv[]) {
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
