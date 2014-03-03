#include <assert.h>
#include <string.h>

#include "spec_helper.h"
#include "board_test.h"
#include "board.h"

void test_new_board() {
  Board* board = new_board();
  for(int i = 0; i < 9; i++) {
    assert(get_space(board, i) == '-');
  }
  destroy_board(board);
}

void test_change_board() {
  Board* board = new_board();
  make_move(board, 0, 'X');
  assert(get_space(board, 0) == 'X');
  destroy_board(board);
}

void test_board_not_full() {
  Board* board = new_board();
  assert(!is_full(board));
  destroy_board(board);
}

void test_board_is_full() {
  Board* board = new_board();
  for(int i = 0; i < 9; i++) {
    make_move(board, i, 'X');
  }
  assert(is_full(board));
  destroy_board(board);
}

void test_board_is_empty() {
  Board* board = new_board();
  assert(is_empty(board));
  destroy_board(board);
}

void test_board_is_won_row() {
  Board* board = new_board();
  assert(!is_won(board));
  make_move(board, 0, 'X');
  make_move(board, 1, 'X');
  make_move(board, 2, 'X');
  assert(is_won(board));
  destroy_board(board);
}

void test_board_is_won_column() {
  Board* board = new_board();
  assert(!is_won(board));
  make_move(board, 0, 'X');
  make_move(board, 3, 'X');
  make_move(board, 6, 'X');
  assert(is_won(board));
  destroy_board(board);
}

void test_board_is_won_diag1() {
  Board* board = new_board();
  assert(!is_won(board));
  make_move(board, 0, 'X');
  make_move(board, 4, 'X');
  make_move(board, 8, 'X');
  assert(is_won(board));
  destroy_board(board);
}

void test_board_is_won_diag2() {
  Board* board = new_board();
  assert(!is_won(board));
  make_move(board, 2, 'X');
  make_move(board, 4, 'X');
  make_move(board, 6, 'X');
  assert(is_won(board));
  destroy_board(board);
}

void test_board_finds_winner() {
  Board* board = new_board();
  make_move(board, 2, 'X');
  make_move(board, 1, 'O');
  make_move(board, 4, 'X');
  make_move(board, 0, 'O');
  make_move(board, 6, 'X');
  assert(winner(board) == 'X');
  destroy_board(board);
}

void test_board_is_done() {
  Board* board = new_board();
  make_move(board, 6, 'X');
  make_move(board, 7, 'X');
  make_move(board, 8, 'X');
  assert(is_done(board));
  destroy_board(board);
}

void test_board_is_draw() {
  Board* board = draw_board();
  assert(is_draw(board));
  destroy_board(board);
}

void test_valid_move() {
  Board* board = new_board();
  bool check = is_valid_move(board, 0);
  assert(check);
  destroy_board(board);
}

void test_invalid_move() {
  Board* board = new_board();
  make_move(board, 0, 'X');
  bool check = is_valid_move(board, 0);
  assert(!check);
  destroy_board(board);
}

void test_board_invalid_move_when_taken() {
  Board* board = new_board();
  make_move(board, 0, 'X');
  assert(make_move(board, 0, 'O') == -1);
  destroy_board(board);
}

void test_board_invalid_move_when_out_of_range() {
  Board* board = new_board();
  assert(make_move(board, 9, 'O') == -1);
  destroy_board(board);
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
  test_valid_move();
  success();
  test_invalid_move();
  success();
  test_board_invalid_move_when_taken();
  success();
  test_board_invalid_move_when_out_of_range();
  success();
}

