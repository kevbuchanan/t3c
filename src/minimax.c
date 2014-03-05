#include "minimax.h"
#include "board.h"

int max_move(Board* board, char piece, char other_piece, int depth, int max_depth, int alpha, int beta);

int min_move(Board* board, char piece, char other_piece, int depth, int max_depth, int alpha, int beta) {
  if (winner(board) == other_piece) return 50 - depth;
  if (is_draw(board) || depth == max_depth) return 0;

  int min = 100;

  for(int i = 0; i < get_size(board); i++) {
    if (make_move(board, i, piece) != -1) {
      int score = max_move(board, other_piece, piece, depth + 1, max_depth, alpha, min);
      if (score < min) min = score;
      unset_move(board, i);
      if (alpha >= min) break;
    }
  }

  return min;
}

int max_move(Board* board, char piece, char other_piece, int depth, int max_depth, int alpha, int beta) {
  if (winner(board) == other_piece) return -(50 - depth);
  if (is_draw(board) || depth == max_depth) return 0;

  int space;
  int max = -100;

  for(int i = 0; i < get_size(board); i++) {
    if (make_move(board, i, piece) != -1) {
      int score = min_move(board, other_piece, piece, depth + 1, max_depth, max, beta);
      if (score > max) {
        max = score;
        space = i;
      }
      unset_move(board, i);
      if (max >= beta) break;
    }
  }

  if (depth == 0) {
    return space;
  } else {
    return max;
  }
}

int next_move(Board* board, char piece, char other_piece) {
  int factor = get_factor(board);
  if (is_empty(board)) return factor + 1;
  int max_depth = 6;
  if (factor > 3) max_depth = 3;
  return max_move(board, piece, other_piece, 0, max_depth, -100, 100);
}
