#include <string.h>

#include "config.h"

#define SIZE_FLAG "-s"
#define DEFAULT_SIZE 3
#define ORDER_FLAG "-o"
#define DEFAULT_ORDER 1
#define DIFF_FLAG "-d"
#define DEFAULT_DIFF 2

int find_flag(int argc, char* argv[], char* flag) {
  int i = -1;
  for(int j = 0; j < argc; j++) {
    if (strcmp(flag, argv[j]) == 0) return j;
  }
  return i;
}

int make_int(char* input) {
  return (int)input[0] - '0';
}

int parse_arg(int argc, char* argv[], char* flag, int fdefault) {
  int i = find_flag(argc, argv, flag);
  if(i != -1) {
    return make_int(argv[i + 1]);
  } else {
    return fdefault;
  }
}

int parse_difficulty(int argc, char* argv[]) {
  return parse_arg(argc, argv, DIFF_FLAG, DEFAULT_DIFF);
}

int parse_order(int argc, char* argv[]) {
  return parse_arg(argc, argv, ORDER_FLAG, DEFAULT_ORDER);
}

int parse_size(int argc, char* argv[]) {
  return parse_arg(argc, argv, SIZE_FLAG, DEFAULT_SIZE);
}

Config initialize_config(int argc, char* argv[]) {
  Config config;
  config.size = parse_size(argc, argv);
  config.difficulty = parse_difficulty(argc, argv);
  config.p1_piece = 'X';
  config.p1_type = human;
  config.p2_piece = 'O';
  config.p2_type = computer;
  return config;
}
