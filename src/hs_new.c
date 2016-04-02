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
  return (hs_new_from_length(egc_strlen(string), string));
}

t_hs            hs_new_from_length(size_t length, const char *chars)
{
  t_hs          hs;

  hs.length = length;
  hs.chars = egc_malloc(hs.length);
  egc_memcpy(hs.chars, chars, length);
  return (hs);
}

t_hs    hs_new_from_char(char c)
{
  return (hs_new_from_length(1, &c));
}
