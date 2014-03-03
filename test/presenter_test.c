#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "spec_helper.h"
#include "presenter_test.h"
#include "presenter.h"
#include "board.h"
#include "writer.h"

void test_display_empty_board() {
  char* board = new_board();
  char expected[] = "\n- - - \n- - - \n- - - \n";
  show_board(board);
  destroy_board(board);
  assert(strcmp(writer_log, expected) == 0);
}

void test_display_played_board() {
  char* board = draw_board();
  char expected[] = "\nX O X \nO X O \nO X O \n";
  show_board(board);
  destroy_board(board);
  assert(strcmp(writer_log, expected) == 0);
}

void test_display_message() {
  char message[] = "Testing the presenter";
  show_message(message);
  assert(strcmp(writer_log, message) == 0);
}

void test_get_move() {
  freopen("fixtures/test_input.txt", "r", stdin);
  char* board = new_board();
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

  test_display_message();
  reset_log();
  success();

  test_get_move();
  success();

  destroy_log();
}
