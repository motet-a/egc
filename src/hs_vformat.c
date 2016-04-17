/*
** hs_vformat.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 10:33:02 2016 antoine
** Last update Sat Apr  2 10:33:02 2016 antoine
*/

#include "../include/egc.h"

t_hs            hs_vformat(const char *format, va_list list)
{
  t_hs          hs;
  t_hs          directive;

  hs = hs_new_empty();
  while (*format)
    {
      if (format[0] == '%' && format[1])
        {
          format++;
          directive = hs_format_directive(&format, list);
          hs = hs_concat(hs, directive);
        }
      else
        {
          hs = hs_concat_hs_char(hs, *format);
          format++;
        }
    }
  return (hs);
}
