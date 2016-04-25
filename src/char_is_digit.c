/*
** char_is_digit.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 25 16:47:18 2016 antoine
** Last update Mon Apr 25 16:47:18 2016 antoine
*/

#include "../include/hs.h"

char    char_is_digit(char c)
{
  return ('0' <= c && c <= '9');
}

char    char_is_hex_digit(char c)
{
  return (char_is_digit(c) ||
          ('a' <= c && c <= 'f') ||
          ('A' <= c && c <= 'F'));
}
