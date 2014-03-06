#include "presenter.h"
#include "messages.h"
#include "writer.h"
#include "reader.h"

void reset_screen() {
  write_out(reset_screen_message);
}

void display_space(char space, int i) {
  if (space == EMPTY) {
    write_outf(empty_space_message, i + 1);
  } else {
    write_outf(taken_space_message, space);
  }
}

void display_row_transition(int factor) {
  write_out(row_transition_start);
  for(int i = 0; i < factor - 1; i++) {
    write_out(row_transition_piece);
  }
  write_out(row_transition_end);
}

void show_board(Board* board) {
  reset_screen();
  int size = get_size(board);
  int factor = get_factor(board);
  for(int i = 0; i < size; i++) {
    display_space(get_space(board, i), i);
    if (i % factor == factor - 1 && i != size - 1) {
      display_row_transition(factor);
    }
    if (i % factor < factor - 1) {
      write_out(cell_transition_message);
    }
  }
  write_out(end_board_message);
}

void show_winner(char winner) {
  write_outf(win_message, winner);
}

void show_draw(void) {
  write_out(draw_message);
}

void show_turn(int turn) {
  write_outf(turn_message, turn);
}

void show_invalid_move(void) {
  write_out(invalid_move_message);
  pause_writer(1);
}

int ask_for_move(Board* board, char piece, char other_piece) {
  write_out(ask_for_move_message);
  return read_int();
}
