#include <stdio.h>

#include "writer.h"

void write(char* string) {
  printf(string, "");
}

void write_char(char* string, char sub) {
  printf(string, sub);
}
