/*
** hs_starts_with.c<test> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 15:51:20 2016 antoine
** Last update Mon Apr 18 15:51:20 2016 antoine
*/

#include "test.h"
#include "hs.h"

static void     test_starts_with(void)
{
  ASSERT(hs_starts_with(hs(""), hs("")));
  ASSERT(hs_starts_with(hs("abc"), hs("")));
  ASSERT(hs_starts_with(hs("abc"), hs("a")));
  ASSERT(hs_starts_with(hs("abc"), hs("abc")));
  ASSERT(!hs_starts_with(hs(""), hs("a")));
  ASSERT(!hs_starts_with(hs("ab"), hs("abc")));
  ASSERT(!hs_starts_with(hs("abc"), hs("b")));
}

static void     test_ends_with(void)
{
  ASSERT(hs_ends_with(hs(""), hs("")));
  ASSERT(hs_ends_with(hs("abc"), hs("")));
  ASSERT(hs_ends_with(hs("abc"), hs("c")));
  ASSERT(!hs_ends_with(hs("a"), hs("aa")));
}

void    test_suite_hs_starts_with(void)
{
  test_starts_with();
  test_ends_with();
}
