/*
** hs_strip.c<test> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Apr 20 22:30:36 2016 antoine
** Last update Wed Apr 20 22:30:36 2016 antoine
*/

#include "test.h"

void    test_suite_hs_strip(void)
{
  ASSERT(hs_equals(hs_lstrip(hs("")), hs("")));
  ASSERT(hs_equals(hs_lstrip(hs("abc")), hs("abc")));
  ASSERT(hs_equals(hs_lstrip(hs("\t\v \r\nabc")), hs("abc")));
  ASSERT(hs_equals(hs_rstrip(hs("")), hs("")));
  ASSERT(hs_equals(hs_rstrip(hs("abc")), hs("abc")));
  ASSERT(hs_equals(hs_rstrip(hs("abc  ")), hs("abc")));
  ASSERT(hs_equals(hs_strip(hs("")), hs("")));
  ASSERT(hs_equals(hs_strip(hs("abc")), hs("abc")));
  ASSERT(hs_equals(hs_strip(hs("  abc  ")), hs("abc")));
}
