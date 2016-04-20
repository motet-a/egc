/*
** hs_equals.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 13:16:56 2016 antoine
** Last update Sat Apr 16 13:16:56 2016 antoine
*/

#include "../include/hs.h"

int             hs_equals(t_hs a, t_hs b)
{
  size_t        i;

  if (a._length != b._length)
    return (0);
  i = 0;
  while (i < a._length)
    {
      if (a._chars[i] != b._chars[i])
        return (0);
      i++;
    }
  return (1);
}
