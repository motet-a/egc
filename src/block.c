/*
** block.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 16:29:32 2016 antoine
** Last update Thu Mar 31 16:29:32 2016 antoine
*/

#include "egc_private.h"

void            egc_block_mark(t_block *block)
{
  void          *data;

  if ((block->flags & BLOCK_FLAGS_FREE) || (block->flags & BLOCK_FLAGS_MARK))
    return ;
  block->flags |= BLOCK_FLAGS_MARK;
  data = (void *)block + sizeof(t_block);
  egc_mark_pointer_array((void **)data, block->size);
}

t_block         *egc_get_next_block(t_heap *heap, t_block *block)
{
  if (block == NULL)
    return ((t_block *)heap->data);
  block = (t_block *)((void *)block + sizeof(t_block) + block->size);
  if ((void *)block >= heap->data + heap->size)
    return (NULL);
  return (block);
}

static t_block  *get_last_free_block(t_heap *heap, t_block *block)
{
  t_block       *previous;

  previous = NULL;
  while (block)
    {
      if (!(block->flags & BLOCK_FLAGS_FREE))
        return (previous);
      previous = block;
      block = egc_get_next_block(heap, block);
    }
  return (NULL);
}

void            egc_block_free(t_block *block, t_heap *heap)
{
  t_block       *last;

  LOG("egc_block_free() block:");
  LOG_POINTER(block);
  LOG("");
  last = get_last_free_block(heap, block);
  if (last && 0)
    {
      block->size = (void *)last - (void *)block - sizeof(t_block);
    }
  block->flags |= BLOCK_FLAGS_FREE;
  egc_set_to_zero((void *)block + sizeof(t_block), block->size);
}
