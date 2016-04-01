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

static size_t   egc_max(size_t a, size_t b)
{
  return (a > b ? a : b);
}

int             egc_get_heap_count(void)
{
  t_heap        *heap;
  int           count;

  count = 0;
  heap = STATICS->heaps;
  while (heap)
    {
      count++;
      heap = heap->next;
    }
  return (count);
}

static void     add_heap(size_t min_block_size)
{
  size_t        size;

  min_block_size += sizeof(t_block);
  size = egc_max(STATICS->heap_size * 2, min_block_size);
  STATICS->heap_size = size;
  STATICS->heaps = egc_heap_new(size, STATICS->heaps);
}

static void     fragment_block(t_block *block, size_t size)
{
  t_block       *new;
  size_t        old_size;

  old_size = block->size;
  new = (void *)block + sizeof(t_block) + size;
  new->size = old_size - sizeof(t_block) - size;
  new->flags = BLOCK_FLAGS_FREE;
  block->size = size;
  LOG("first block:");
  LOG_POINTER(block);
  LOG("new block:");
  LOG_POINTER(new);
  LOG("");
}

static t_block  *malloc_block(size_t size)
{
  t_block       *block;
  t_statics     *statics;
  t_heap        *heap;

  statics = STATICS;
  egc_collect();
  block = egc_get_free_block(statics, &heap, size);
  if (!block)
    {
      egc_collect();
      add_heap(size);
      block = egc_get_free_block(statics, &heap, size);
      if (!block)
        {
          LOG("malloc_block() error");
        }
    }
  if (block->size > size + 10 * sizeof(size_t))
    fragment_block(block, size);
  block->flags &= ~BLOCK_FLAGS_FREE;
  statics->malloc_count++;
  return (block);
}

void            *egc_malloc(size_t size)
{
  t_block       *block;

  if (size % 8)
    size += sizeof(size_t) - size % sizeof(size_t);
  LOG("egc_malloc() size:");
  LOG_POINTER((void *)size);
  LOG("");
  block = malloc_block(size);
  LOG("egc_malloc() block:");
  LOG_POINTER(block);
  LOG("");
  return ((void *)block + sizeof(t_block));
}
