CC=gcc
CFLAGS=-Wall -Wextra -g

SRC=src/main.c
OUT=bin/app

all: $(OUT)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -rf bin

run: all
	./bin/app
