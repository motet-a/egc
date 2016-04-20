/*
** mark.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:01:50 2016 antoine
** Last update Thu Mar 31 13:01:50 2016 antoine
*/

#include "private.h"

static void     mark_block(t_block *block)
{
  void          *data;
  t_block_flags flags;

  flags = block->flags;
  if ((flags & BLOCK_FLAGS_FREE) || (flags & BLOCK_FLAGS_MARK))
    return ;
  block->flags |= BLOCK_FLAGS_MARK;
  if (flags & BLOCK_FLAGS_ATOM)
    return ;
  data = (char *)block + sizeof(t_block);
  egc_mark_pointer_array((void **)data, block->size);
}

void            egc_mark_pointer_array(void **pointer_array, size_t size)
{
  t_block       *block;
  t_statics     *statics;
  char          *char_array;
  void          *p;

  if (size < sizeof(void *))
    return ;
  char_array = (char *)pointer_array;
  statics = STATICS;
  size -= sizeof(void *);
  while (size)
    {
      p = *(void **)(char_array + size);
      block = egc_find_pointed_to_block(statics, p);
      if (block)
        mark_block(block);
      size--;
    }
}

void            egc_mark_user_statics(void)
{
  t_statics     *statics;

  statics = STATICS;
  if (statics->user_statics && statics->user_statics_size)
    egc_mark_pointer_array(statics->user_statics, statics->user_statics_size);
}
