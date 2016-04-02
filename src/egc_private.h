/*
** egc_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 17:43:11 2016 antoine
** Last update Wed Mar 30 17:43:11 2016 antoine
*/

#ifndef EGC_PRIVATE_H
# define EGC_PRIVATE_H

# include <stdint.h>
# include "../include/egc.h"

typedef int     t_block_flags;

# define BLOCK_FLAGS_FREE       (1)
# define BLOCK_FLAGS_MARK       (2)
# define BLOCK_FLAGS_ATOM       (4)

typedef struct  s_block
{
  t_block_flags flags;
  size_t        size;
}               t_block;

typedef struct  s_heap
{
  size_t        size;
  void          *data;
  struct s_heap *next;
}               t_heap;

void            egc_set_to_zero(void *data, size_t length);

void            egc_block_mark(t_block *block);

void            egc_block_free(t_block *block, t_heap *heap);

t_block         *egc_get_next_block(t_heap *heap, t_block *block);

t_heap          *egc_heap_new(size_t size, t_heap *next);

/*
** Returns NULL if there is no free block of the given size
*/
t_block         *egc_heap_get_free_block(t_heap *heap, size_t size);


void            egc_heap_delete(t_heap *heap);

void            egc_heap_mark(t_heap *heap);

void            egc_mark_pointer_array(void **pointer_array, size_t size);

/*
** A random number.
** You can use anything here, since it looks random and is
** 8 bytes long to fit in a uint64_t.
*/
# define MAGIC_NUMBER   (0x8bc2df231f11ecc6)

void            egc_log(const char *message);
void            egc_log_pointer(void *pointer);
void            egc_log_uint(unsigned long n);

# ifdef EGC_DEBUG
#  define LOG(message)  egc_log(message)
#  define LOG_POINTER(pointer)  egc_log_pointer(pointer)
#  define LOG_UINT(pointer)  egc_log_uint(pointer)
# else
#  define LOG(message)
#  define LOG_POINTER(pointer)
#  define LOG_UINT(pointer)
# endif

# ifdef EGC_DEBUG
#  define IF_DEBUG(e)   (e)
# else
#  define IF_DEBUG(e)
# endif

# ifdef EGC_DEBUG
#  define STATICS       (&g_egc_private_statics)
# else
#  define STATICS       (egc_get_private_statics())
# endif

typedef struct          s_statics
{
  uint64_t              magic_number;
  t_egc_error_callback  error_callback;
  void                  *user_statics;
  size_t                user_statics_size;
  t_heap                *heaps;
  void                  *stack_bottom;
  size_t                heap_size;
  size_t                malloc_count;
  size_t                free_count;
}                       t_statics;

# ifdef EGC_DEBUG
t_statics               g_egc_private_statics;
# endif

int             egc_get_heap_count(void);

void            egc_mark_stack(void);

void            egc_mark_user_statics(void);

/*
** Returns NULL if there is no free block of the given size
*/
t_block         *egc_get_free_block(t_statics *statics,
                                    t_heap **heap_pointer,
                                    size_t size);

/*
** Returns NULL if this is not a pointer to a heap
*/
t_heap          *egc_find_heap_from_pointer(t_heap *heaps, const void *p);

void            *egc_safe_malloc(size_t length);

t_statics       *egc_get_private_statics(void);

#endif /* EGC_PRIVATE_H */
