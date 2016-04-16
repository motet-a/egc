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
  LOG("mark_range()");
  LOG_POINTER(a);
  LOG_POINTER(b);
  LOG("");
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

void            egc_mark_user_statics(void)
{
  t_statics     *statics;

  statics = STATICS;
  if (statics->user_statics && statics->user_statics_size)
    egc_mark_pointer_array(statics->user_statics, statics->user_statics_size);
}
