CFLAGS = -Wall

all: spec main

spec: bin/test.o bin/spec_helper.o bin/board.o bin/board_test.o bin/presenter.o bin/presenter_test.o bin/ttt_ai.o bin/ttt_ai_test.o \
			bin/player.o bin/player_test.o bin/test_writer.o bin/reader.o bin/log.o bin/game.o bin/game_test.o bin/config.o bin/config_test.o \
			bin/player_factory.o bin/player_factory_test.o
	cc -o spec bin/test.o bin/spec_helper.o bin/board.o bin/board_test.o bin/presenter.o bin/presenter_test.o bin/ttt_ai.o \
				bin/ttt_ai_test.o bin/player.o bin/player_test.o bin/test_writer.o bin/reader.o bin/log.o bin/game.o bin/game_test.o \
				bin/config.o bin/config_test.o bin/player_factory.o bin/player_factory_test.o

main: bin/main.o bin/board.o bin/presenter.o bin/ttt_ai.o bin/player.o bin/writer.o bin/reader.o bin/game.o \
			bin/config.o bin/player_factory.o
	cc -o main bin/main.o bin/board.o bin/presenter.o bin/ttt_ai.o bin/player.o bin/writer.o bin/reader.o bin/game.o \
				bin/config.o bin/player_factory.o

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

bin/ttt_ai.o: src/ttt_ai.c
	cc -I include/test -I include/src -c -o bin/ttt_ai.o src/ttt_ai.c

bin/ttt_ai_test.o: test/ttt_ai_test.c
	cc -I include/test -I include/src -c -o bin/ttt_ai_test.o test/ttt_ai_test.c

bin/player.o: src/player.c
	cc -I include/test -I include/src -c -o bin/player.o src/player.c

bin/player_test.o: test/player_test.c
	cc -I include/test -I include/src -c -o bin/player_test.o test/player_test.c

bin/writer.o: src/writer.c
	cc -I include/test -I include/src -c -o bin/writer.o src/writer.c

bin/reader.o: src/reader.c
	cc -I include/test -I include/src -c -o bin/reader.o src/reader.c

bin/test_writer.o: test/test_writer.c
	cc -I include/test -I include/src -c -o bin/test_writer.o test/test_writer.c

bin/config.o: src/config.c
	cc -I include/test -I include/src -c -o bin/config.o src/config.c

bin/config_test.o: test/config_test.c
	cc -I include/test -I include/src -c -o bin/config_test.o test/config_test.c

bin/log.o: test/log.c
	cc -I include/test -I include/src -c -o bin/log.o test/log.c

bin/game.o: src/game.c
	cc -I include/test -I include/src -c -o bin/game.o src/game.c

bin/game_test.o: test/game_test.c
	cc -I include/test -I include/src -c -o bin/game_test.o test/game_test.c

bin/player_factory.o: src/player_factory.c
	cc -I include/test -I include/src -c -o bin/player_factory.o src/player_factory.c

bin/player_factory_test.o: test/player_factory_test.c
	cc -I include/test -I include/src -c -o bin/player_factory_test.o test/player_factory_test.c

clean:
	rm -f bin/*

