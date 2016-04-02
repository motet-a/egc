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

static void     fragment(t_block *block, size_t size)
{
  t_block       *new;
  size_t        old_size;

  old_size = block->size;
  new = (void *)block + sizeof(t_block) + size;
  new->size = old_size - sizeof(t_block) - size;
  new->flags = BLOCK_FLAGS_FREE;
  egc_set_to_zero((void *)new + sizeof(t_block), new->size);
  block->size = size;
  LOG("first block:");
  LOG_POINTER(block);
  LOG("new block:");
  LOG_POINTER(new);
  LOG("");
}

void            egc_block_request_fragmentation(t_block *block, size_t size)
{
  if (block->size > size + 10 * sizeof(size_t))
    fragment(block, size);
}
