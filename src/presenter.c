#include <stdio.h>

#include "writer.h"
#include "board.h"

void show_board(Board* board) {
  write("\n");
  int size = get_size(board);
  int factor = get_factor(board);
  for(int i = 0; i < size; i++) {
    write_char("%c ", get_space(board, i));
    if (i % factor == factor - 1) write("\n");
  }
}

void show_message(char* message) {
  write(message);
}

int ask_for_move(Board* board, char piece, char other_piece) {
  char input[3];
  int move;
  fgets(input, 3, stdin);
  sscanf(input, "%d", &move);
  return move;
}
