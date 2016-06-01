/*
** block_fragment.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 15:51:46 2016 antoine
** Last update Sat Apr  2 15:51:46 2016 antoine
*/

#include "private.h"

static void     block_fragment(t_block *block,
                               t_heap *heap,
                               size_t new_left_size)
{
  t_block       *new;
  size_t        old_size;

  egc_defrag_block(heap, block, 0);
  if (block->size <= new_left_size)
    return ;
  old_size = block->size;
  new = (void *)((char *)block + sizeof(t_block) + new_left_size);
  new->size = old_size - sizeof(t_block) - new_left_size;
  new->flags = BLOCK_FLAGS_FREE;
  block->size = new_left_size;
  LOG("egc_block_fragment()");
  LOG("old left block:");
  LOG_POINTER(block);
  LOG("new right block:");
  LOG_POINTER(new);
  LOG("");
}

void            egc_block_request_fragmentation(t_block *block,
                                                t_heap *heap,
                                                size_t left_min_size)
{
  size_t        max_size;

  max_size = left_min_size + 4 * sizeof(t_block);
  if (block->size > max_size)
    block_fragment(block, heap, left_min_size);
}
