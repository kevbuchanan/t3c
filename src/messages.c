#include "messages.h"

char* turn_message = "\n\x1B[0mPlayer %d's turn\n";

char* draw_message = "\n\x1B[0mDraw\n";

char* win_message = "\n\x1B[0m%c wins!\n";

char* invalid_move_message = "\n\x1B[0mInvalid move\n";

char* ask_for_move_message = "\n\x1B[0mEnter your move:\n";

char* empty_space_message = "  \x1B[36m%-3d";

char* taken_space_message = "  \x1B[33m%-3c";

char* reset_screen_message = "\e[1;1H\e[2J\n";

char* end_board_message = "\n";

char* cell_transition_message = "\x1B[0m|";

char* row_transition_start = "\x1B[0m\n";

char* row_transition_piece = "-----+";

char* row_transition_end = "-----\n";

