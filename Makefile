##
## Makefile for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar 30 17:32:15 2016 antoine
## Last update Wed Mar 30 17:32:15 2016 antoine
##

include egc.mk

CFLAGS		= -W -Wall -Wextra -std=c89 -I./include/

ifneq ($(findstring test,$(MAKECMDGOALS)),)
	DEBUG	= true
endif

ifdef LOG
	DEBUG	= true
endif

ifdef DEBUG
	CFLAGS	+= -g
	CFLAGS	+= -D EGC_DEBUG
endif

ifdef LOG
	CFLAGS	+= -D EGC_LOG
endif

LDFLAGS		=

TEST_SOURCES	= test/test.c test/utils.c test/malloc.c
TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)

all: test

glist: src/glist_%.c

src/glist_%.c:
	./glist_gen.py

libegc.a: glist $(EGC_OBJECTS)
	ar rc $@ $(EGC_OBJECTS)
	ranlib $@

test: glist test/test

test/test: $(TEST_OBJECTS) libegc.a
	$(CC) -o $@ $^ $(LDFLAGS)

example: example.o libegc.a
	$(CC) -o $@ $^ $(LDFLAGS)

delivery: src/glist_char.c
	$(RM) glist_gen.py
	$(RM) .gitignore
	$(RM) valgrind.supp

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

glist_clean:
	$(RM) src/glist_*.c
	$(RM) include/glist_*.h

clean:
	$(RM) $(TEST_OBJECTS)
	$(RM) $(EGC_OBJECTS)

fclean: clean
	$(RM) libegc.a
	$(RM) test/test

re: fclean all

.PHONY: all test clean fclean re
