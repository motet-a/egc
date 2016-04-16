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

  if (a.length != b.length)
    return (0);
  i = 0;
  while (i < a.length)
    {
      if (a.chars[i] != b.chars[i])
        return (0);
      i++;
    }
  return (1);
}

int     hs_equals_str(t_hs a, const char *b)
{
  return (hs_equals(a, hs_new_from_str(b)));
}
