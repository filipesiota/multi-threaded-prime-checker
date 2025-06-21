CC=gcc
CFLAGS=-Iinclude

SRC=$(shell find src -name '*.c')

all: program

program: $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -o build/$@ $^

sanitize: $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -fsanitize=address -o build/program $^

clean:
	rm -R build/
