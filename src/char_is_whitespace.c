/*
** char_is_whitespace.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 22:26:21 2016 antoine
** Last update Wed Apr 20 22:26:21 2016 antoine
*/

#include "../include/hs.h"

int     char_is_whitespace(char c)
{
  return (c == ' ' || c == '\f' || c == '\n' || c == '\r' ||
          c == '\t' || c == '\v');
}
