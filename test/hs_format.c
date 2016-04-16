/*
** hs_format.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 22:35:06 2016 antoine
** Last update Sat Apr 16 22:35:06 2016 antoine
*/

#include "test.h"

void    test_suite_hs_format(void)
{
  ASSERT(hs_equals_str(hs_format(""), ""));
  ASSERT(hs_equals_str(hs_format("hello"), "hello"));
  ASSERT(hs_equals_str(hs_format("%d", -1), "-1"));
  ASSERT(hs_equals_str(hs_format("%d", 123), "123"));
  ASSERT(hs_equals_str(hs_format("%x", 0xdeadbeef), "deadbeef"));
  ASSERT(hs_equals_str(hs_format("%s", "a"), "a"));
  ASSERT(hs_equals_str(hs_format("%hs", hs_new_from_str("a")), "a"));
}
