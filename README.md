# Tic Tac Toe in C

##Make

```bash
$ make
```

## Test

```bash
$ ./spec
```

## Run

```bash
$ ./main
```

Default is human(X) vs medium difficulty(O) on 3x3 board

## Options
Size: ```-s <size 1 to 9>```

Player 1: ```-p1 <human hard medium easy>```

Player 2: ```-p2 <human hard medium easy>```

## Debug Memory Leaks

```bash
$ valgrind --tool=memcheck --dsymutil=yes --leak-check=full ./spec
```
