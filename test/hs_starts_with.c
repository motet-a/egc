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

void    test_suite_hs_starts_with(void)
{
  ASSERT(hs_starts_with_str(hs_new_from_str(""), ""));
  ASSERT(hs_starts_with_str(hs_new_from_str("abc"), ""));
  ASSERT(hs_starts_with_str(hs_new_from_str("abc"), "a"));
  ASSERT(hs_starts_with_str(hs_new_from_str("abc"), "abc"));
  ASSERT(!hs_starts_with_str(hs_new_from_str(""), "a"));
  ASSERT(!hs_starts_with_str(hs_new_from_str("ab"), "abc"));
  ASSERT(!hs_starts_with_str(hs_new_from_str("abc"), "b"));
}
