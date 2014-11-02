#include "player_factory.h"
#include "presenter.h"
#include "ttt_ai.h"

MoveHandler get_handler(PlayerType type) {
  switch (type) {
    case human :
      return &ask_for_move;
      break;
    case hard :
      return &hard_move;
      break;
    case medium :
      return &medium_move;
      break;
    case easy :
      return &easy_move;
      break;
  }
}

Player* build_player(char piece, PlayerType type) {
  MoveHandler handler = get_handler(type);
  return create_player(piece, handler);
}
