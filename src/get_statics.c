/*
** get_statics.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:07:20 2016 antoine
** Last update Wed Mar 30 18:07:20 2016 antoine
*/

#include "egc_private.h"

#ifndef EGC_DEBUG

t_statics               *egc_get_private_statics(void)
{
  char                  variable_on_the_stack;
  char                  *stack_pointer;

  stack_pointer = &variable_on_the_stack;
  while (*(uint64_t *)stack_pointer != MAGIC_NUMBER + 1)
    {
      stack_pointer++;
    }
  return ((t_statics *)stack_pointer);
}
#endif

void                    *egc_get_statics(void)
{
  return (STATICS->user_statics);
}

size_t                  egc_get_statics_size(void)
{
  return (STATICS->user_statics_size);
}
