/*
** collect.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:07:36 2016 antoine
** Last update Thu Mar 31 13:07:36 2016 antoine
*/

#include "egc_private.h"

static void     unmark_heap(t_heap *heap)
{
  t_block       *block;

  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      /*
        printf("block %p size %lu %d\n", block, block->size,
        block->flags & BLOCK_FLAGS_FREE);
        if (block->size > 100000)
        {
        egc_abort();
        }
      */
      block->flags &= ~BLOCK_FLAGS_MARK;
    }
}

static void     unmark_heaps(void)
{
  t_heap        *heap;

  heap = STATICS->heaps;
  while (heap)
    {
      unmark_heap(heap);
      heap = heap->next;
    }
}

void            egc_heap_free_unmarked(t_heap *heap)
{
  t_block       *block;
  t_block_flags flags;

  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      flags = block->flags;
      if (!(flags & BLOCK_FLAGS_MARK) && !(flags & BLOCK_FLAGS_FREE))
        {
          STATICS->free_count++;
          STATICS->total_free_count++;
          egc_block_free(block, heap);
          egc_heap_free_unmarked(heap);
          return;
        }
    }
}

void            egc_free_unmarked(void)
{
  t_heap        *heap;

  heap = STATICS->heaps;
  while (heap)
    {
      egc_heap_free_unmarked(heap);
      heap = heap->next;
    }
}

void            egc_collect(void)
{
  LOG("egc_collect()");
  LOG("");
  unmark_heaps();
  egc_mark_stack();
  egc_mark_user_statics();
  egc_free_unmarked();
  egc_defrag();
  STATICS->collection_count++;
}
