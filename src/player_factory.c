#include "player_factory.h"
#include "player.h"
#include "presenter.h"
#include "ttt_ai.h"

MoveHandler human_strategy() {
  return &ask_for_move;
}

MoveHandler difficult_strategy() {
  return &hard_move;
}

MoveHandler medium_strategy() {
  return &medium_move;
}

MoveHandler easy_strategy() {
  return &easy_move;
}

Player* build_player(char piece, PlayerType type) {
  Player* player;
  switch (type) {
    case human :
      player = create_player(piece, human_strategy());
      break;
    case difficult :
      player = create_player(piece, difficult_strategy());
      break;
    case medium :
      player = create_player(piece, medium_strategy());
      break;
    case easy :
      player = create_player(piece, easy_strategy());
      break;
  }
  return player;
}
