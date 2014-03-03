#include <string.h>
#include <stdbool.h>

#include "board.h"

int minimax(char* board, char piece, char other_piece, int depth, bool is_min, char ai) {
  if (winner(board) == ai) return 50 - depth;
  if (winner(board) == other_piece) return -(50 - depth);
  if (is_draw(board)) return 0;

  int space;

  if (is_min) {

    int min = 100;

    for(int i = 0; i < SIZE; i++) {
      if (make_move(board, i, piece) != -1) {
        int score = minimax(board, other_piece, piece, depth + 1, false, ai);
        if (score < min) {
          min = score;
          space = i;
        }
        unset_move(board, i);
      }
    }

    return min;

  } else {

    int max = -100;

    for(int i = 0; i < SIZE; i++) {
      if (make_move(board, i, piece) != -1) {
        int score = minimax(board, other_piece, piece, depth + 3, true, ai);
        if (score > max) {
          max = score;
          space = i;
        }
        unset_move(board, i);
      }
    }

    if (depth == 0) {
      return space;
    } else {
      return max;
    }
  }
}

int next_move(char* board, char piece, char other_piece) {
  if (is_empty(board)) return 4;
  return minimax(board, piece, other_piece, 0, false, piece);
}
