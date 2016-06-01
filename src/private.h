/*
** egc_private.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 17:43:11 2016 antoine
** Last update Wed Mar 30 17:43:11 2016 antoine
*/

#ifndef PRIVATE_H_
# define PRIVATE_H_

# include <stdint.h>
# include "../include/egc.h"

typedef int     t_block_flags;

# define BLOCK_FLAGS_FREE       (1)
# define BLOCK_FLAGS_MARK       (2)
# define BLOCK_FLAGS_ATOM       (4)
# define BLOCK_FLAGS_DEBUG_LOCK (8)

# define AVT__(a, m)            AVT_(a, m)

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

/*
** Sets the first `n` bytes pointed to by data with zeros.
*/
void    egc_set_to_zero_(void *data, size_t n);

# define USE_MEMSET

# ifdef USE_MEMSET

#  include <string.h>
#  define SET_TO_ZERO(data, n)  memset(data, 0, n)
# else
#  define SET_TO_ZERO(data, n)  egc_set_to_zero_(data, n)
# endif /* !USE_MEMSET */

void    egc_mark_pointer_array(void **pointer_array, size_t size);

void    egc_block_free(t_block *block, t_heap *heap);

t_block *egc_get_next_block(t_heap *heap, t_block *block);

/*
** Creates a new heap of the given size
*/
t_heap  *egc_heap_new(size_t size, t_heap *next);

/*
** Calls egc_heap_new()
*/
void    egc_heap_add(size_t min_block_size);

/*
** Returns NULL if there is no free block of the given size
*/
t_block *egc_heap_get_free_block(t_heap *heap, size_t size);

void    egc_heap_delete(t_heap *heap);

/*
** Random numbers.
** You can use anything here, since it looks random and is
** 8 bytes long to fit in a uint64_t.
*/
# define MAGIC_NUMBER_0 (0x8bc2df231f11ecc6)
# define MAGIC_NUMBER_1 (0xc8e65651af5414fc)

void            egc_log(const char *message);
void            egc_log_pointer(void *pointer);
void            egc_log_uint(unsigned long n);

# define EGC_VT                 __volatile__

# ifdef EGC_LOG
#  define LOG(message)          egc_log(message)
#  define LOG_POINTER(pointer)  egc_log_pointer(pointer)
#  define LOG_UINT(pointer)     egc_log_uint(pointer)
# else
#  define LOG(message)
#  define LOG_POINTER(pointer)
#  define LOG_UINT(pointer)
# endif /* !EGC_LOG */

# ifdef EGC_DEBUG
#  define STATICS       (&g_egc_private_statics)
# else
#  define STATICS       (egc_get_private_statics())
# endif /* !EGC_DEBUG */

# ifdef EGC_DEBUG
#  define EGC_IF_DEBUG(x)       (x)
#  define EGC_IF_NOT_DEBUG(x)
# else
#  define EGC_IF_DEBUG(x)
#  define EGC_IF_NOT_DEBUG(x)   (x)
# endif /* !EGC_DEBUG */

/*
** One magic number is not sufficient.
** We need two magic numbers, and for safety purposes,
** they are not adjacent.
*/
typedef struct          s_statics
{
  uint64_t              magic_number_0;
  t_egc_error_callback  error_callback;
  void                  *user_statics;
  size_t                user_statics_size;
  t_heap                *heaps;
  void                  *stack_bottom;
  size_t                heap_size;
  size_t                total_malloc_count;
  size_t                total_free_count;
  size_t                malloc_count;
  size_t                free_count;
  size_t                collection_count;
  uint64_t              magic_number_1;
}                       t_statics;

# ifdef EGC_DEBUG
extern t_statics        g_egc_private_statics;
# endif /* !EGC_DEBUG */

# define AVT_(a, b)     __##a##s##b##__ EGC_VT

void            egc_init(t_statics *statics);
void            egc_stop(void);

void            egc_block_fragment(t_block *block,
                                   t_heap *heap,
                                   size_t min_size);

void            egc_block_request_fragmentation(t_block *block,
                                                t_heap *heap,
                                                size_t size);

t_block         *egc_defrag_block(t_heap *heap, t_block *block, int clr_left);
void            egc_defrag(void);

t_block         *egc_malloc_block(size_t size, t_statics *statics);

void            egc_debug_lock_on(void *pointer);
void            egc_debug_lock_off(void *pointer);

/*
** Aborts the program execution
*/
void            egc_abort(void);

t_block         *egc_get_last_free_block(t_heap *heap, t_block *block);

t_block         *egc_find_pointed_to_block(t_statics *statics, void *pointer);
t_heap          *egc_find_pointed_to_heap(const t_statics *statics,
                                          void *pointer);

int             egc_get_heap_count(void);

void            egc_unmark(void);

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

/*
** Don't use this function directly. Use egc_collect() instead.
*/
void            egc_collect_impl(void);

# define AVT    AVT__(a, m)

#endif /* !PRIVATE_H_ */
