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

static void     join_blocks(t_block *left, t_block *right, int clear_left)
{
  size_t        new_size;
  char          *begin;
  char          *new_end;

  begin = (char *)left + sizeof(t_block);
  new_end = (char *)right + sizeof(t_block) + right->size;
  new_size = new_end - begin;
  if (clear_left)
    egc_set_to_zero(begin, new_size);
  else
    egc_set_to_zero(begin + left->size, new_size - left->size);
  left->size = new_size;
}

/*
** Returns `block` on success or NULL on failure
**
** If the given block is used, returns NULL and does nothing.
*/
t_block         *egc_defrag_block(t_heap *heap, t_block *block, int clr_left)
{
  t_block       *last_free_block;

  last_free_block = egc_get_last_free_block(heap, block);
  if (!last_free_block || block == last_free_block)
    return (NULL);
  join_blocks(block, last_free_block, clr_left)
    LOG("egc_block_defrag()");
  LOG_POINTER(block);
  LOG("");
  return (block);
}

void            egc_defrag_blocks(t_heap *heap, t_block *block)
{
  while ((block = egc_get_next_block(heap, block)))
    {
      if (block->flags & BLOCK_FLAGS_FREE)
        egc_defrag_block(heap, block, 1);
    }
}

void            egc_defrag(void)
{
  t_heap        *heap;

  heap = STATICS->heaps;
  while (heap)
    {
      egc_defrag_blocks(heap, NULL);
      heap = heap->next;
    }
}

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
