#include <assert.h>
#include <string.h>

#include "spec_helper.h"
#include "game_test.h"
#include "game.h"
#include "board.h"
#include "log.h"
#include "player.h"

void test_handles_draw() {
  Board* board = draw_board();
  Player* p1 = create_player('X', &fake_move);
  Player* p2 = create_player('O', &fake_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  assert(strstr(writer_log, "Draw"));
}

void test_handles_win() {
  Board* board = draw_board();
  unset_move(board, 0);
  Player* p1 = create_player('O', &fake_move);
  Player* p2 = create_player('X', &fake_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  assert(strstr(writer_log, "\n- O X \nO X O \nO X O \n"));
  assert(strstr(writer_log, "Player 1's turn"));
  assert(strstr(writer_log, "\nO O X \nO X O \nO X O \n"));
  assert(strstr(writer_log, "O wins!"));
}

void test_gets_valid_move() {
  Board* board = draw_board();
  unset_move(board, 1);
  Player* p1 = create_player('X', &incrementing_move);
  Player* p2 = create_player('O', &fake_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  current_move = 0;
  assert(strstr(writer_log, "Player 1's turn"));
  assert(strstr(writer_log, "Invalid move"));
  assert(strstr(writer_log, "X wins!"));
}

void test_switches_turns() {
  Board* board = draw_board();
  unset_move(board, 0);
  unset_move(board, 1);
  Player* p1 = create_player('X', &incrementing_move);
  Player* p2 = create_player('O', &incrementing_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  current_move = 0;
  assert(strstr(writer_log, "Player 1's turn"));
  assert(strstr(writer_log, "Player 2's turn"));
  assert(strstr(writer_log, "Draw"));
}

void game_test() {
  init_log();

  test_handles_draw();
  reset_log();
  success();

  test_handles_win();
  reset_log();
  success();

  test_gets_valid_move();
  reset_log();
  success();

  test_switches_turns();
  reset_log();
  success();

  destroy_log();
}
