/*
** hs_is_digit.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 25 16:45:58 2016 antoine
** Last update Mon Apr 25 16:45:58 2016 antoine
*/

#include "hs.h"

int     hs_is_digit(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)string._length)
    {
      if (!char_is_alpha_numeric(string._chars[i]))
        return (0);
    }
  return (1);
}

int     hs_is_hex_digit(t_hs string)
{
  int   i;

  i = -1;
  while (++i < (int)string._length)
    {
      if (!char_is_hex_digit(string._chars[i]))
        return (0);
    }
  return (1);
}
