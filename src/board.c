#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "board.h"

char* new_board() {
  char* board = malloc(SIZE * sizeof(char) + 1);

  char board_string[SIZE + 1] = "";
  for(int i = 0; i < SIZE; i++) {
    board_string[i] = EMPTY;
  }

  strcpy(board, board_string);
  return board;
}

void destroy_board(char* board) {
  free(board);
}

bool valid_move(char* board, int space) {
  return space < SIZE && board[space] == EMPTY;
}

int make_move(char* board, int space, char piece) {
  if (valid_move(board, space)) {
    board[space] = piece;
    return 0;
  } else {
    return -1;
  }
}

void unset_move(char* board, int space) {
  board[space] = EMPTY;
}

int empty_count(char* board) {
  int count = 0;
  for(int i = 0; i < SIZE; i++) {
    if (board[i] == EMPTY) {
      count += 1;
    }
  }
  return count;
}

bool is_full(char* board) {
  int empty_spaces = empty_count(board);
  return empty_spaces == 0;
}

bool is_empty(char* board) {
  int empty_spaces = empty_count(board);
  return empty_spaces == SIZE;
}

char check_rows(char* board) {
  int offset = 0;
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < FACTOR; i++) {
    for(int j = 0; j < FACTOR; j++) {
      char this = board[j + (FACTOR * offset)];
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

char check_cols(char* board) {
  int offset = 0;
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < FACTOR; i++) {
    for(int j = 0; j < FACTOR; j++) {
      char this = board[(j * FACTOR) + i];
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

char check_diag1(char* board) {
  char space = EMPTY;
  int count = 0;
  for(int i = 0; i < FACTOR; i++) {
    char this = board[i * (1 + FACTOR)];
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

char check_diag2(char* board) {
  char space = EMPTY;
  int count = 0;
  int start = FACTOR - 1;
  for(int i = 0; i < FACTOR; i++) {
    char this = board[start + (i * start)];
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

bool is_won(char* board) {
  if (check_rows(board) != EMPTY) {
    return true;
  }
  if (check_cols(board) != EMPTY) {
    return true;
  }
  if (check_diag1(board) != EMPTY) {
    return true;
  }
  if (check_diag2(board) != EMPTY) {
    return true;
  }
  return false;
}

char winner(char* board) {
  char piece;
  if ((piece = check_rows(board)) != EMPTY) {
    return piece;
  }
  if ((piece = check_cols(board)) != EMPTY) {
    return piece;
  }
  if ((piece = check_diag1(board)) != EMPTY) {
    return piece;
  }
  if ((piece = check_diag2(board)) != EMPTY) {
    return piece;
  }
  return EMPTY;
}

bool is_draw(char* board) {
  return is_full(board) && winner(board) == EMPTY;
}

bool is_done(char* board) {
  return winner(board) != EMPTY || is_draw(board);
}

