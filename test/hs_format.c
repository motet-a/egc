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
  ASSERT(hs_equals(hs_format(""), hs("")));
  ASSERT(hs_equals(hs_format("hello"), hs("hello")));
  ASSERT(hs_equals(hs_format("%%"), hs("%")));
  ASSERT(hs_equals(hs_format("%c", 'z'), hs("z")));
  ASSERT(hs_equals(hs_format("%hhu", 0xffff), hs("255")));
  ASSERT(hs_equals(hs_format("%d", -1), hs("-1")));
  ASSERT(hs_equals(hs_format("%d", 123), hs("123")));
  ASSERT(hs_equals(hs_format("%x", 0xdeadbeef), hs("deadbeef")));
  ASSERT(hs_equals(hs_format("%s", "a"), hs("a")));
  ASSERT(hs_equals(hs_format("%hs", hs("x")), hs("x")));
}
