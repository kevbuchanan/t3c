#include <stdio.h>

#include "writer.h"
#include "log.h"

void write(char* string) {
  add_to_log(string);
}

void writef(char* string, char sub) {
  char output[20];
  sprintf(output, string, sub);
  add_to_log(output);
}

