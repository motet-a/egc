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

int     hs_get_real_index(t_hs hs, int index)
{
  if (index < 0)
    index += hs.length;
  if (index < 0 || index >= (int)hs.length)
    return (-1);
  return (index);
}

static int      get_real_index(t_hs hs, int index)
{
  if (index == (int)hs.length)
    return (index);
  return (hs_get_real_index(hs, index));
}

t_hs    hs_slice(t_hs hs, int start_index, int end_index)
{
  int   length;

  start_index = get_real_index(hs, start_index);
  end_index = get_real_index(hs, end_index);
  if (start_index < 0 || end_index < 0)
    return (hs_new_empty());
  length = end_index - start_index;
  if (length < 0)
    length = 0;
  return (hs_new_from_n_chars(length, hs.chars + start_index));
}

t_hs    hs_slice_str(const char *string, int start_index, int end_index)
{
  return (hs_slice(hs_new_from_str(string), start_index, end_index));
}

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
  *hs_pointer = hs_slice(*hs_pointer, 0, index);
  return (hs_slice(hs, index, -1));
}

t_glist_hs      hs_split(t_hs hs, t_hs separator)
{
  t_glist_hs    list;
  t_hs          word;

  if (separator.length == 0)
    separator = hs_new_from_str(" ");
  list = glist_hs_new();
  while (hs.length)
    {
      word = skip_word(&hs, separator);
      glist_hs_append(&list, word);
    }
  return (list);
}

t_glist_hs      hs_split_str(t_hs hs, const char *separator)
{
  return (hs_split(hs, hs_new_from_str(separator)));
}
