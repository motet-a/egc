/*
** hs_format.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 09:54:53 2016 antoine
** Last update Sat Apr  2 09:54:53 2016 antoine
*/

#include "../include/egc.h"

t_hs            hs_format(const char *format, ...)
{
  va_list       list;
  t_hs          hs;

  va_start(list, format);
  hs = hs_vformat(format, list);
  va_end(list);
  return (hs);
}
