/*
** hs_get.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 10:41:12 2016 antoine
** Last update Mon Apr 18 10:41:12 2016 antoine
*/

#include "../include/hs.h"

char    hs_get(t_hs hs, int index)
{
  if (index < 0)
    index = 0;
  if (hs._length == 0)
    return ('\0');
  if (index >= (int)hs._length)
    index = hs._length - 1;
  return (hs._chars[index]);
}
