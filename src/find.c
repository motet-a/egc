/*
** find.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 10:41:24 2016 antoine
** Last update Wed Apr 20 10:41:24 2016 antoine
*/

#include "private.h"

t_heap          *egc_find_pointed_to_heap(const t_statics *statics,
                                          void *pointer)
{
  t_heap        *heap;
  void          *data;

  heap = statics->heaps;
  while (heap)
    {
      data = heap->data;
      if (pointer >= data && (char *)pointer < (char *)data + heap->size)
        {
          return (heap);
        }
      heap = heap->next;
    }
  return (NULL);
}

t_block         *egc_find_pointed_to_block(t_statics *statics, void *pointer)
{
  t_heap        *heap;
  t_block       *block;
  void          *data;

  heap = egc_find_pointed_to_heap(statics, pointer);
  if (!heap)
    return (NULL);
  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      if (pointer < (void *)block)
        egc_abort();
      data = (char *)block + sizeof(t_block);
      if (pointer < data + block->size)
        return (block);
    }
  return (NULL);
}
