/*
** glist.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 15:00:41 2016 antoine
** Last update Sat Apr 16 15:00:41 2016 antoine
*/

#include "../include/egc.h"
#include "test.h"

void            test_suite_glist(void)
{
  t_glist_int   l;

  l = glist_int_new();
  ASSERT(glist_int_size(&l) == 0);
  glist_int_append(&l, 0);
  ASSERT(glist_int_size(&l) == 1);
  glist_int_append(&l, 1);
  glist_int_append(&l, 2);
  ASSERT(glist_int_size(&l) == 3);
}
