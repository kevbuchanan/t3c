#include "board.h"

int max_move(Board* board, char piece, char other_piece, int depth);

int min_move(Board* board, char piece, char other_piece, int depth) {
  if (winner(board) == other_piece) return 50 - depth;
  if (is_draw(board)) return 0;

  int min = 100;

  for(int i = 0; i < get_size(board); i++) {
    if (make_move(board, i, piece) != -1) {
      int score = max_move(board, other_piece, piece, depth + 1);
      if (score < min) {
        min = score;
      }
      unset_move(board, i);
    }
  }

  return min;
}

int max_move(Board* board, char piece, char other_piece, int depth) {
  if (winner(board) == other_piece) return -(50 - depth);
  if (is_draw(board)) return 0;

  int space;
  int max = -100;

  for(int i = 0; i < get_size(board); i++) {
    if (make_move(board, i, piece) != -1) {
      int score = min_move(board, other_piece, piece, depth + 1);
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

int next_move(Board* board, char piece, char other_piece) {
  if (is_empty(board)) return 4;
  return max_move(board, piece, other_piece, 0);
}
