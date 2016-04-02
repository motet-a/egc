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
			collect.c \
			exit.c \
			get_statics.c \
			heap.c \
			hs_concat.c \
			hs_format.c \
			hs_new.c \
			hs_new_int.c \
			hs_print.c \
			hs_vformat.c \
			log.c \
			malloc.c \
			mark.c \
			mark_stack.c \
			printf.c \
			safe_malloc.c \
			start.c \
			string.c

EGC_SOURCES		= $(foreach file,$(EGC_SOURCES_NAMES), \
			src/$(file))

EGC_OBJECTS		= $(EGC_SOURCES:.c=.o)
