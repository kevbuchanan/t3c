#include <assert.h>

#include "spec_helper.h"
#include "player_factory_test.h"
#include "player_factory.h"
#include "presenter.h"
#include "ttt_ai.h"

void test_build_human_player() {
  Player* player = build_player('Z', human);
  assert(player->piece == 'Z');
  assert(player->get_move == &ask_for_move);
  destroy_player(player);
}

void test_build_difficult_player() {
  Player* player = build_player('X', difficult);
  assert(player->piece == 'X');
  assert(player->get_move == &hard_move);
  destroy_player(player);
}

void test_build_medium_player() {
  Player* player = build_player('U', medium);
  assert(player->piece == 'U');
  assert(player->get_move == &medium_move);
  destroy_player(player);
}

void test_build_easy_player() {
  Player* player = build_player('W', easy);
  assert(player->piece == 'W');
  assert(player->get_move == &easy_move);
  destroy_player(player);
}

void player_factory_test() {
  test_build_human_player();
  success();
  test_build_difficult_player();
  success();
  test_build_medium_player();
  success();
  test_build_easy_player();
  success();
}
