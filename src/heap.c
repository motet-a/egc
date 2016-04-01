/*
** heap.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 19:09:54 2016 antoine
** Last update Wed Mar 30 19:09:55 2016 antoine
*/

#include "egc_private.h"

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

t_heap          *egc_find_heap_from_pointer(t_heap *heap, const void *p)
{
  while (heap)
    {
      if (p >= heap->data && p < heap->data + heap->size)
        return (heap);
      heap = heap->next;
    }
  return (NULL);
}

t_block         *egc_get_free_block(t_statics *statics,
                                    t_heap **heap_pointer,
                                    size_t size)
{
  t_block       *block;
  t_heap        *heap;

  heap = statics->heaps;
  *heap_pointer = NULL;
  while (heap)
    {
      *heap_pointer = heap;
      block = egc_heap_get_free_block(heap, size);
      if (block)
        return (block);
      heap = heap->next;
    }
  return (NULL);
}
