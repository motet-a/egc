/*
** unmark.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 10:15:50 2016 antoine
** Last update Wed Apr 20 10:15:50 2016 antoine
*/

#include "private.h"

static void     unmark_heap(t_heap *heap)
{
  t_block       *block;

  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    block->flags &= ~BLOCK_FLAGS_MARK;
}

void            egc_unmark(void)
{
  t_heap        *heap;

  heap = STATICS->heaps;
  while (heap)
    {
      unmark_heap(heap);
      heap = heap->next;
    }
}
