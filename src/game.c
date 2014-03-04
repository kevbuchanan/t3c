#include "game.h"
#include "board.h"
#include "presenter.h"
#include "player.h"

void start_game(Board* board, Player* player1, Player* player2) {
  show_board(board);

  int turn = 1;
  int move;

  while(!is_done(board)) {
    show_turn(turn);
    if (turn == 1) {
      move = player1->get_move(board, player1->piece, player2->piece);
      if (make_move(board, move, player1->piece) != -1) {
        turn = 2;
      }
    } else {
      move = player2->get_move(board, player2->piece, player1->piece);
      if (make_move(board, move, player2->piece) != -1) {
        turn = 1;
      }
    }
    show_board(board);
  }

  if (is_draw(board)) {
    show_draw();
  } else {
    show_winner(winner(board));
  }
}
