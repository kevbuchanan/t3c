#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "spec_helper.h"
#include "presenter_test.h"
#include "presenter.h"
#include "board.h"
#include "writer.h"

void test_display_empty_board() {
  Board* board = new_board();
  char expected[] = "\e[1;1H\e[2J\n- - - \n- - - \n- - - \n";
  show_board(board);
  destroy_board(board);
  assert(strcmp(writer_log, expected) == 0);
}

void test_display_played_board() {
  Board* board = draw_board();
  char expected[] = "\e[1;1H\e[2J\nX O X \nO X O \nO X O \n";
  show_board(board);
  destroy_board(board);
  assert(strcmp(writer_log, expected) == 0);
}

void test_display_turn() {
  show_turn(1);
  assert(strcmp(writer_log, "\nPlayer 1's turn\n") == 0);
}

void test_show_winner() {
  show_winner('X');
  assert(strcmp(writer_log, "\nX wins!\n") == 0);
}

void test_show_draw() {
  show_draw();
  assert(strcmp(writer_log, "\nDraw\n") == 0);
}

void test_get_move() {
  freopen("fixtures/test_input.txt", "r", stdin);
  Board* board = new_board();
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
