CFLAGS = -Wall

all: spec main

spec: bin/test.o bin/spec_helper.o bin/board.o bin/presenter.o bin/minimax.o bin/player.o
	cc -o spec bin/test.o bin/spec_helper.o bin/board.o bin/presenter.o bin/minimax.o bin/player.o

main: bin/main.o bin/board.o bin/presenter.o bin/minimax.o bin/player.o
	cc -o main bin/main.o bin/board.o bin/presenter.o bin/minimax.o bin/player.o

bin/test.o: test/test.c
	cc -I include -c -o bin/test.o test/test.c

bin/main.o: src/main.c
	cc -I include -c -o bin/main.o src/main.c

bin/board.o: src/board.c
	cc -I include -c -o bin/board.o src/board.c

bin/presenter.o: src/presenter.c
	cc -I include -c -o bin/presenter.o src/presenter.c

bin/minimax.o: src/minimax.c
	cc -I include -c -o bin/minimax.o src/minimax.c

bin/player.o: src/player.c
	cc -I include -c -o bin/player.o src/player.c

bin/spec_helper.o: test/spec_helper.c
	cc -I include -c -o bin/spec_helper.o test/spec_helper.c

clean:
	rm -f bin/*

