/*
** hs_print.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 11:21:23 2016 antoine
** Last update Sat Apr  2 11:21:23 2016 antoine
*/

#include <unistd.h>
#include "../include/egc.h"

int     hs_print(t_hs hs)
{
  return (hs_print_file(hs, STDOUT_FILENO));
}

int     hs_print_err(t_hs hs)
{
  return (hs_print_file(hs, STDERR_FILENO));
}

int     hs_print_file(t_hs hs, int output_file)
{
  return (write(output_file, hs._chars, hs._length));
}
