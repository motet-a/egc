/*
** realloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Apr 15 12:42:36 2016 antoine
** Last update Fri Apr 15 12:42:36 2016 antoine
*/

#include "egc_private.h"

/*
** Returns `block` on success or NULL on failure
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
