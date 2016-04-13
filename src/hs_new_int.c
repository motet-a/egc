/*
** hs_new_int.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 10:50:48 2016 antoine
** Last update Sat Apr  2 10:50:48 2016 antoine
*/

#include "../include/egc.h"

t_hs    hs_new_int(long n)
{
  return (hs_new_int_base(n, 10));
}

t_hs    hs_new_int_base(long n, unsigned base)
{
  if (n < 0)
    return (hs_concat_char_hs('-', hs_new_uint_base(-n, base)));
  else
    return (hs_new_uint_base(n, base));
}

t_hs    hs_new_uint(unsigned long n)
{
  return (hs_new_uint_base(n, 10));
}

static char     get_digit_char(size_t n)
{
  if (n < 10)
    return (n + '0');
  return (n - 10 + 'a');
}

t_hs    hs_new_uint_base(unsigned long n, unsigned base)
{
  t_hs  s;

  if (n >= base)
    s = hs_new_uint_base(n / base, base);
  else
    s = hs_new_empty();
  s = hs_concat_hs_char(s, get_digit_char(n % base));
  return (s);
}
