/*
** hs_strip.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 21:15:55 2016 antoine
** Last update Wed Apr 20 21:15:55 2016 antoine
*/

#include "../include/hs.h"

t_hs    hs_lstrip(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)hs_length(string))
    {
      if (!char_is_whitespace(hs_get(string, i)))
        break;
    }
  if (i == (int)hs_length(string))
    return (hs_new_empty());
  return (hs_slice(string, i, hs_length(string)));
}

t_hs    hs_rstrip(t_hs string)
{
  int   i;

  i = hs_length(string) - 1;
  while (i >= 0)
    {
      if (!char_is_whitespace(hs_get(string, i)))
        break;
      i--;
    }
  return (hs_slice(string, 0, i + 1));
}

t_hs    hs_strip(t_hs string)
{
  return (hs_lstrip(hs_rstrip(string)));
}
