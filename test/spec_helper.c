#include <stdio.h>

#include "spec_helper.h"
#include "board.h"

static int test_count = 0;

void success(void) {
  char* success = "\x1B[32m.";
  printf("%s", success);
  test_count++;
}

void show_results(void) {
  puts("\n");
  printf("Completed %d tests\n", test_count);
  puts("");
}

int fake_move(char* board, char piece, char other_piece) {
  return 0;
}

int current_move = 0;

int incrementing_move(char* board, char piece, char other_piece) {
  int move = current_move;
  current_move++;
  return move;
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

