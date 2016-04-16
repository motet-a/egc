/*
** hs_new.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 09:03:29 2016 antoine
** Last update Sat Apr  2 09:03:29 2016 antoine
*/

#include "../include/egc.h"

t_hs            hs_new_from_str(const char *string)
{
  return (hs_new_from_n_chars(egc_strlen(string), string));
}

t_hs            hs_new_from_n_chars(size_t n, const char *chars)
{
  t_hs          hs;

  hs.length = n;
  hs.chars = egc_malloc_atomic(hs.length);
  egc_memcpy(hs.chars, chars, n);
  return (hs);
}

t_hs    hs_new_from_char(char c)
{
  return (hs_new_from_n_chars(1, &c));
}

t_hs    hs_new_empty()
{
  return (hs_new_from_n_chars(0, NULL));
}
