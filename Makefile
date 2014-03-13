CC = gcc
CFLAGS = -Wall -std=c99
INCLUDE = -I include/test -I include/src -c
OUT = bin/src bin/test bin/test/mock
CORE = src/board.c src/presenter.c src/ttt_ai.c src/player.c src/reader.c src/game.c src/config.c src/player_factory.c
MOCKED = src/writer.c src/messages.c src/main.c
TESTS = $(wildcard test/*.c) $(wildcard test/mock/*.c)
TEST_OBJECTS = $(TESTS:.c=.o)
MAIN_OBJECTS = $(CORE:.c=.o)
MOCKED_OBJECTS = $(MOCKED:.c=.o)

all: make_dirs spec main

spec: $(TEST_OBJECTS) $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) -o spec $(addprefix bin/, $(TEST_OBJECTS) $(MAIN_OBJECTS))

main: $(MAIN_OBJECTS) $(MOCKED_OBJECTS)
	$(CC) $(CFLAGS) -o main $(addprefix bin/, $(MAIN_OBJECTS) $(MOCKED_OBJECTS))

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o bin/$@ $<

.PHONY: make_dirs
make_dirs: $(OUT)

$(OUT):
	mkdir -p $@

clean:
	rm -rf bin

