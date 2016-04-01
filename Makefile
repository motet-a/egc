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

CFLAGS		= -W -Wall -Wextra -std=c89
CFLAGS		+= -g

ifeq ($(DEBUG),true)
	CFLAGS	+= -D EGC_DEBUG
endif

LDFLAGS		=

TEST_SOURCES	= test/main.c test/test.c
TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)

all: test

libegc.a: $(EGC_OBJECTS)
	ar rc $@ $^
	ranlib $@

test: test/test

test/test: $(TEST_OBJECTS) libegc.a
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(TEST_OBJECTS)
	$(RM) $(EGC_OBJECTS)

fclean: clean
	$(RM) libegc.a
	$(RM) test/test

re: fclean all

.PHONY: all test clean fclean re
