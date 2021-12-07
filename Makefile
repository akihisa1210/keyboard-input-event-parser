CC = gcc
CFLAGS = -g -Wall

main: main.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf main
