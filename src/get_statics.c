/*
** get_statics.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:07:20 2016 antoine
** Last update Wed Mar 30 18:07:20 2016 antoine
*/

#include "private.h"

#ifndef EGC_DEBUG

static void             sigsegv_suicide(void)
{
  char                  *c;

  c = NULL;
  *c = 123;
}

t_statics               *egc_get_statics_0(void *stack_pointer)
{
  t_statics             *statics;

  while (1)
    {
      if (*(uint64_t *)stack_pointer == MAGIC_NUMBER_0 + 1)
        {
          statics = (t_statics *)stack_pointer;
          if (statics->magic_number_1 == MAGIC_NUMBER_1)
            return statics;
        }
      stack_pointer++;
    }
  sigsegv_suicide();
  return (NULL);
}

t_statics               *egc_get_private_statics(void)
{
  char                  variable_on_the_stack;

  return (egc_get_statics_0(&variable_on_the_stack));
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
