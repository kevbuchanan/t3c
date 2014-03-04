#include <stdio.h>

#include "writer.h"

void write(char* string) {
  printf(string, "");
}

void writef(char* string, char sub) {
  printf(string, sub);
}

void write_char(char* string, char sub) {
  printf(string, sub);
}
