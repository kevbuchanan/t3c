#include "presenter.h"
#include "writer.h"
#include "reader.h"

void clear_screen() {
  write_out("\e[1;1H\e[2J");
}

void display_space(char space, int i) {
  if (space == EMPTY) {
    write_outf("%c ", space);
  } else {
    write_outf("%c ", space);
  }
}

void show_board(Board* board) {
  clear_screen();
  write_out("\n");
  int size = get_size(board);
  int factor = get_factor(board);
  for(int i = 0; i < size; i++) {
    display_space(get_space(board, i), i);
    if (i % factor == factor - 1) write_out("\n");
  }
}

void show_message(char* message) {
  write_out(message);
}

void show_messagef(char* message, char sub) {
  write_outf(message, sub);
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

void show_invalid_move(void) {
  show_message("\nInvalid move\n");
  pause_writer(1);
}

int ask_for_move(Board* board, char piece, char other_piece) {
  show_message("\nEnter your move:\n");
  return read_int();
}
