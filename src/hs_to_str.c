/*
** hs_to_str.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 21 16:22:15 2016 antoine
** Last update Thu Apr 21 16:22:15 2016 antoine
*/

#include "../include/egc.h"

t_hs    hs_escape_nuls(t_hs string)
{
  t_hs  r;
  int   i;
  char  c;

  r = hs_new_empty();
  i = -1;
  while (++i < (int)hs_length(string))
    {
      c = hs_get(string, i);
      if (!c)
        r = hs_concat(r, hs("\\0"));
      else
        r = hs_concat(r, hs_new_from_char(c));
    }
  return (r);
}

char    *hs_to_str(t_hs string)
{
  t_hs  escaped;
  char  *r;
  int   length;

  escaped = hs_escape_nuls(string);
  length = hs_length(escaped);
  r = egc_malloc_atomic(length + 1);
  egc_memcpy(r, escaped._chars, length);
  r[length] = '\0';
  return (r);
}
