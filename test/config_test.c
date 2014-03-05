#include <assert.h>

#include "spec_helper.h"
#include "config_test.h"
#include "config.h"

char* test_argv[] = {"-d", "3", "-s",  "4"};

void test_size() {
  char* argv[] = {"-s", "5"};
  Config config = initialize_config(2, argv);
  assert(config.size == 5);
}

void test_difficulty() {
  Config config = initialize_config(6, test_argv);
  assert(config.difficulty == 3);
}

void test_p1_piece() {
  Config config = initialize_config(6, test_argv);
  assert(config.p1_piece == 'X');
}

void test_p1_type() {
  Config config = initialize_config(6, test_argv);
  assert(config.p1_type == human);
}

void test_p2_piece() {
  Config config = initialize_config(6, test_argv);
  assert(config.p2_piece == 'O');
}

void test_p2_type() {
  Config config = initialize_config(6, test_argv);
  assert(config.p2_type == medium);
}

void test_defaults() {
  char* argv[] = {};
  Config config = initialize_config(0, argv);
  assert(config.difficulty == 2);
  assert(config.size == 3);
}

void test_checks_max() {
  char* argv[] = {"-s", "12"};
  Config config = initialize_config(0, argv);
  assert(config.size == 3);
}

void config_test() {
  test_size();
  success();
  test_difficulty();
  success();
  test_p1_piece();
  success();
  test_p1_type();
  success();
  test_p2_piece();
  success();
  test_p2_type();
  success();
  test_defaults();
  success();
  test_checks_max();
  success();
}
