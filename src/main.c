#include "board.h"
#include "game.h"
#include "player.h"
#include "minimax.h"
#include "presenter.h"

int main() {
  Board* board = new_board();

  Player* player1 = create_player('X', &ask_for_move);
  Player* player2 = create_player('O', &next_move);

  start_game(board, player1, player2);

  destroy_player(player1);
  destroy_player(player2);
  destroy_board(board);

  return 0;
}
