#include <assert.h>

#include "spec_helper.h"
#include "minimax_test.h"
#include "minimax.h"
#include "board.h"

void play_all_games(Board* board, char first, char second, char ai) {
  if (winner(board) == ai || is_draw(board)) return;
  if (first == ai) {
    int move = next_move(board, first, second);
    make_move(board, move, first);
    assert(winner(board) == EMPTY || winner(board) == ai);
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
  Board* board = new_board();
  int move = next_move(board, 'X', 'O');
  assert(move == 4);
  destroy_board(board);
}

void test_take_win() {
  Board* board = new_board();
  make_move(board, 0, 'X');
  make_move(board, 3, 'O');
  make_move(board, 1, 'X');
  make_move(board, 4, 'O');
  int move = next_move(board, 'X', 'O');
  assert(move == 2);
  destroy_board(board);
}

void test_take_draw() {
  Board* board = new_board();
  make_move(board, 0, 'X');
  make_move(board, 1, 'O');
  make_move(board, 2, 'X');
  make_move(board, 3, 'O');
  make_move(board, 4, 'X');
  make_move(board, 5, 'O');
  make_move(board, 6, 'O');
  int move = next_move(board, 'O', 'X');
  assert(move == 8);
  destroy_board(board);
}

void test_never_loses_going_first() {
  Board* board = new_board();
  play_all_games(board, 'X', 'O', 'X');
  destroy_board(board);
}

void test_never_loses_going_second() {
  Board* board = new_board();
  play_all_games(board, 'X', 'O', 'O');
  destroy_board(board);
}

void minimax_test() {
  test_empty_board();
  success();
  test_take_win();
  success();
  test_take_draw();
  success();
  test_never_loses_going_first();
  success();
  test_never_loses_going_second();
  success();
}
