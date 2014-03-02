#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "spec_helper.h"
#include "minimax.h"
#include "board.h"

void test_empty_board() {
  char* board = new_board();
  int move = next_move(board, 'X', 'O');
  assert(move == 4);
  free_board(board);
}

void test_take_win() {
  char* board = new_board();
  make_move(board, 0, 'X');
  make_move(board, 3, 'O');
  make_move(board, 1, 'X');
  make_move(board, 4, 'O');
  int move = next_move(board, 'X', 'O');
  assert(move == 2);
  free_board(board);
}

void test_take_draw() {
  char* board = new_board();
  make_move(board, 0, 'X');
  make_move(board, 1, 'O');
  make_move(board, 2, 'X');
  make_move(board, 3, 'O');
  make_move(board, 4, 'X');
  make_move(board, 5, 'O');
  make_move(board, 6, 'O');
  int move = next_move(board, 'O', 'X');
  assert(move == 8);
  free_board(board);
}

void test_never_loses_going_first() {
  char* board = new_board();
  play_all_games(board, 'X', 'O', 'X');
  free_board(board);
}

void test_never_loses_going_second() {
  char* board = new_board();
  play_all_games(board, 'X', 'O', 'O');
  free_board(board);
}

void minimax_test() {
  test_empty_board();
  test_take_win();
  test_take_draw();
//  test_never_loses_going_first();
//  test_never_loses_going_second();
  success();
}
