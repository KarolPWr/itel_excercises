BIN=sigint sigusr memtest

CC=gcc
CCOPTS=-Wall -Wextra -g

.PHONY: all clean pristine

all: $(BIN)

clean:
	rm -f $(BIN)

pristine: clean

%: %.c
	$(CC) $(CCOPTS) -o $@ $<

