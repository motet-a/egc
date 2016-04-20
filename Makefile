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

CFLAGS		= -W -Wall -Wextra \
		-Wmissing-prototypes \
		-Wmissing-declarations \
		-std=c89 -g -I./include/

ifneq ($(or					\
	$(findstring rtest,$(MAKECMDGOALS)),	\
	$(findstring vgtest,$(MAKECMDGOALS))),)
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

TEST_SOURCES	= \
		test/glist.c \
		test/hs_get.c \
		test/hs_format.c \
		test/hs_index_of.c \
		test/hs_slice.c \
		test/hs_split.c \
		test/hs_starts_with.c \
		test/malloc.c \
		test/set_to_zero.c \
		test/statics.c \
		test/test.c \
		test/utils.c

TEST_OBJECTS	= $(TEST_SOURCES:.c=.o)

all: libegc.a

$(GLIST_SOURCES):
	./glist_gen.py

libegc.a: src/glist_char_0.c $(EGC_OBJECTS)
	ar rc $@ $(EGC_OBJECTS)
	ranlib $@

test: src/glist_char_0.c test/test

test/test: $(TEST_OBJECTS) libegc.a
	$(CC) -o $@ $^ $(LDFLAGS)

rtest: test
	./test/test

vgtest: test
	valgrind --suppressions=valgrind.supp ./test/test

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

.PHONY: all test rtest vgtest clean fclean re example delivery glist_clean
