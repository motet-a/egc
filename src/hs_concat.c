/*
** hs_concat.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 09:18:25 2016 antoine
** Last update Sat Apr  2 09:18:25 2016 antoine
*/

#include "../include/egc.h"

t_hs    hs_concat(t_hs left, t_hs right)
{
  t_hs  new;

  new._length = left._length + right._length;
  new._chars = egc_malloc_atomic(new._length);
  egc_memcpy(new._chars, left._chars, left._length);
  egc_memcpy(new._chars + left._length, right._chars, right._length);
  return (new);
}

t_hs            hs_concat_str_hs(const char *left, t_hs right)
{
  return (hs_concat(hs_new_from_str(left), right));
}

t_hs            hs_concat_hs_str(t_hs left, const char *right)
{
  return (hs_concat(left, hs_new_from_str(right)));
}

t_hs    hs_concat_hs_char(t_hs left, char right)
{
  t_hs  new;

  new._length = left._length + 1;
  new._chars = egc_malloc_atomic(new._length);
  egc_memcpy(new._chars, left._chars, left._length);
  new._chars[left._length] = right;
  return (new);
}

t_hs    hs_concat_char_hs(char left, t_hs right)
{
  t_hs  new;

  new._length = 1 + right._length;
  new._chars = egc_malloc_atomic(new._length);
  new._chars[0] = left;
  egc_memcpy(new._chars + 1, right._chars, right._length);
  return (new);
}
