/*
** hs_slice.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 16:48:52 2016 antoine
** Last update Sat Apr 16 16:48:52 2016 antoine
*/

#include "../include/egc.h"
#include "test.h"

void    test_suite_hs_slice(void)
{
  ASSERT(hs_equals(hs_slice(hs("abc"), 0, 0), hs("")));
  ASSERT(hs_equals(hs_slice(hs("abc"), 0, 1), hs("a")));
  ASSERT(hs_equals(hs_slice(hs("abc"), 0, 3), hs("abc")));
  ASSERT(hs_equals(hs_slice(hs("abc"), 0, -1), hs("ab")));
  ASSERT(hs_equals(hs_slice(hs("abc"), 0, -2), hs("a")));
  ASSERT(hs_equals(hs_slice(hs("abc"), 1, -1), hs("b")));
  ASSERT(hs_equals(hs_slice(hs("abc"), -2, -1), hs("b")));
}
