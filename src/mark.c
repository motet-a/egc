/*
** mark.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:01:50 2016 antoine
** Last update Thu Mar 31 13:01:50 2016 antoine
*/

#include "egc_private.h"

t_heap          *egc_get_pointed_to_heap(const t_statics *statics,
                                         const void *pointer)
{
  t_heap        *heap;
  void          *data;

  heap = statics->heaps;
  while (heap)
    {
      data = heap->data;
      if (pointer >= data && pointer < data + sizeof(t_block) + heap->size)
        return (heap);
      heap = heap->next;
    }
  return (NULL);
}

static t_block  *get_pointed_to_block(t_statics *statics, void *pointer)
{
  t_heap        *heap;
  t_block       *block;
  void          *data;

  heap = egc_get_pointed_to_heap(statics, pointer);
  if (!heap)
    return (NULL);
  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      data = (void *)block;
      if (pointer < data)
        {
          LOG("get_pointed_block() error");
          break;
        }
      if (pointer < data + sizeof(t_block) + block->size)
        return (block);
    }
  return (NULL);
}

void            egc_mark_pointer_array(void **pointer_array, size_t size)
{
  t_block       *block;
  t_statics     *statics;
  char          *char_array;

  if (size < sizeof(void *))
    return ;
  char_array = (char *)pointer_array;
  statics = STATICS;
  size -= sizeof(void *);
  while (size--)
    {
      block = get_pointed_to_block(statics, *(void **)(char_array + size));
      if (block)
        egc_block_mark(block);
    }
}
