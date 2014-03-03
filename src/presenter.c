#include <stdio.h>

#include "writer.h"

void show_board(char* board) {
  for(int i = 0; i < 9; i++) {
    write_char("%c ", board[i]);
    if (i % 3 == 2) write("\n");
  }
}

void show_message(char* message) {
  write(message);
}

int ask_for_move(void) {
  char input[3];
  int move;
  fgets(input, 3, stdin);
  sscanf(input, "%d", &move);
  return move;
}
