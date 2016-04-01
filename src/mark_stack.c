/*
** mark_stack.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:03:03 2016 antoine
** Last update Thu Mar 31 13:03:03 2016 antoine
*/

#include "egc_private.h"

static void     mark_range(void *a, void *b)
{
  if (a < b)
    egc_mark_pointer_array(a, b - a);
  else
    egc_mark_pointer_array(b, a - b);
}

void            egc_mark_stack(void)
{
  void          *stack_bottom;
  uint64_t      variable_on_the_stack;

  stack_bottom = STATICS->stack_bottom;
  mark_range(&variable_on_the_stack, stack_bottom);
}
