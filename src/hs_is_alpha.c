/*
** hs_is_alpha.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 20:43:36 2016 antoine
** Last update Wed Apr 20 20:43:36 2016 antoine
*/

#include "hs.h"

int     hs_is_alpha(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)string._length)
    {
      if (!char_is_alpha(string._chars[i]))
        return (0);
    }
  return (1);
}

int     hs_is_lower(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)string._length)
    {
      if (!char_is_lower(string._chars[i]))
        return (0);
    }
  return (1);
}

int     hs_is_upper(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)string._length)
    {
      if (!char_is_upper(string._chars[i]))
        return (0);
    }
  return (1);
}

int     hs_is_alpha_numeric(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)string._length)
    {
      if (!char_is_alpha_numeric(string._chars[i]))
        return (0);
    }
  return (1);
}
