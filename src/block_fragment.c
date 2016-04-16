/*
** block_fragment.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 15:51:46 2016 antoine
** Last update Sat Apr  2 15:51:46 2016 antoine
*/

#include "egc_private.h"

void            egc_block_fragment(t_block *block, size_t min_size)
{
  t_block       *new;
  size_t        old_size;

  if (block->size <= min_size)
    return ;
  old_size = block->size;
  new = (void *)block + sizeof(t_block) + min_size;
  new->size = old_size - sizeof(t_block) - min_size;
  new->flags = BLOCK_FLAGS_FREE;
  block->size = min_size;
  LOG("first block:");
  LOG_POINTER(block);
  LOG("new block:");
  LOG_POINTER(new);
  LOG("");
}

void            egc_block_request_fragmentation(t_block *block,
                                                size_t min_size)
{
  size_t        max_size;

  max_size = min_size + 10 * sizeof(size_t);
  if (block->size > max_size)
    egc_block_fragment(block, min_size);
}
