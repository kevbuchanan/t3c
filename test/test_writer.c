#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "writer.h"

void init_log(void) {
  writer_log = malloc(200);
}

void destroy_log(void) {
  free(writer_log);
}

void reset_log(void) {
  strcpy(writer_log, "");
}

void add_to_log(char* string) {
  strcat(writer_log, string);
}

void write(char* string) {
  add_to_log(string);
}

void writef(char* string, char sub) {
  char output[20];
  sprintf(output, string, sub);
  add_to_log(output);
}

