#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "spec_helper.h"
#include "presenter_test.h"
#include "presenter.h"
#include "board.h"
#include "log.h"

void test_display_empty_board() {
  Board* board = new_board(3);
  char expected[] = "1 2 3 4 5 6 7 8 9 ";
  show_board(board);
  destroy_board(board);
  assert(strstr(writer_log, expected));
}

void test_display_played_board() {
  Board* board = draw_board();
  char expected[] = "X O X O X O O X O ";
  show_board(board);
  destroy_board(board);
  assert(strstr(writer_log, expected));
}

void test_display_turn() {
  show_turn(1);
  assert(strstr(writer_log, "Player 1's turn"));
}

void test_display_invalid_move() {
  show_invalid_move();
  assert(strstr(writer_log, "Invalid move"));
}

void test_show_winner() {
  show_winner('X');
  assert(strstr(writer_log, "X wins!"));
}

void test_show_draw() {
  show_draw();
  assert(strstr(writer_log, "Draw"));
}

void test_get_move() {
  freopen("test/fixtures/test_input.txt", "r", stdin);
  Board* board = new_board(3);
  int move = ask_for_move(board, 'X', 'O');
  destroy_board(board);
  assert(move == 5);
}

void presenter_test() {
  init_log();

  test_display_empty_board();
  reset_log();
  success();

  test_display_played_board();
  reset_log();
  success();

  test_display_turn();
  reset_log();
  success();

  test_display_invalid_move();
  reset_log();
  success();

  test_show_winner();
  reset_log();
  success();

  test_show_draw();
  reset_log();
  success();

  test_get_move();
  success();

  destroy_log();
}
