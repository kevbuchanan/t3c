#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "spec_helper.c"
#include "../src/board.h"

void test_new_board() {
  char* board = new_board();
  assert(strcmp(board, "---------") == 0);
}

void test_change_board() {
  char* board = new_board();
  make_move(board, 0, 'X');
  assert(board[0] == 'X');
}

void test_board_not_full() {
  char* board = new_board();
  assert(!is_full(board));
}

void test_board_is_full() {
  char* board = new_board();
  for(int i = 0; i < 9; i++) {
    make_move(board, i, 'X');
  }
  assert(is_full(board));
}

void test_board_is_empty() {
  char* board = new_board();
  assert(is_empty(board));
}

void test_board_is_won_row() {
  char* board = new_board();
  assert(!is_won(board));
  make_move(board, 0, 'X');
  make_move(board, 1, 'X');
  make_move(board, 2, 'X');
  assert(is_won(board));
}

void test_board_is_won_column() {
  char* board = new_board();
  assert(!is_won(board));
  make_move(board, 0, 'X');
  make_move(board, 3, 'X');
  make_move(board, 6, 'X');
  assert(is_won(board));
}

void test_board_is_won_diag1() {
  char* board = new_board();
  assert(!is_won(board));
  make_move(board, 0, 'X');
  make_move(board, 4, 'X');
  make_move(board, 8, 'X');
  assert(is_won(board));
}

void test_board_is_won_diag2() {
  char* board = new_board();
  assert(!is_won(board));
  make_move(board, 2, 'X');
  make_move(board, 4, 'X');
  make_move(board, 6, 'X');
  assert(is_won(board));
}

void test_board_finds_winner() {
  char* board = new_board();
  make_move(board, 2, 'X');
  make_move(board, 1, 'O');
  make_move(board, 4, 'X');
  make_move(board, 0, 'O');
  make_move(board, 6, 'X');
  assert(winner(board) == 'X');
}

void test_board_is_done() {
  char* board = new_board();
  make_move(board, 6, 'X');
  make_move(board, 7, 'X');
  make_move(board, 8, 'X');
  assert(is_done(board));
}

void test_board_is_draw() {
  char* board = new_board();
  make_move(board, 0, 'X');
  make_move(board, 1, 'O');
  make_move(board, 2, 'X');
  make_move(board, 3, 'O');
  make_move(board, 4, 'X');
  make_move(board, 5, 'O');
  make_move(board, 6, 'O');
  make_move(board, 7, 'X');
  make_move(board, 8, 'O');
  assert(is_draw(board));
}

void test_board_invalid_move_when_taken() {
  char* board = new_board();
  make_move(board, 0, 'X');
  assert(make_move(board, 0, 'O') == -1);
}

void test_board_invalid_move_when_out_of_range() {
  char* board = new_board();
  assert(make_move(board, 9, 'O') == -1);
}

void board_test() {
  test_new_board();
  success();
  test_change_board();
  success();
  test_board_not_full();
  success();
  test_board_is_full();
  success();
  test_board_is_empty();
  success();
  test_board_is_won_row();
  success();
  test_board_is_won_column();
  success();
  test_board_is_won_diag1();
  success();
  test_board_is_won_diag2();
  success();
  test_board_finds_winner();
  success();
  test_board_is_done();
  success();
  test_board_is_draw();
  success();
  test_board_invalid_move_when_taken();
  success();
  test_board_invalid_move_when_out_of_range();
  success();
}
