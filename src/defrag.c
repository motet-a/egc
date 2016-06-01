/*
** defrag.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 08:04:43 2016 antoine
** Last update Sun Apr 17 08:04:43 2016 antoine
*/

#include "private.h"

static void     assert_not_locked(t_block *left, t_block *right)
{
  t_heap        *heap;

  heap = egc_find_pointed_to_heap(STATICS, left);
  while ((left = egc_get_next_block(heap, left)))
    {
      if (!(left->flags & BLOCK_FLAGS_FREE) ||
          left->flags & BLOCK_FLAGS_DEBUG_LOCK)
        egc_abort();
      if (left == right)
        break ;
    }
}

static void     join_blocks(t_block *left, t_block *right, int clear_left)
{
  size_t        new_size;
  char          *begin;
  char          *new_end;

  assert_not_locked(left, right);
  begin = (char *)left + sizeof(t_block);
  new_end = (char *)right + sizeof(t_block) + right->size;
  new_size = new_end - begin;
  if (clear_left)
    SET_TO_ZERO(begin, new_size);
  else
    SET_TO_ZERO(begin + left->size, new_size - left->size);
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
  join_blocks(block, last_free_block, clr_left);
  LOG("egc_defrag_block()");
  LOG_POINTER(block);
  LOG("");
  return (block);
}

static void     egc_defrag_blocks(t_heap *heap, t_block *block)
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

  LOG("egc_defrag()");
  LOG("");
  heap = STATICS->heaps;
  while (heap)
    {
      egc_defrag_blocks(heap, NULL);
      heap = heap->next;
    }
}
