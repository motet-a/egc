/*
** hs_to_str.c<test> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 21 16:42:06 2016 antoine
** Last update Thu Apr 21 16:42:06 2016 antoine
*/

#include "test.h"

static int      str_equals(const char *a, const char *b)
{
  while (*a == *b)
    {
      if (!*a)
        return (1);
      a++;
      b++;
    }
  return (0);
}

static void     test_hs_to_str(void)
{
  ASSERT(str_equals(hs_to_str(hs("")), ""));
  ASSERT(str_equals(hs_to_str(hs("abc")), "abc"));
  ASSERT(str_equals(hs_to_str(hs("a\\0c")), "a\\0c"));
}

void    test_suite_hs_to_str(void)
{
  t_hs  s;

  ASSERT(hs_equals(hs_escape_nuls(hs("abc")), hs("abc")));
  s = hs_new_from_n_chars(3, "a\0c");
  ASSERT(hs_equals(hs_escape_nuls(s), hs("a\\0c")));
  test_hs_to_str();
}
