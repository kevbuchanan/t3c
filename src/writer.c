#include <stdio.h>
#include <unistd.h>

#include "writer.h"

void write_out(char* string) {
  printf(string, "");
}

void write_outf(char* string, char sub) {
  printf(string, sub);
}

void write_char_out(char* string, char sub) {
  printf(string, sub);
}

void pause_writer(int time) {
  sleep(time);
}
