#include <stdlib.h>
#include <time.h>

#include "ttt_ai.h"

#define INFINITY 100
#define SCORE 50
#define MAX_DEPTH 4

int space_for(int i, int starting_point, int size) {
  int n = i - starting_point;
  if (n < 0) {
    return n + size;
  } else {
    return n;
  }
}

int max_move(Board* board, char piece, char other_piece, int depth, int max_depth, int alpha, int beta);

int min_move(Board* board, char piece, char other_piece, int depth, int max_depth, int alpha, int beta) {
  if (winner(board) == other_piece) return SCORE - depth;
  if (is_draw(board) || depth == max_depth) return 0;

  int min = INFINITY;

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
  if (winner(board) == other_piece) return -SCORE + depth;
  if (is_draw(board) || depth == max_depth) return 0;

  int space;
  int max = -INFINITY;

  int size = get_size(board);
  int rand_start = rand() % size;

  for(int i = 0; i < size; i++) {
    int j = space_for(i, rand_start, size);
    if (make_move(board, j, piece) != -1) {
      int score = min_move(board, other_piece, piece, depth + 1, max_depth, max, beta);
      if (score > max) {
        max = score;
        space = j;
      }
      unset_move(board, j);
      if (max >= beta) break;
    }
  }

  if (depth == 0) {
    return space;
  } else {
    return max;
  }
}

int hard_move(Board* board, char piece, char other_piece) {
  int factor = get_factor(board);
  if (is_empty(board)) return factor + 1;

  int max_depth = 10;
  if (factor > 3) max_depth = MAX_DEPTH;

  return max_move(board, piece, other_piece, 0, max_depth, -INFINITY, INFINITY);
}

int medium_move(Board* board, char piece, char other_piece) {
  return max_move(board, piece, other_piece, 0, 2, -INFINITY, INFINITY);
}

int easy_move(Board* board, char piece, char other_piece) {
  int random_move = rand() % get_size(board);
  return random_move;
}
