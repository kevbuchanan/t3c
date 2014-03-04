CFLAGS = -Wall

all: spec main

spec: bin/test.o bin/spec_helper.o bin/board.o bin/board_test.o bin/presenter.o bin/presenter_test.o bin/minimax.o bin/minimax_test.o bin/player.o bin/player_test.o bin/test_writer.o bin/log.o bin/game.o bin/game_test.o
	cc -o spec bin/test.o bin/spec_helper.o bin/board.o bin/board_test.o bin/presenter.o bin/presenter_test.o bin/minimax.o bin/minimax_test.o bin/player.o bin/player_test.o bin/test_writer.o bin/log.o bin/game.o bin/game_test.o

main: bin/main.o bin/board.o bin/presenter.o bin/minimax.o bin/player.o bin/writer.o bin/game.o
	cc -o main bin/main.o bin/board.o bin/presenter.o bin/minimax.o bin/player.o bin/writer.o bin/game.o

bin/test.o: test/test.c
	cc -I include/test -I include/src -c -o bin/test.o test/test.c

bin/spec_helper.o: test/spec_helper.c
	cc -I include/test -I include/src -c -o bin/spec_helper.o test/spec_helper.c

bin/main.o: src/main.c
	cc -I include/test -I include/src -c -o bin/main.o src/main.c

bin/board.o: src/board.c
	cc -I include/test -I include/src -c -o bin/board.o src/board.c

bin/board_test.o: test/board_test.c
	cc -I include/test -I include/src -c -o bin/board_test.o test/board_test.c

bin/presenter.o: src/presenter.c
	cc -I include/test -I include/src -c -o bin/presenter.o src/presenter.c

bin/presenter_test.o: test/presenter_test.c
	cc -I include/test -I include/src -c -o bin/presenter_test.o test/presenter_test.c

bin/minimax.o: src/minimax.c
	cc -I include/test -I include/src -c -o bin/minimax.o src/minimax.c

bin/minimax_test.o: test/minimax_test.c
	cc -I include/test -I include/src -c -o bin/minimax_test.o test/minimax_test.c

bin/player.o: src/player.c
	cc -I include/test -I include/src -c -o bin/player.o src/player.c

bin/player_test.o: test/player_test.c
	cc -I include/test -I include/src -c -o bin/player_test.o test/player_test.c

bin/writer.o: src/writer.c
	cc -I include/test -I include/src -c -o bin/writer.o src/writer.c

bin/test_writer.o: test/test_writer.c
	cc -I include/test -I include/src -c -o bin/test_writer.o test/test_writer.c

bin/log.o: test/log.c
	cc -I include/test -I include/src -c -o bin/log.o test/log.c

bin/game.o: src/game.c
	cc -I include/test -I include/src -c -o bin/game.o src/game.c

bin/game_test.o: test/game_test.c
	cc -I include/test -I include/src -c -o bin/game_test.o test/game_test.c

clean:
	rm -f bin/*

