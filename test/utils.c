/*
** utils.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Apr 12 21:30:59 2016 antoine
** Last update Tue Apr 12 21:30:59 2016 antoine
*/

#include <unistd.h>
#include "utils.h"

void            print_error(const char *string)
{
  while (*string)
    {
      write(STDOUT_FILENO, string, 1);
      string++;
    }
}

int             string_equals(const char *a, const char *b)
{
  while (*a == *b)
    {
      if (!*a)
        return (1);
      a++;
      b++;
    }
  return (0);
}

int             is_zero(void *data, size_t length)
{
  while (length--)
    if (((char *)data)[length])
      return (0);
  return (1);
}
