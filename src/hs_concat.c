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

  new.length = left.length + right.length;
  new.chars = egc_malloc(new.length);
  egc_memcpy(new.chars, left.chars, left.length);
  egc_memcpy(new.chars + left.length, right.chars, right.length);
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

  new.length = left.length + 1;
  new.chars = egc_malloc(new.length);
  egc_memcpy(new.chars, left.chars, left.length);
  new.chars[left.length] = right;
  return (new);
}

t_hs    hs_concat_char_hs(char left, t_hs right)
{
  t_hs  new;

  new.length = 1 + right.length;
  new.chars = egc_malloc(new.length);
  new.chars[0] = left;
  egc_memcpy(new.chars + 1, right.chars, right.length);
  return (new);
}
