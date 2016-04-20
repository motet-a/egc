/*
** log.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:22:17 2016 antoine
** Last update Thu Mar 31 13:22:17 2016 antoine
*/

#include "private.h"

void            egc_log(const char *message)
{
  t_statics     *statics;

  statics = STATICS;
  statics->error_callback("egc: ");
  statics->error_callback(message);
  statics->error_callback("\n");
}

static char     get_digit_char(size_t n)
{
  if (n < 10)
    return (n + '0');
  return (n - 10 + 'a');
}

static void     log_uint(t_statics *statics, unsigned long n, unsigned base)
{
  char          digit[2];

  if (n >= base)
    log_uint(statics, n / base, base);
  digit[0] = get_digit_char(n % base);
  digit[1] = '\0';
  statics->error_callback(digit);
}

void            egc_log_pointer(void *pointer)
{
  t_statics     *statics;

  statics = STATICS;
  statics->error_callback("egc: 0x");
  log_uint(statics, (unsigned long)pointer, 16);
  statics->error_callback("\n");
}

void            egc_log_uint(unsigned long n)
{
  t_statics     *statics;

  statics = STATICS;
  statics->error_callback("egc: ");
  log_uint(statics, n, 10);
  statics->error_callback("\n");
}
