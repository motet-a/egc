/*
** char_case.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 23:41:39 2016 antoine
** Last update Wed Apr 20 23:41:39 2016 antoine
*/

#include "../include/hs.h"

char    char_to_lower(char c)
{
  if (char_is_upper(c))
    return (c + ('a' - 'A'));
  return (c);
}

char    char_to_upper(char c)
{
  if (char_is_lower(c))
    return (c - ('a' - 'A'));
  return (c);
}
