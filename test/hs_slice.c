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
  ASSERT(hs_equals_str(hs_slice_str("abc", 0, 0), ""));
  ASSERT(hs_equals_str(hs_slice_str("abc", 0, 1), "a"));
  ASSERT(hs_equals_str(hs_slice_str("abc", 0, 3), "abc"));
  ASSERT(hs_equals_str(hs_slice_str("abc", 0, -1), "ab"));
  ASSERT(hs_equals_str(hs_slice_str("abc", 0, -2), "a"));
}
