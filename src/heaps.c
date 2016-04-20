/*
** heaps.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 15:49:28 2016 antoine
** Last update Sat Apr  2 15:49:28 2016 antoine
*/

#include "private.h"

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
