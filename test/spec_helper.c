#include <stdio.h>
#include <assert.h>

#include "spec_helper.h"
#include "board.h"
#include "minimax.h"

void success(void) {
  char* success = "\x1B[32m.";
  printf("%s", success);
}

char* draw_board(void) {
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
  return board;
}

void play_all_games(char* board, char first, char second, char ai) {
  if (winner(board) == ai || is_draw(board)) return;
  if (first == ai) {
    int move = next_move(board, first, second);
    make_move(board, move, first);
    play_all_games(board, second, first, ai);
    unset_move(board, move);
  } else {
    for(int i = 0; i < SIZE; i++) {
      if (make_move(board, i, first) != -1) {
        assert(winner(board) == EMPTY || winner(board) == ai);
        play_all_games(board, second, first, ai);
        unset_move(board, i);
      }
    }
  }
}
