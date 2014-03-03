#ifndef SPEC_HELPER_H
#define SPEC_HELPER_H

void success(void);
void show_results(void);
int current_move;
int fake_move(char* board, char piece, char other_piece);
int incrementing_move(char* board, char piece, char other_piece);
char* draw_board(void);

#endif
