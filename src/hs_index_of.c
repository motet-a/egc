/*
** hs_index_of.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 16:01:38 2016 antoine
** Last update Sat Apr 16 16:01:38 2016 antoine
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

int     hs_index_of(t_hs hs, t_hs substring)
{
  int   index;

  if (hs._length < substring._length)
    return (-1);
  index = -1;
  while (++index < (int)hs._length)
    {
      if (equals(hs._chars + index, substring._chars, substring._length))
        return (index);
    }
  return (-1);
}

int     hs_index_of_str(t_hs hs, const char *substring)
{
  return (hs_index_of(hs, hs_new_from_str(substring)));
}
