##
## egc.mk for  in /home/antoine
##
## Made by antoine
## Login   <antoine@epitech.net>
##
## Started on  Wed Mar 30 18:36:20 2016 antoine
## Last update Wed Mar 30 18:36:20 2016 antoine
##

EGC_SOURCES_NAMES	= \
			block.c \
			block_fragment.c \
			collect.c \
			debug_lock.c \
			defrag.c \
			exit.c \
			get_statics.c \
			glist_char.c \
			glist_double.c \
			glist_float.c \
			glist_hs.c \
			glist_int.c \
			glist_long.c \
			glist_str.c \
			glist_uint.c \
			glist_ulong.c \
			glist_voidp.c \
			heap.c \
			heaps.c \
			hs_concat.c \
			hs_equals.c \
			hs_format.c \
			hs_index_of.c \
			hs_new.c \
			hs_new_int.c \
			hs_print.c \
			hs_puts.c \
			hs_slice.c \
			hs_split.c \
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
			string.c

EGC_SOURCES		= $(foreach file,$(EGC_SOURCES_NAMES), \
			src/$(file))

EGC_OBJECTS		= $(EGC_SOURCES:.c=.o)
