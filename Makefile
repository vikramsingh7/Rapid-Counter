CC := gcc -Wall
OPTS := -Wall -ggdb

CFLAGS=-std=c99

main:
	$(CC) $(OPTS) $(LIBS) -o final main.c -pthread -std=c99

clean:
	@rm -f repl final

.PHONY: clean wathc all
