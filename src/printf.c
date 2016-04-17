/*
** printf.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 10:36:49 2016 antoine
** Last update Sat Apr  2 10:36:49 2016 antoine
*/

#include <unistd.h>
#include "../include/egc.h"

int             egc_printf(const char *format, ...)
{
  va_list       list;
  int           r;

  va_start(list, format);
  r = egc_vprintf(format, list);
  va_end(list);
  return (r);
}

int             egc_fprintf(int file_descriptor, const char *format, ...)
{
  va_list       list;
  int           r;

  va_start(list, format);
  r = egc_vfprintf(file_descriptor, format, list);
  va_end(list);
  return (r);
}

int             egc_vprintf(const char *format, va_list list)
{
  return (egc_vfprintf(STDOUT_FILENO, format, list));
}

int             egc_vfprintf(int file, const char *format, va_list list)
{
  t_hs          hs;

  hs = hs_vformat(format, list);
  if (hs_print_file(hs, file) != (ssize_t)hs.length)
    return (-1);
  return ((int)hs.length);
}
