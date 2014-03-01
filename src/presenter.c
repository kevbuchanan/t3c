#include <stdio.h>

void show_board(char* board) {
  for(int i = 0; i < 9; i++) {
    printf("%c ", board[i]);
    if (i % 3 == 2) { puts(""); }
  }
}
