#include <assert.h>

#include "spec_helper.h"
#include "config_test.h"
#include "config.h"

void test_size() {
  char* argv[] = {"-s", "5"};
  Config config = initialize_config(2, argv);
  assert(config.size == 5);
}

void test_order() {
  char* argv[] = {"-o", "2", "-s",  "4"};
  Config config = initialize_config(4, argv);
  assert(config.order == 2);
}

void test_difficulty() {
  char* argv[] = {"-o", "2", "-d", "3", "-s",  "4"};
  Config config = initialize_config(6, argv);
  assert(config.difficulty == 3);
}

void test_defaults() {
  char* argv[] = {};
  Config config = initialize_config(0, argv);
  assert(config.difficulty == 2);
  assert(config.size == 3);
  assert(config.order == 1);
}

void config_test() {
  test_size();
  success();
  test_order();
  success();
  test_difficulty();
  success();
  test_defaults();
  success();
}
