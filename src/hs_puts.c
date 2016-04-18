/*
** hs_puts.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Apr 15 12:38:17 2016 antoine
** Last update Fri Apr 15 12:38:17 2016 antoine
*/

#include <unistd.h>
#include "../include/egc.h"

int     hs_puts(t_hs hs)
{
  return (hs_puts_file(hs, STDOUT_FILENO));
}

int     hs_puts_err(t_hs hs)
{
  return (hs_puts_file(hs, STDERR_FILENO));
}

int     hs_puts_file(t_hs hs, int output_file)
{
  int   a;
  int   b;

  a = hs_print_file(hs, output_file);
  if (a < 0)
    return (a);
  b = write(output_file, "\n", 1);
  if (b < 0)
    return (b);
  return (a + b);
}
