#include "game.h"
#include "presenter.h"

int do_turn(int turn, Board* board, Player* player, Player* other_player) {
  show_board(board);

  show_turn(turn + 1);

  int move = player->get_move(board, player->piece, other_player->piece);

  if (make_move(board, move, player->piece) != -1) {
    return 1 - turn;
  } else {
    show_invalid_move();
    return do_turn(turn, board, player, other_player);
  }
}

void end_game(Board* board) {
  show_board(board);

  if (is_draw(board)) {
    show_draw();
  } else {
    show_winner(winner(board));
  }
}

void start_game(Board* board, Player* player1, Player* player2) {
  int turn = 0;

  while(!is_done(board)) {
    if (turn == 0) {
      turn = do_turn(turn, board, player1, player2);
    } else {
      turn = do_turn(turn, board, player2, player1);
    }
  }

  end_game(board);
}
