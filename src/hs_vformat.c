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

static t_hs     format_string(char length, va_list list)
{
  if (length == 'h')
    return (va_arg(list, t_hs));
  return (hs_new_from_str(va_arg(list, char *)));
}

static t_hs     format_decimal(char length, va_list list)
{
  if (length == 'h')
    return (hs_new_int((short)va_arg(list, int)));
  if (length == 'i')
    return (hs_new_int((char)va_arg(list, int)));
  if (length == 'l')
    return (hs_new_int(va_arg(list, long)));
  return (hs_new_int(va_arg(list, int)));
}

static t_hs     format_unsigned(char length, va_list list, unsigned base)
{
  if (length == 'h')
    return (hs_new_uint_base((unsigned short)va_arg(list, unsigned), base));
  if (length == 'i')
    return (hs_new_uint_base((unsigned char)va_arg(list, unsigned), base));
  if (length == 'l')
    return (hs_new_uint_base(va_arg(list, unsigned long), base));
  if (length == 'p')
    return (hs_new_uint_base(va_arg(list, size_t), base));
  return (hs_new_uint_base(va_arg(list, unsigned), base));
}

static t_hs     format_directive(const char **format_pointer, va_list list)
{
  char          length;
  char          c;

  length = ' ';
  while (**format_pointer == 'l' || **format_pointer == 'h')
    {
      length = **format_pointer;
      (*format_pointer)++;
    }
  if (!(c = **format_pointer))
    return (hs_new_from_char('%'));
  (*format_pointer)++;
  if (c == 'd')
    return (format_decimal(length, list));
  if (c == 'u')
    return (format_unsigned(length, list, 10));
  if (c == 'x')
    return (format_unsigned(length, list, 16));
  if (c == 'p')
    return (hs_concat_str_hs("0x", format_unsigned('p', list, 16)));
  if (c == 'c')
    return (hs_new_from_char((char)va_arg(list, int)));
  if (c == 's')
    return (format_string(length, list));
  return (hs_new_from_char('%'));
}

t_hs            hs_vformat(const char *format, va_list list)
{
  t_hs          hs;
  t_hs          directive;

  hs = hs_new_from_str("");
  while (*format)
    {
      if (format[0] == '%' && format[1])
        {
          format++;
          directive = format_directive(&format, list);
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
