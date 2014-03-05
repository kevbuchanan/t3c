#include <string.h>
#include <stdio.h>

#include "config.h"

#define SIZE_FLAG "-s"
#define DEFAULT_SIZE 3
#define MAX_SIZE 9

#define DIFF_FLAG "-d"
#define DEFAULT_DIFF 2
#define MAX_DIFF 3

int find_flag(int argc, char* argv[], char* flag) {
  for(int j = 0; j < argc; j++) {
    if (strcmp(flag, argv[j]) == 0) return j;
  }
  return -1;
}

int make_int(char* input) {
  return (int)input[0] - '0';
}

int parse_arg(int argc, char* argv[], char* flag, int fdefault, int max) {
  int i = find_flag(argc, argv, flag);
  if (argc - 1 >= i + 1) {
    int iarg = make_int(argv[i + 1]);
    if(i != -1 && iarg <= max) {
      return iarg;
    }
  }
  return fdefault;
}

int parse_difficulty(int argc, char* argv[]) {
  return parse_arg(argc, argv, DIFF_FLAG, DEFAULT_DIFF, MAX_DIFF);
}

int parse_size(int argc, char* argv[]) {
  return parse_arg(argc, argv, SIZE_FLAG, DEFAULT_SIZE, MAX_SIZE);
}

Config initialize_config(int argc, char* argv[]) {
  Config config;
  config.size = parse_size(argc, argv);
  config.difficulty = parse_difficulty(argc, argv);
  config.p1_piece = 'X';
  config.p1_type = human;
  config.p2_piece = 'O';
  config.p2_type = medium;
  return config;
}
