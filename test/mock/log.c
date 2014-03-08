#include <stdlib.h>
#include <string.h>

#include "log.h"

char* writer_log;

void init_log(void) {
  writer_log = malloc(200);
  for (int i = 0; i < 200; writer_log[i++] = '\0');
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
