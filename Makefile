CFLAGS = -Wall

all: spec main

spec: bin/test.o bin/spec_helper.o bin/board.o bin/presenter.o bin/minimax.o
	cc -o spec bin/test.o bin/board.o bin/minimax.o bin/spec_helper.o bin/presenter.o

main: bin/main.o bin/board.o bin/presenter.o bin/minimax.o
	cc -o main bin/main.o bin/board.o bin/presenter.o

bin/test.o: test/test.c include/board.h
	cc -I include -c -o bin/test.o test/test.c

bin/main.o: src/main.c include/board.h
	cc -I include -c -o bin/main.o src/main.c

bin/board.o: src/board.c include/board.h
	cc -I include -c -o bin/board.o src/board.c

bin/presenter.o: src/presenter.c include/presenter.h
	cc -I include -c -o bin/presenter.o src/presenter.c

bin/minimax.o: src/minimax.c include/minimax.h include/board.h
	cc -I include -c -o bin/minimax.o src/minimax.c

bin/spec_helper.o: test/spec_helper.c include/spec_helper.h include/board.h
	cc -I include -c -o bin/spec_helper.o test/spec_helper.c

clean:
	rm -f bin/*

