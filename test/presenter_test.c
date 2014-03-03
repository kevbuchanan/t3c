#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "presenter.h"
#include "board.h"
#include "writer.h"

void test_display_empty_board() {
  char* board = new_board();
  char expected[] = "- - - \n- - - \n- - - \n";
  show_board(board);
  destroy_board(board);
  assert(strcmp(writer_log, expected) == 0);
}

void test_display_played_board() {
  char* board = draw_board();
  char expected[] = "X O X \nO X O \nO X O \n";
  show_board(board);
  destroy_board(board);
  assert(strcmp(writer_log, expected) == 0);
}

void presenter_test() {
  init_log();

  test_display_empty_board();
  success();

  reset_log();

  test_display_played_board();
  success();

  destroy_log();
}
