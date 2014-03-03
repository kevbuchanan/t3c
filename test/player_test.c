#include <assert.h>

#include "spec_helper.h"
#include "player.h"
#include "board.h"

int fake_move(char* board, char piece, char other_piece) {
  return 1;
}

void test_player_piece() {
  Player* player = create_player('X', &fake_move);
  assert(player->piece == 'X');
  destroy_player(player);
}

void test_player_move() {
  Player* player = create_player('X', &fake_move);
  char* board = new_board();
  assert(player->get_move(board, 'X', 'O') == 1);
  destroy_board(board);
  destroy_player(player);
}

void player_test() {
  test_player_piece();
  success();
  test_player_move();
  success();
}
