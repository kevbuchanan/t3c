#include <string.h>
#include <stdbool.h>

#include "config.h"

#define SIZE_FLAG "-s"
#define DEFAULT_SIZE 3
#define MAX_SIZE 9

#define P1_FLAG "-p1"
#define P2_FLAG "-p2"

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

int parse_size(int argc, char* argv[]) {
  return parse_arg(argc, argv, SIZE_FLAG, DEFAULT_SIZE, MAX_SIZE);
}

bool is_match(char* arg, char* type) {
  return strcmp(arg, type) == 0;
}

PlayerType parse_player_type(int argc, char* argv[], char* flag, PlayerType fdefault) {
  int i = find_flag(argc, argv, flag);
  if (argc - 1 >= i + 1) {
    char* arg = argv[i + 1];
    if (is_match(arg, "human")) return human;
    if (is_match(arg, "hard")) return hard;
    if (is_match(arg, "medium")) return medium;
    if (is_match(arg, "easy")) return easy;
  }
  return fdefault;
}

Config initialize_config(int argc, char* argv[]) {
  Config config;
  config.size = parse_size(argc, argv);
  config.p1_piece = 'X';
  config.p1_type = parse_player_type(argc, argv, P1_FLAG, human);
  config.p2_piece = 'O';
  config.p2_type = parse_player_type(argc, argv, P2_FLAG, hard);
  return config;
}
