#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "board.h"

#define SIZE 9
#define FACTOR 3

struct _Board {
  char* spaces;
};

Board* new_board() {
  Board* board = malloc(sizeof(Board));
  board->spaces = malloc(SIZE * sizeof(char) + 1);

  char board_string[SIZE + 1] = "";
  for(int i = 0; i < SIZE; i++) {
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

int get_size(Board* board) {
  return SIZE;
}

int get_factor(Board* board) {
  return FACTOR;
}

bool is_valid_move(Board* board, int space) {
  return space < SIZE && board->spaces[space] == EMPTY;
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
  for(int i = 0; i < SIZE; i++) {
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
  return empty_spaces == SIZE;
}

char check_rows(Board* board) {
  int offset = 0;
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < FACTOR; i++) {
    for(int j = 0; j < FACTOR; j++) {
      char this = board->spaces[j + (FACTOR * offset)];
      if (this == space && this != EMPTY) {
        count++;
      } else {
        space = this;
        count = 1;
      }
    }
    if (count == FACTOR) {
      return space;
    } else {
      offset += 1;
      count = 0;
    }
  }
  return EMPTY;
}

char check_cols(Board* board) {
  int offset = 0;
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < FACTOR; i++) {
    for(int j = 0; j < FACTOR; j++) {
      char this = board->spaces[(j * FACTOR) + i];
      if (this == space && this != EMPTY) {
        count++;
      } else {
        space = this;
        count = 1;
      }
    }
    if (count == FACTOR) {
      return space;
    } else {
      offset += 1;
      count = 0;
    }
  }
  return EMPTY;
}

char check_diag1(Board* board) {
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < FACTOR; i++) {
    char this = board->spaces[i * (1 + FACTOR)];
    if (this == space && this != EMPTY) {
      count++;
    } else {
      space = this;
      count = 1;
    }
  }
  if (count == FACTOR) {
    return space;
  }
  return EMPTY;
}

char check_diag2(Board* board) {
  char space = EMPTY;
  int count = 0;
  int start = FACTOR - 1;
  for(int i = 0; i < FACTOR; i++) {
    char this = board->spaces[start + (i * start)];
    if (this == space && this != EMPTY) {
      count++;
    } else {
      space = this;
      count = 1;
    }
  }
  if (count == FACTOR) {
    return space;
  }
  return EMPTY;
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

