/*
** hs_format_directive.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 08:43:26 2016 antoine
** Last update Sun Apr 17 08:43:26 2016 antoine
*/

#include "../include/egc.h"

static t_hs     format_string(char length, va_list list)
{
  if (length == 'h')
    return (va_arg(list, t_hs));
  return (hs(va_arg(list, char *)));
}

static t_hs     format_decimal(char length, va_list list)
{
  if (length == 'h')
    return (hs_new_from_int((short)va_arg(list, int)));
  if (length == 'i')
    return (hs_new_from_int((char)va_arg(list, int)));
  if (length == 'l')
    return (hs_new_from_int(va_arg(list, long)));
  return (hs_new_from_int(va_arg(list, int)));
}

static t_hs     format_unsigned(char length, va_list list, unsigned base)
{
  unsigned      n;

  if (length == 'h')
    {
      n = va_arg(list, unsigned);
      return (hs_new_from_uint_base((unsigned short)n, base));
    }
  if (length == 'i')
    {
      n = va_arg(list, unsigned);
      return (hs_new_from_uint_base((unsigned char)n, base));
    }
  if (length == 'l')
    return (hs_new_from_uint_base(va_arg(list, unsigned long), base));
  if (length == 'p')
    return (hs_new_from_uint_base(va_arg(list, size_t), base));
  return (hs_new_from_uint_base(va_arg(list, unsigned), base));
}

static t_hs     format_directive(char length, char c, va_list list)
{
  if (c == 'd' || c == 'i')
    return (format_decimal(length, list));
  if (c == 'u')
    return (format_unsigned(length, list, 10));
  if (c == 'x')
    return (format_unsigned(length, list, 16));
  if (c == 'p')
    return (hs_concat(hs("0x"), format_unsigned('p', list, 16)));
  if (c == 'c')
    return (hs_new_from_char((char)va_arg(list, int)));
  if (c == 's')
    return (format_string(length, list));
  return (hs_new_from_char('%'));
}

t_hs    hs_format_directive(const char **format_pointer, va_list list)
{
  char  length;
  char  c;

  length = ' ';
  while (**format_pointer == 'l' || **format_pointer == 'h')
    {
      if (length == 'h' && **format_pointer == 'h')
        length = 'i';
      else
        length = **format_pointer;
      (*format_pointer)++;
    }
  if (!(c = **format_pointer))
    return (hs_new_from_char('%'));
  (*format_pointer)++;
  return (format_directive(length, c, list));
}
