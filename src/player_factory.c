#include "player_factory.h"
#include "player.h"
#include "presenter.h"
#include "ttt_ai.h"

MoveHandler human_strategy() {
  return &ask_for_move;
}

MoveHandler computer_strategy() {
  return &hard_move;
}

Player* build_player(char piece, PlayerType type) {
  Player* player;
  switch (type) {
    case human :
      player = create_player(piece, human_strategy());
      break;
    case computer :
      player = create_player(piece, computer_strategy());
      break;
  }
  return player;
}
