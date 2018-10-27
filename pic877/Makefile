SRC=sine.c

CC=sdcc
FAMILY=pic14
PROC=16f877a

ALL: $(SRC:.c=.hex)

$(SRC:.c=.hex): $(SRC)
	$(CC) --use-non-free -m$(FAMILY) -p$(PROC) $^

clean:
	rm -f $(SRC:.c=.asm) $(SRC:.c=.cod) $(SRC:.c=.hex) $(SRC:.c=.lst) $(SRC:.c=.o)

.PHONY: all clean

PROG:
	sudo ./pk2cmd -PPIC16F877A -F$(SRC:.c=.hex) -M	
