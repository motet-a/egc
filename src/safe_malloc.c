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

static size_t   set_to_zero_8(size_t sdata, size_t length8)
{
  while (length8 > 0)
    {
      ((size_t *)sdata)[0] = 0;
      ((size_t *)sdata)[1] = 0;
      ((size_t *)sdata)[2] = 0;
      ((size_t *)sdata)[3] = 0;
      ((size_t *)sdata)[4] = 0;
      ((size_t *)sdata)[5] = 0;
      ((size_t *)sdata)[6] = 0;
      ((size_t *)sdata)[7] = 0;
      sdata += 8 * sizeof(size_t);
      length8--;
    }
  return (length8);
}

void            egc_set_to_zero(void *data, size_t length)
{
  size_t        sdata;
  size_t        length8;

  if (length >= 8)
    {
      sdata = (size_t)data;
      while (sdata % sizeof(size_t) && length--)
        ((char *)sdata++)[0] = '\0';
      length8 = length / (sizeof(size_t) * 8);
      length8 = set_to_zero_8(sdata, length8);
      length %= sizeof(size_t) * 8;
      while (length8)
        ((size_t *)sdata)[length8--] = 0;
      length %= sizeof(size_t) ;
    }
  while (length--)
    ((char *)data)[length] = '\0';
}
