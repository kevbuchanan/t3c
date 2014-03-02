#include <stdio.h>

#include "board_test.c"
#include "minimax_test.c"

void run_suite() {
  board_test();
  minimax_test();
}

int main() {
  run_suite();
  puts("");
  return 0;
}

