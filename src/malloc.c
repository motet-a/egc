/*
** malloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:42:56 2016 antoine
** Last update Wed Mar 30 18:42:56 2016 antoine
*/

#include "private.h"

/*
** TODO:
*/
static void     request_collection(t_statics *statics)
{
  if (statics->malloc_count > 2 * statics->free_count + 10)
    {
      egc_collect();
      statics->malloc_count = 0;
      statics->free_count = 0;
    }
}

static t_block  *malloc_block_impl(size_t size, t_statics *statics)
{
  t_block       *block;
  t_heap        *heap;

  block = egc_get_free_block(statics, &heap, size);
  if (!block)
    {
      egc_collect();
      egc_heap_add(size);
      block = egc_get_free_block(statics, &heap, size);
      if (!block)
        egc_abort();
    }
  egc_block_request_fragmentation(block, heap, size);
  block->flags &= ~BLOCK_FLAGS_FREE;
  SET_TO_ZERO((void *)block + sizeof(t_block), block->size);
  statics->malloc_count++;
  statics->total_malloc_count++;
  return (block);
}

t_block         *egc_malloc_block(size_t size, t_statics *statics)
{
  t_block       *block;

  LOG("egc_malloc_block() begin");
  request_collection(statics);
  if (!size)
    size++;
  if (size % 8)
    size += 8 - size % 8;
  block = malloc_block_impl(size, statics);
  LOG("egc_malloc_block()");
  LOG_POINTER(block);
  LOG("");
  return (block);
}

void            *egc_malloc(size_t size)
{
  t_block       *block;
  void          *data;
  t_statics     *statics;

  statics = STATICS;
  LOG("egc_malloc() size:");
  LOG_POINTER((void *)size);
  LOG("");
  block = egc_malloc_block(size, statics);
  LOG("egc_malloc() block:");
  LOG_POINTER(block);
  LOG("");
  data = (void *)block + sizeof(t_block);
  if (egc_find_pointed_to_block(statics, data) != block)
    egc_abort();
  if (egc_find_pointed_to_block(statics, block) != block)
    egc_abort();
  return (data);
}

void            *egc_malloc_atomic(size_t size)
{
  t_block       *block;

  block = egc_malloc_block(size, STATICS);
  block->flags |= BLOCK_FLAGS_ATOM;
  return ((void *)block + sizeof(t_block));
}
