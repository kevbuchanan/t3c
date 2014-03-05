#include "presenter.h"
#include "messages.h"
#include "writer.h"
#include "reader.h"

void show_message(char* message) {
  write_out(message);
}

void show_messagef(char* message, char sub) {
  write_outf(message, sub);
}

void reset_screen() {
  show_message(reset_screen_message);
}

void display_space(char space, int i) {
  if (space == EMPTY) {
    show_messagef(empty_space_message, i + 1);
  } else {
    show_messagef(taken_space_message, space);
  }
}

void show_board(Board* board) {
  reset_screen();
  int size = get_size(board);
  int factor = get_factor(board);
  for(int i = 0; i < size; i++) {
    display_space(get_space(board, i), i);
    if (i % factor == factor - 1) show_message(end_row_message);
  }
}

void show_winner(char winner) {
  show_messagef(win_message, winner);
}

void show_draw(void) {
  show_message(draw_message);
}

void show_turn(int turn) {
  show_messagef(turn_message, turn);
}

void show_invalid_move(void) {
  show_message(invalid_move_message);
  pause_writer(1);
}

int ask_for_move(Board* board, char piece, char other_piece) {
  show_message(ask_for_move_message);
  return read_int();
}
