#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "board.h"

int minimax(char* board, char piece, char other_piece, int depth, bool min, char ai) {
  if (winner(board) == ai) return 50 - depth;
  if (winner(board) == piece) return -(50 - depth);
  if (is_draw(board)) return 0;

  if (min) {
    int min = 100;
    for(int i = 0; i < SIZE; i++) {
      if (make_move(board, i, other_piece) != -1) {
        int score = minimax(board, other_piece, piece, depth + 1, false, ai);
        if (score < min) min = score;
        unset_move(board, i);
      }
    }
    return min;
  } else {
    int max = -100;
    for(int i = 0; i < SIZE; i++) {
      if (make_move(board, i, other_piece) != -1) {
        int score = minimax(board, other_piece, piece, depth + 3, true, ai);
        if (score > max) max = score;
        unset_move(board, i);
      }
    }
    return max;
  }
}

int next_move(char* board, char piece, char other_piece) {
  int scores[SIZE];
  for(int i = 0; i < SIZE; i++) {
    if (make_move(board, i, piece) != -1) {
      scores[i] = minimax(board, piece, other_piece, 0, true, piece);
      unset_move(board, i);
    } else {
      scores[i] = -100;
    }
  }

  int space;
  int max = -100;
  for(int i = 0; i < SIZE; i++) {
    if (scores[i] > max) {
      space = i;
      max = scores[i];
    }
  }
  return space;
}
