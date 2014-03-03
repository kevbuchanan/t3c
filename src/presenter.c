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
