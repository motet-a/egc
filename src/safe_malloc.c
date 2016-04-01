/*
** safe_malloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 17:47:49 2016 antoine
** Last update Wed Mar 30 17:47:49 2016 antoine
*/

#include "egc_private.h"

static void     on_malloc_error(void)
{
  STATICS->error_callback("malloc() returned NULL\n");
  egc_exit(1);
}

void            *egc_safe_malloc(size_t length)
{
  void          *data;

  data = malloc(length);
  if (!data)
    on_malloc_error();
  return (data);
}

void            egc_set_to_zero(void *data, size_t length)
{
  while (length--)
    {
      ((char *)data)[length] = '\0';
    }
}
