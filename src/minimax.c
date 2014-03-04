#include "minimax.h"
#include "board.h"

int max_move(Board* board, char piece, char other_piece, int depth, int alpha, int beta);

int min_move(Board* board, char piece, char other_piece, int depth, int alpha, int beta) {
  if (winner(board) == other_piece) return 50 - depth;
  if (is_draw(board)) return 0;
  if (alpha >= beta) return alpha;

  for(int i = 0; i < get_size(board); i++) {
    if (make_move(board, i, piece) != -1) {
      int score = max_move(board, other_piece, piece, depth + 1, alpha, beta);
      if (score < beta) {
        beta = score;
      }
      unset_move(board, i);
    }
  }

  return beta;
}

int max_move(Board* board, char piece, char other_piece, int depth, int alpha, int beta) {
  if (winner(board) == other_piece) return -(50 - depth);
  if (is_draw(board)) return 0;
  if (alpha >= beta) return alpha;

  int space;

  for(int i = 0; i < get_size(board); i++) {
    if (make_move(board, i, piece) != -1) {
      int score = min_move(board, other_piece, piece, depth + 1, alpha, beta);
      if (score > alpha) {
        alpha = score;
        space = i;
      }
      unset_move(board, i);
    }
  }

  if (depth == 0) {
    return space;
  } else {
    return alpha;
  }
}

int next_move(Board* board, char piece, char other_piece) {
  if (is_empty(board)) return get_factor(board) + 1;
  return max_move(board, piece, other_piece, 0, -100, 100);
}
