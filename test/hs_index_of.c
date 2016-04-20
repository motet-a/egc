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

void    test_suite_hs_index_of(void)
{
  ASSERT(hs_index_of(hs(""), hs("")) == 0);
  ASSERT(hs_index_of(hs("h"), hs("")) == 0);
  ASSERT(hs_index_of(hs(""), hs("abc")) == -1);
  ASSERT(hs_index_of(hs(" ab "), hs("abc")) == -1);
  ASSERT(hs_index_of(hs("abc "), hs("abc")) == 0);
  ASSERT(hs_index_of(hs(" abc"), hs("abc")) == 1);
}
