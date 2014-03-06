CFLAGS = -Wall
INCLUDE = -I include/test -I include/src -c
CORE = src/board.c src/presenter.c src/ttt_ai.c src/player.c src/reader.c src/game.c src/config.c src/player_factory.c
MOCKED = src/writer.c src/messages.c src/main.c
TESTS = $(wildcard test/*.c)
TEST_OBJECTS = $(TESTS:.c=.o)
MAIN_OBJECTS = $(CORE:.c=.o)
MOCKED_OBJECTS = $(MOCKED:.c=.o)

all: spec main

spec: $(TEST_OBJECTS) $(MAIN_OBJECTS)
	cc -o spec $(addprefix bin/, $(TEST_OBJECTS) $(MAIN_OBJECTS))

main: $(MAIN_OBJECTS) $(MOCKED_OBJECTS)
	cc -o main $(addprefix bin/, $(MAIN_OBJECTS) $(MOCKED_OBJECTS))

%.o: %.c
	cc $(INCLUDE) -o bin/$@ $<

clean:
	rm -f bin/src/*
	rm -f bin/test/*

