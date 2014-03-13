#include <assert.h>

#include "spec_helper.h"
#include "config_test.h"
#include "config.h"

char* empty_argv[] = {};
char* test_argv[] = {"-s",  "4", "-p1", "hard", "-p2", "human"};

void test_size() {
  Config config = initialize_config(7, test_argv);
  assert(config.size == 4);
}

void test_p1_default_piece() {
  Config config = initialize_config(0, empty_argv);
  assert(config.p1_piece == 'X');
}

void test_p1_default_type() {
  Config config = initialize_config(0, empty_argv);
  assert(config.p1_type == human);
}

void test_p2_default_piece() {
  Config config = initialize_config(0, empty_argv);
  assert(config.p2_piece == 'O');
}

void test_p2_default_type() {
  Config config = initialize_config(0, empty_argv);
  assert(config.p2_type == hard);
}

void test_default_size() {
  Config config = initialize_config(0, empty_argv);
  assert(config.size == 3);
}

void test_checks_max() {
  char* argv[] = {"-s", "e"};
  Config config = initialize_config(2, argv);
  assert(config.size == 3);
}

void test_parse_player1() {
  Config config = initialize_config(7, test_argv);
  assert(config.p1_type == hard);
}

void test_parse_player2() {
  Config config = initialize_config(7, test_argv);
  assert(config.p2_type == human);
}

void config_test() {
  test_size();
  success();
  test_p1_default_piece();
  success();
  test_p1_default_type();
  success();
  test_p2_default_piece();
  success();
  test_p2_default_type();
  success();
  test_default_size();
  success();
  test_checks_max();
  success();
  test_parse_player1();
  success();
  test_parse_player1();
  success();
}
