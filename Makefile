CFLAGS=-Wall

all: spec main

spec: bin/test.o bin/board.o
	cc -o spec bin/test.o bin/board.o

main: bin/main.o bin/board.o bin/presenter.o
	cc -o main bin/main.o bin/board.o bin/presenter.o

bin/test.o: test/test.c src/board.h
	cc -c -o bin/test.o test/test.c

bin/main.o: src/main.c src/board.h
	cc -c -o bin/main.o src/main.c

bin/board.o: src/board.c src/board.h
	cc -c -o bin/board.o src/board.c

bin/presenter.o: src/presenter.c src/presenter.h
	cc -c -o bin/presenter.o src/presenter.c

clean:
	rm -f bin/*

