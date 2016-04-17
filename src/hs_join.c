/*
** hs_join.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 10:36:55 2016 antoine
** Last update Sun Apr 17 10:36:55 2016 antoine
*/

#include "../include/egc.h"

t_hs    hs_join(t_hs separator, const t_glist_hs *strings)
{
  int   i;
  t_hs  s;

  s = hs_new_empty();
  i = -1;
  while (++i < glist_hs_size(strings))
    {
      if (i)
        s = hs_concat(s, separator);
      s = hs_concat(s, glist_hs_get(strings, i));
    }
  return (s);
}

t_hs    hs_join_str_hs(const char *separator, const t_glist_hs *strings)
{
  return (hs_join(hs_new_from_str(separator), strings));
}
