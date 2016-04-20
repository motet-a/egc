/*
** debug_lock.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 22:05:20 2016 antoine
** Last update Sat Apr 16 22:05:20 2016 antoine
*/

#include "private.h"

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
