/*
** hs_split.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 15:55:33 2016 antoine
** Last update Sat Apr 16 15:55:33 2016 antoine
*/

#include "../include/egc.h"

static t_hs     skip_word(t_hs *hs_pointer, t_hs separator)
{
  int           index;
  t_hs          hs;

  hs = *hs_pointer;
  index = hs_index_of(hs, separator);
  if (index == -1)
    {
      *hs_pointer = hs_new_empty();
      return (hs);
    }
  *hs_pointer = hs_slice(hs, index, hs_length(hs));
  return (hs_slice(hs, 0, index));
}

static int      skip_separator(t_hs *hs_pointer, t_hs separator)
{
  int           index;
  t_hs          hs;

  hs = *hs_pointer;
  index = hs_index_of(hs, separator);
  if (index != 0)
    return (0);
  *hs_pointer = hs_slice(hs, hs_length(separator), hs_length(hs));
  return (1);
}

t_glist_hs      hs_split(t_hs s, t_hs separator)
{
  t_glist_hs    list;
  t_hs          word;

  if (hs_length(separator) == 0)
    separator = hs(" ");
  list = glist_hs_new();
  if (!hs_length(s))
    return (list);
  while (1)
    {
      word = skip_word(&s, separator);
      glist_hs_append(&list, word);
      if (!hs_length(s))
        break;
      if (!skip_separator(&s, separator))
        break;
    }
  return (list);
}
