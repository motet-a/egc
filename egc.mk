##
## egc.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar 30 18:36:20 2016 antoine
## Last update Wed Mar 30 18:36:20 2016 antoine
##

GLIST_TYPES		= char double float hs int long str uint ulong voidp

GLIST_SOURCES_NAMES	= $(foreach type,$(GLIST_TYPES), \
			glist_$(type)_0.c \
			glist_$(type)_1.c \
			glist_$(type)_2.c)

EGC_SOURCES_NAMES	= \
			block.c \
			block_fragment.c \
			char_is_alpha.c \
			char_is_whitespace.c \
			char_case.c \
			collect.c \
			debug_lock.c \
			defrag.c \
			exit.c \
			find.c \
			get_statics.c \
			heap.c \
			heaps.c \
			hs_concat.c \
			hs_equals.c \
			hs_format.c \
			hs_format_directive.c \
			hs_get.c \
			hs_index_of.c \
			hs_is_alpha.c \
			hs_join.c \
			hs_length.c \
			hs_new.c \
			hs_new_int.c \
			hs_print.c \
			hs_puts.c \
			hs_slice.c \
			hs_split.c \
			hs_starts_with.c \
			hs_strip.c \
			hs_to_str.c \
			hs_vformat.c \
			init.c \
			log.c \
			malloc.c \
			mark.c \
			mark_stack.c \
			printf.c \
			realloc.c \
			run.c \
			safe_malloc.c \
			stats.c \
			string.c \
			unmark.c

EGC_SOURCES_NAMES	+= $(GLIST_SOURCES_NAMES)

EGC_SOURCES		= $(foreach file,$(EGC_SOURCES_NAMES), \
			src/$(file))

GLIST_SOURCES		= $(foreach file,$(GLIST_SOURCES_NAMES), \
			src/$(file))

EGC_OBJECTS		= $(EGC_SOURCES:.c=.o)
