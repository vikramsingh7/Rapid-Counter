CC := gcc -Wall
OPTS := -Wall -ggdb



main:
	$(CC) $(OPTS) $(LIBS) -o final main.c -pthread

clean:
	@rm -f repl final

.PHONY: clean wathc all
