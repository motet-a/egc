/*
** hs_starts_with.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 10:49:13 2016 antoine
** Last update Mon Apr 18 10:49:13 2016 antoine
*/

#include "../include/hs.h"

int             hs_starts_with(t_hs string, t_hs prefix)
{
  size_t        i;

  i = 0;
  while (i < string._length && string._chars[i] == prefix._chars[i])
    i++;
  return (i >= prefix._length);
}

int     hs_starts_with_str(t_hs string, const char *prefix)
{
  return (hs_starts_with(string, hs_new_from_str(prefix)));
}


int     hs_ends_with(t_hs string, t_hs postfix)
{
  int   string_i;
  int   postfix_i;

  string_i = hs_length(string);
  postfix_i = hs_length(postfix);
  while (--string_i > 0 && --postfix_i > 0)
    {
      if (string._chars[string_i] != postfix._chars[postfix_i])
        return (0);
    }
  return (postfix_i == 0);
}

int     hs_ends_with_str(t_hs string, const char *prefix)
{
  return (hs_ends_with(string, hs_new_from_str(prefix)));
}
