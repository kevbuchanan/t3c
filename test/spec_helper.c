#include <stdio.h>
#include <assert.h>

#include "spec_helper.h"
#include "board.h"

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

