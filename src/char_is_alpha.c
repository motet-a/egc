/*
** char_is_alpha.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 20:45:57 2016 antoine
** Last update Wed Apr 20 20:45:57 2016 antoine
*/

#include "../include/hs.h"

char    char_is_alpha(char c)
{
  return (char_is_lower(c) || char_is_upper(c));
}

char    char_is_alpha_numeric(char c)
{
  return (char_is_alpha(c) || char_is_digit(c));
}

char    char_is_lower(char c)
{
  return ('a' <= c && c <= 'z');
}

char    char_is_upper(char c)
{
  return ('A' <= c && c <= 'Z');
}
