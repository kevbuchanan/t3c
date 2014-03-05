#include <stdlib.h>
#include <string.h>

#include "board.h"

struct _Board {
  char* spaces;
  int factor;
};

Board* new_board(int factor) {
  Board* board = malloc(sizeof(Board));
  board->factor = factor;
  board->spaces = malloc(100);

  char board_string[100] = "";
  int size = factor * factor;
  for(int i = 0; i < size; i++) {
    board_string[i] = EMPTY;
  }

  strcpy(board->spaces, board_string);
  return board;
}

void destroy_board(Board* board) {
  free(board->spaces);
  free(board);
}

char get_space(Board* board, int space) {
  return board->spaces[space];
}

int get_factor(Board* board) {
  return board->factor;
}

int get_size(Board* board) {
  int factor = get_factor(board);
  return factor * factor;
}

bool is_valid_move(Board* board, int space) {
  return space < get_size(board) && board->spaces[space] == EMPTY;
}

int make_move(Board* board, int space, char piece) {
  if (is_valid_move(board, space)) {
    board->spaces[space] = piece;
    return 0;
  } else {
    return -1;
  }
}

void unset_move(Board* board, int space) {
  board->spaces[space] = EMPTY;
}

int empty_count(Board* board) {
  int count = 0;
  for(int i = 0; i < get_size(board); i++) {
    if (board->spaces[i] == EMPTY) {
      count += 1;
    }
  }
  return count;
}

bool is_full(Board* board) {
  int empty_spaces = empty_count(board);
  return empty_spaces == 0;
}

bool is_empty(Board* board) {
  int empty_spaces = empty_count(board);
  return empty_spaces == get_size(board);
}

char check_lines(Board* board, int rows) {
  int offset = 0;
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < board->factor; i++) {
    for(int j = 0; j < board->factor; j++) {
      char this;
      if (rows == 1) {
        this = board->spaces[j + (board->factor * offset)];
      } else {
        this = board->spaces[(j * board->factor) + i];
      }
      if (this == space && this != EMPTY) {
        count++;
      } else {
        space = this;
        count = 1;
      }
    }
    if (count == board->factor) {
      return space;
    } else {
      offset += 1;
      count = 0;
    }
  }
  return EMPTY;
}

char check_rows(Board* board) {
  return check_lines(board, 1);
}

char check_cols(Board* board) {
  return check_lines(board, 0);
}

char check_diag(Board* board, int direction) {
  char space = EMPTY;
  int count = 0;
  int start = board->factor - 1;
  for(int i = 0; i < board->factor; i++) {
    char this;
    if (direction == 1) {
      this = board->spaces[i * (1 + board->factor)];
    } else {
      this = board->spaces[start + (i * start)];
    }
    if (this == space && this != EMPTY) {
      count++;
    } else {
      space = this;
      count = 1;
    }
  }
  if (count == board->factor) {
    return space;
  }
  return EMPTY;
}

char check_diag1(Board* board) {
  return check_diag(board, 1);
}

char check_diag2(Board* board) {
  return check_diag(board, 0);
}

char winner(Board* board) {
  char piece;
  piece = check_rows(board);
  if (piece != EMPTY) return piece;
  piece = check_cols(board);
  if (piece != EMPTY) return piece;
  piece = check_diag1(board);
  if (piece != EMPTY) return piece;
  piece = check_diag2(board);
  return piece;
}

bool is_won(Board* board) {
  return winner(board) != EMPTY;
}

bool is_draw(Board* board) {
  return is_full(board) && winner(board) == EMPTY;
}

bool is_done(Board* board) {
  return winner(board) != EMPTY || is_draw(board);
}

