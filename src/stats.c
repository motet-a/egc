/*
** stats.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 10:13:35 2016 antoine
** Last update Thu Apr 14 10:13:35 2016 antoine
*/

#include "private.h"

static int      get_block_count(t_heap *heap)
{
  int           count;
  t_block       *block;

  count = 0;
  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    count++;
  return (count);
}

static int      get_used_block_count(t_heap *heap)
{
  int           count;
  t_block       *block;

  count = 0;
  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      if (!(block->flags & BLOCK_FLAGS_FREE))
        count++;
    }
  return (count);
}

static void     print_heap(t_heap *heap)
{
  egc_log("size: ");
  egc_log_uint(heap->size);
  egc_log("blocks: ");
  egc_log_uint(get_block_count(heap));
  egc_log("used blocks: ");
  egc_log_uint(get_used_block_count(heap));
  egc_log("");
}

void    egc_print_stats(void)
{
  t_heap        *heap;

  egc_log("==== Heaps ====");
  egc_log("");
  heap = STATICS->heaps;
  while (heap)
    {
      print_heap(heap);
      heap = heap->next;
    }
}
