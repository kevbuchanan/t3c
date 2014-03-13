#include <stdio.h>
#include <string.h>

#include "reader.h"

void flush() {
  int c = 1;
  while (c != '\n' && c != EOF) {
    c = getchar();
  }
}

int read_int() {
  char input[4];
  int move = -1;
  fgets(input, 4, stdin);
  if (strchr(input, '\n') == NULL) {
    flush();
  } else {
    sscanf(input, "%d", &move);
  }
  return move - 1;
}
