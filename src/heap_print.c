/*
** heap_print.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Apr 19 13:24:48 2016 antoine
** Last update Tue Apr 19 13:24:48 2016 antoine
*/

#include "private.h"

void            egc_heap_print(t_heap *heap)
{
  t_block       *block;

  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      printf("block %p size %lu %d\n", block, block->size,
             block->flags & BLOCK_FLAGS_FREE);
      if (!block->size || block->size > 100000)
        {
          egc_abort();
        }
    }
}

void            egc_heaps_print(void)
{
  t_heap        *heap;

  heap = STATICS->heaps;
  while (heap)
    {
      egc_heap_print(heap);
      heap = heap->next;
    }
  puts("");
}
