#include <stdio.h>

#include "writer.h"
#include "log.h"

void write_out(char* string) {
  add_to_log(string);
}

void write_outf(char* string, char sub) {
  char output[20];
  sprintf(output, string, sub);
  add_to_log(output);
}

void pause_writer(int time) {}

