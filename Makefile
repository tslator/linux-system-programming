CC=gcc
CFLAGS=-Wall -Wextra -g

SRCS=$(wildcard src/*.c)
OUT=bin/app

all: $(OUT)

$(OUT): $(SRCS) | bin
	@$(CC) $(CFLAGS) -o $(OUT) $(SRCS)

bin:
	@mkdir -p bin

clean:
	@rm -rf bin

run: all
	@./bin/app
