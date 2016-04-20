/*
** hs_slice.c<src> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 22:33:20 2016 antoine
** Last update Sat Apr 16 22:33:20 2016 antoine
*/

#include "../include/hs.h"

int     hs_get_real_index(t_hs hs, int index)
{
  if (index < 0)
    index += hs._length;
  if (index < 0 || index >= (int)hs._length)
    return (-1);
  return (index);
}

static int      get_real_index(t_hs hs, int index)
{
  if (index == (int)hs._length)
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
  return (hs_new_from_n_chars(length, hs._chars + start_index));
}
