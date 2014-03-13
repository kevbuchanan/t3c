# Tic Tac Toe in C [![Build Status](https://travis-ci.org/kevinbuch/t3c.png?branch=master)](https://travis-ci.org/kevinbuch/t3c)

##Make

```bash
$ make
```

## Test

```bash
$ ./spec
```

## Play

```bash
$ ./main
```

Default is human(X) vs hard difficulty(O) on 3x3 board

### Options
Size: ```-s <size 1 to 9>```

Player 1: ```-p1 <human hard medium easy>```

Player 2: ```-p2 <human hard medium easy>```

Example:

```bash
$ ./main -s 6 -p1 easy -p2 human
```

### Difficulties

Easy: Makes random moves

Medium: Will win if possible, but is beatable

Hard: Unbeatable on 3x3 board

## Debug Memory Leaks

```bash
$ valgrind --tool=memcheck --dsymutil=yes --leak-check=full ./spec
```
