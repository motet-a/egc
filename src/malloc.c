/*
** malloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:42:56 2016 antoine
** Last update Wed Mar 30 18:42:56 2016 antoine
*/

#include "egc_private.h"

static void     request_collection(t_statics *statics)
{
  if (statics->malloc_count > 2 * statics->free_count + 10)
    {
      egc_collect();
      statics->malloc_count = 0;
      statics->free_count = 0;
    }
}

t_block         *egc_malloc_block(size_t size, t_statics *statics)
{
  t_block       *block;
  t_heap        *heap;

  request_collection(statics);
  if (size % 8)
    size += sizeof(size_t) - size % sizeof(size_t);
  block = egc_get_free_block(statics, &heap, size);
  if (!block)
    {
      egc_collect();
      egc_heap_add(size);
      block = egc_get_free_block(statics, &heap, size);
      if (!block)
        egc_abort();
    }
  egc_block_request_fragmentation(block, size);
  block->flags &= ~BLOCK_FLAGS_FREE;
  egc_set_to_zero((void *)block + sizeof(t_block), block->size);
  statics->malloc_count++;
  statics->total_malloc_count++;
  return (block);
}

void            *egc_malloc(size_t size)
{
  t_block       *block;

  LOG("egc_malloc() size:");
  LOG_POINTER((void *)size);
  LOG("");
  block = egc_malloc_block(size, STATICS);
  LOG("egc_malloc() block:");
  LOG_POINTER(block);
  LOG("");
  return ((void *)block + sizeof(t_block));
}

/*
** Returns `block` on success
*/
static t_block  *realloc_join(t_heap *heap, t_block *block)
{
  t_block       *last_free;

  last_free = egc_get_last_free_block(heap, block);
  if (!last_free)
    return (NULL);
  block->size = (void *)last_free - (void *)heap + last_free->size;
  egc_set_to_zero((void *)block + sizeof(t_block), block->size);
  return (block);
}

static void     *realloc_new(t_heap *heap, t_block *block, size_t size)
{
  t_block       *new;

  new = egc_malloc_block(size, STATICS);
  new->flags = block->flags;
  egc_block_free(block, heap);
  return (new);
}

static void     *realloc_split(t_block *block, size_t size)
{
  egc_block_request_fragmentation(block, size);
  return (block + sizeof(t_block));
}

void            *egc_realloc(void *data, size_t size)
{
  t_block       *block;
  t_heap        *heap;

  LOG("egc_realloc()");
  LOG("");
  if (!data)
    return (egc_malloc(size));
  block = data - sizeof(t_block);
  if (size < block->size)
    return (realloc_split(block, size));
  heap = egc_get_pointed_to_heap(STATICS, block + 1);
  if (realloc_join(heap, block))
    return (block + sizeof(t_block));
  return (realloc_new(heap, block, size));
}

void            *egc_malloc_atomic(size_t size)
{
  t_block       *block;

  block = egc_malloc_block(size, STATICS);
  block->flags |= BLOCK_FLAGS_ATOM;
  return ((void *)block + sizeof(t_block));
}
