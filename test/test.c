#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

#include "board_test.c"

void run_suite() {
  board_test();
}

int main() {
  run_suite();
  puts("");
  return 0;
}

