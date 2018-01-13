ifdef COMSPEC
 MV ?= move
 RM ?= del
else
 MV ?= mv -f
 RM ?= rm -f
endif

CC=gcc
CFLAGS = -g -O2 -Wall -Werror `pkg-config --cflags MLV`

LDFLAGS=`pkg-config --libs MLV`
CFLAGS=-W -Wall -ansi 
EXEC=jeu
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

jeu: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

main.o: functions.h structures.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)  $(LDFLAGS)

.PHONY: clean mrproper

clean:
	@$(RM) *.o

mrproper: clean
	@$(RM) $(EXEC)