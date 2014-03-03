#include "board.h"
#include "presenter.h"

int main() {
  char* board = new_board();
  show_board(board);
  destroy_board(board);
  return 0;
}
