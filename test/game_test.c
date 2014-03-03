#include <assert.h>
#include <string.h>

#include "spec_helper.h"
#include "game_test.h"
#include "game.h"
#include "board.h"
#include "writer.h"
#include "player.h"

void test_shows_draw() {
  Board* board = draw_board();
  Player* p1 = create_player('X', &fake_move);
  Player* p2 = create_player('O', &fake_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  char expected[] = "\nX O X \nO X O \nO X O \n\nDraw\n";
  assert(strcmp(writer_log, expected) == 0);
}

void test_shows_win() {
  Board* board = draw_board();
  unset_move(board, 0);
  Player* p1 = create_player('O', &fake_move);
  Player* p2 = create_player('X', &fake_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  char expected[] = "\n- O X \nO X O \nO X O \n"
                    "\nPlayer 1's turn\n"
                    "\nO O X \nO X O \nO X O \n"
                    "\nWin\n";
  assert(strcmp(writer_log, expected) == 0);
}

void test_gets_valid_move() {
  Board* board = draw_board();
  unset_move(board, 1);
  Player* p1 = create_player('X', &incrementing_move);
  Player* p2 = create_player('O', &fake_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  current_move = 0;
  char expected[] = "\nX - X \nO X O \nO X O \n"
                    "\nPlayer 1's turn\n"
                    "\nX - X \nO X O \nO X O \n"
                    "\nPlayer 1's turn\n"
                    "\nX X X \nO X O \nO X O \n"
                    "\nWin\n";
  assert(strcmp(writer_log, expected) == 0);
}

void test_switches_turns() {
  Board* board = draw_board();
  unset_move(board, 0);
  unset_move(board, 1);
  Player* p1 = create_player('X', &incrementing_move);
  Player* p2 = create_player('O', &incrementing_move);
  start_game(board, p1, p2);
  destroy_board(board);
  destroy_player(p1);
  destroy_player(p2);
  current_move = 0;
  char expected[] = "\n- - X \nO X O \nO X O \n"
                    "\nPlayer 1's turn\n"
                    "\nX - X \nO X O \nO X O \n"
                    "\nPlayer 2's turn\n"
                    "\nX O X \nO X O \nO X O \n"
                    "\nDraw\n";
  assert(strcmp(writer_log, expected) == 0);
}

void game_test() {
  init_log();

  test_shows_draw();
  reset_log();
  success();

  test_shows_win();
  reset_log();
  success();

  test_gets_valid_move();
  reset_log();
  success();

  test_switches_turns();
  reset_log();
  success();

  destroy_log();
}
