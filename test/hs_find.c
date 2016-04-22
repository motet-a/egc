/*
** hs_index_of.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 20:13:55 2016 antoine
** Last update Wed Apr 20 20:13:55 2016 antoine
*/

#include "test.h"

void    test_suite_hs_find(void)
{
  ASSERT(hs_find(hs(""), hs(""), 0) == 0);
  ASSERT(hs_find(hs("h"), hs(""), 0) == 0);
  ASSERT(hs_find(hs(""), hs("abc"), 0) == -1);
  ASSERT(hs_find(hs(" ab "), hs("abc"), 0) == -1);
  ASSERT(hs_find(hs("abc "), hs("abc"), 0) == 0);
  ASSERT(hs_find(hs(" abc"), hs("abc"), 0) == 1);
}
