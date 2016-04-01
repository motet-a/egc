/*
** test.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Apr  1 23:56:36 2016 antoine
** Last update Fri Apr  1 23:56:36 2016 antoine
*/

#include <unistd.h>
#include "test.h"

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

void            string_copy(char *dest, const char *source)
{
  while (*source)
    {
      *dest = *source;
      dest++;
      source++;
    }
  *dest = '\0';
}
