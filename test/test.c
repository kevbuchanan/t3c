#include "spec_helper.h"

#include "board_test.c"
#include "minimax_test.c"
#include "player_test.c"
#include "presenter_test.c"

void run_suite() {
  board_test();
  minimax_test();
  player_test();
  presenter_test();
}

int main() {
  run_suite();
  show_results();
  return 0;
}

