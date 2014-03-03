CFLAGS = -Wall

all: spec main

spec: test/test.c test/spec_helper.c src/board.c src/presenter.c src/minimax.c src/player.c src/game.c
	cc -I include -o spec test/test.c  test/spec_helper.c src/board.c src/presenter.c src/minimax.c src/player.c src/game.c

main: src/main.c src/board.c src/presenter.c src/minimax.c src/player.c src/game.c
	cc -I include -o main src/main.c src/board.c src/presenter.c src/minimax.c src/player.c src/game.c

clean:
	rm -f bin/*

