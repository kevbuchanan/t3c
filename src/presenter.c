#include <stdio.h>

#include "writer.h"
#include "board.h"

void clear_screen() {
  write("\e[1;1H\e[2J");
}

void display_space(char space, int i) {
  if (space == EMPTY) {
    writef("%c ", space);
  } else {
    writef("%c ", space);
  }
}

void show_board(Board* board) {
  clear_screen();
  write("\n");
  int size = get_size(board);
  int factor = get_factor(board);
  for(int i = 0; i < size; i++) {
    display_space(get_space(board, i), i);
    if (i % factor == factor - 1) write("\n");
  }
}

void show_message(char* message) {
  write(message);
}

void show_messagef(char* message, char sub) {
  writef(message, sub);
}

void show_winner(char winner) {
  show_messagef("\n%c wins!\n", winner);
}

void show_draw(void) {
  show_message("\nDraw\n");
}

void show_turn(int turn) {
  show_messagef("\nPlayer %d's turn\n", turn);
}

int ask_for_move(Board* board, char piece, char other_piece) {
  char input[3];
  int move;
  fgets(input, 3, stdin);
  sscanf(input, "%d", &move);
  return move - 1;
}
