#include "spec_helper.h"

#include "board_test.h"
#include "minimax_test.h"
#include "player_test.h"
#include "presenter_test.h"
#include "game_test.h"
#include "config_test.h"
#include "player_factory_test.h"

void run_suite() {
  board_test();
  minimax_test();
  player_test();
  presenter_test();
  game_test();
  config_test();
  player_factory_test();
}

int main() {
  run_suite();
  show_results();
  return 0;
}

