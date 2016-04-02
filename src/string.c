/*
** string.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 09:21:56 2016 antoine
** Last update Sat Apr  2 09:21:56 2016 antoine
*/

#include "../include/egc_string.h"

size_t          egc_strlen(const char *string)
{
  const char    *begin;

  begin = string;
  while (*string)
    string++;
  return (string - begin);
}

void            egc_memcpy(char *dest, const char *source, size_t n)
{
  while (n--)
    dest[n] = source[n];
}

void            egc_strcpy(char *dest, const char *source)
{
  while (*source)
    {
      *dest = *source;
      dest++;
      source++;
    }
  *dest = '\0';
}
