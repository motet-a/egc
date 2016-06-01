/*
** realloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Apr 15 12:42:36 2016 antoine
** Last update Fri Apr 15 12:42:36 2016 antoine
*/

#include "private.h"

static void     *realloc_split(t_heap *heap, t_block *block, size_t size)
{
  char          *begin;

  egc_block_request_fragmentation(block, heap, size);
  begin = (char *)block + sizeof(t_block);
  if (block->size > size)
    SET_TO_ZERO(begin + size, block->size - size);
  LOG("realloc_split()");
  LOG_POINTER(block);
  LOG("");
  return (begin);
}

static void     *realloc_new(t_heap *heap, t_block *block, size_t size)
{
  t_block       *new;
  size_t        preserved_size;

  LOG("realloc_new() begin");
  new = egc_malloc_block(size, STATICS);
  if (block->flags & BLOCK_FLAGS_FREE)
    egc_abort();
  new->flags = block->flags;
  preserved_size = size;
  if (block->size < preserved_size)
    preserved_size = block->size;
  egc_memcpy((char *)new + sizeof(t_block),
             (char *)block + sizeof(t_block),
             preserved_size);
  LOG("realloc_new()");
  LOG_UINT(size);
  LOG_POINTER(block);
  LOG_POINTER(new);
  LOG("");
  egc_block_free(block, heap);
  return ((char *)new + sizeof(t_block));
}

void            *egc_realloc(void *data, size_t size)
{
  t_block       *block;
  t_heap        *heap;

  LOG("egc_realloc() begin");
  LOG("");
  egc_collect();
  if (!data)
    return (egc_malloc(size));
  block = data - sizeof(t_block);
  LOG("egc_realloc()");
  LOG_POINTER(block);
  heap = egc_find_pointed_to_heap(STATICS, data);
  if (!heap)
    egc_abort();
  /*
    TODO: Test and enable the following statements

    if (size < block->size)
    return (realloc_split(heap, block, size));
    if (egc_defrag_block(heap, block, 0))
    return ((char *)block + sizeof(t_block));
  */
  return (realloc_new(heap, block, size));
}
