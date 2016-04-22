/*
** hs_find.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Apr 22 13:08:26 2016 antoine
** Last update Fri Apr 22 13:08:26 2016 antoine
*/

#include "../include/hs.h"

static int      equals(const char *a, const char *b, int length)
{
  while (length--)
    {
      if (a[length] != b[length])
        return (0);
    }
  return (1);
}

int     hs_find(t_hs hs, t_hs substring, size_t index)
{
  if ((int)hs._length - (int)index < (int)substring._length)
    return (-1);
  while ((int)index + (int)substring._length <= (int)hs._length)
    {
      if (equals(hs._chars + index, substring._chars, substring._length))
        return (index);
      index++;
    }
  return (-1);
}
