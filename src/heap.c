/*
** heap.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 19:09:54 2016 antoine
** Last update Wed Mar 30 19:09:55 2016 antoine
*/

#include "private.h"

t_block         *egc_heap_get_free_block(t_heap *heap, size_t size)
{
  t_block       *block;

  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      if ((block->flags & BLOCK_FLAGS_FREE) && block->size >= size)
        return (block);
    }
  return (NULL);
}

t_heap          *egc_heap_new(size_t size, t_heap *next)
{
  t_heap        *heap;
  t_block       *block;
  void          *data;

  data = egc_safe_malloc(size);
  LOG("egc_heap_new() size:");
  LOG_POINTER((void *)size);
  LOG("egc_heap_new() data:");
  LOG_POINTER(data);
  LOG("");
  egc_set_to_zero(data, size);
  block = (t_block *)data;
  block->size = size - sizeof(t_block);
  block->flags = BLOCK_FLAGS_FREE;
  heap = egc_safe_malloc(sizeof(t_heap));
  heap->data = data;
  heap->next = next;
  heap->size = size;
  return (heap);
}

void            egc_heap_delete(t_heap *heap)
{
  if (!heap)
    return ;
  free(heap->data);
  egc_heap_delete(heap->next);
  free(heap);
}

static size_t   egc_max(size_t a, size_t b)
{
  return (a > b ? a : b);
}

void            egc_heap_add(size_t min_block_size)
{
  size_t        size;

  min_block_size += sizeof(t_block);
  size = egc_max(STATICS->heap_size * 2, min_block_size);
  STATICS->heap_size = size;
  STATICS->heaps = egc_heap_new(size, STATICS->heaps);
}
