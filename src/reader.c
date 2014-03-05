#include <stdio.h>

#include "reader.h"

int read_int() {
  char input[3];
  int move = -1;
  fgets(input, 3, stdin);
  sscanf(input, "%d", &move);
  fpurge(stdin);
  return move - 1;
}
