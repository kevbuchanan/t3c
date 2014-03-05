#include <assert.h>

#include "spec_helper.h"
#include "ttt_ai_test.h"
#include "ttt_ai.h"
#include "board.h"
#include <stdio.h>

void play_all_games(Board* board, char first, char second, char ai) {
  if (is_done(board)) return;
  if (first == ai) {
    int move = hard_move(board, first, second);
    make_move(board, move, first);
    play_all_games(board, second, first, ai);
    unset_move(board, move);
  } else {
    for(int i = 0; i < get_size(board); i++) {
      if (make_move(board, i, first) != -1) {
        assert(winner(board) == EMPTY);
        play_all_games(board, second, first, ai);
        unset_move(board, i);
      }
    }
  }
}

void test_empty_board() {
  Board* board = new_board(3);
  int move = hard_move(board, 'X', 'O');
  assert(move == 4);
  destroy_board(board);
}

void test_take_win() {
  Board* board = new_board(3);
  make_move(board, 0, 'X');
  make_move(board, 3, 'O');
  make_move(board, 1, 'X');
  make_move(board, 4, 'O');
  int move = hard_move(board, 'X', 'O');
  assert(move == 2);
  destroy_board(board);
}

void test_take_draw() {
  Board* board = new_board(3);
  make_move(board, 0, 'X');
  make_move(board, 1, 'O');
  make_move(board, 2, 'X');
  make_move(board, 3, 'O');
  make_move(board, 4, 'X');
  make_move(board, 5, 'O');
  make_move(board, 6, 'O');
  int move = hard_move(board, 'O', 'X');
  assert(move == 8);
  destroy_board(board);
}

void test_medium_move() {
  Board* board = new_board(3);
  make_move(board, 2, 'X');
  make_move(board, 6, 'X');
  make_move(board, 0, 'O');
  int move = medium_move(board, 'O', 'X');
  assert(move == 4);
  destroy_board(board);
}

void test_easy_move() {
  Board* board = new_board(3);
  make_move(board, 3, 'X');
  make_move(board, 5, 'X');
  make_move(board, 6, 'O');
  int move = easy_move(board, 'O', 'X');
  assert(move < 9 && move >= 0);
  destroy_board(board);
}

void test_never_loses_going_first() {
  Board* board = new_board(3);
  play_all_games(board, 'X', 'O', 'X');
  destroy_board(board);
}

void test_never_loses_going_second() {
  Board* board = new_board(3);
  play_all_games(board, 'X', 'O', 'O');
  destroy_board(board);
}

void ttt_ai_test() {
  test_empty_board();
  success();
  test_take_win();
  success();
  test_take_draw();
  success();
  test_medium_move();
  success();
  test_easy_move();
  success();
  test_never_loses_going_first();
  success();
  test_never_loses_going_second();
  success();
}
