CC=gcc
CFLAGS=-Wall -Wextra -g

SRC=src/main.c
OUT=bin/app

all: $(OUT)

$(OUT): $(SRC) | bin
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

bin:
	mkdir -p bin

clean:
	rm -rf bin

run: all
	./bin/app
