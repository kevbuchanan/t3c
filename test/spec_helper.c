#include <stdio.h>

void success() {
  char* success = "\x1B[32m.";
  printf("%s", success);
}
