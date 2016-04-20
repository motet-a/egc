/*
** block.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 16:29:32 2016 antoine
** Last update Thu Mar 31 16:29:32 2016 antoine
*/

#include "private.h"

t_block         *egc_get_next_block(t_heap *heap, t_block *block)
{
  if (block == NULL)
    return ((t_block *)heap->data);
  block = (t_block *)((char *)block + sizeof(t_block) + block->size);
  if ((void *)block >= heap->data + heap->size)
    return (NULL);
  return (block);
}

t_block         *egc_get_last_free_block(t_heap *heap, t_block *block)
{
  t_block       *previous;

  previous = NULL;
  while (block)
    {
      if (block == previous)
        egc_abort();
      if (!(block->flags & BLOCK_FLAGS_FREE))
        break;
      previous = block;
      block = egc_get_next_block(heap, block);
    }
  return (previous);
}

void            egc_block_free(t_block *block, t_heap *heap)
{
  t_block       *last;

  if (block->flags & BLOCK_FLAGS_FREE)
    egc_abort();
  if (block->flags & BLOCK_FLAGS_DEBUG_LOCK)
    {
      egc_log("egc_block_free(): locked block");
      egc_log_pointer(block);
      egc_log("");
      egc_abort();
    }
  LOG("egc_block_free() block:");
  LOG_POINTER(block);
  LOG("");
  last = egc_get_last_free_block(heap, block);
  if (last)
    {
      block->size = (char *)last - (char *)block + sizeof(t_block);
      block->size += last->size;
    }
  block->flags = BLOCK_FLAGS_FREE;
  egc_set_to_zero((void *)block + sizeof(t_block), block->size);
}

void            egc_debug_lock_on(void *pointer)
{
  t_block       *block;

  block = (t_block *)((char *)pointer - sizeof(t_block));
  if (block->flags & BLOCK_FLAGS_FREE)
    egc_abort();
  if (block->flags & BLOCK_FLAGS_DEBUG_LOCK)
    egc_abort();
  block->flags |= BLOCK_FLAGS_DEBUG_LOCK;
}

void            egc_debug_lock_off(void *pointer)
{
  t_block       *block;

  block = (t_block *)((char *)pointer - sizeof(t_block));
  if (block->flags & BLOCK_FLAGS_FREE)
    egc_abort();
  if (!(block->flags & BLOCK_FLAGS_DEBUG_LOCK))
    egc_abort();
  block->flags &= ~BLOCK_FLAGS_DEBUG_LOCK;
}
