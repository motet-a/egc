/*
** hs_get.c<test> for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Mon Apr 18 10:44:34 2016 antoine
** Last update Mon Apr 18 10:44:34 2016 antoine
*/

#include "test.h"

void    test_suite_hs_get(void)
{
  ASSERT(hs_get(hs_new_empty(), 0) == '\0');
  ASSERT(hs_get(hs_new_empty(), 1) == '\0');
  ASSERT(hs_get(hs_new_empty(), -1) == '\0');
  ASSERT(hs_get(hs_new_from_str("abc"), -1) == 'a');
  ASSERT(hs_get(hs_new_from_str("abc"), 0) == 'a');
  ASSERT(hs_get(hs_new_from_str("abc"), 1) == 'b');
  ASSERT(hs_get(hs_new_from_str("abc"), 2) == 'c');
  ASSERT(hs_get(hs_new_from_str("abc"), 3) == 'c');
  ASSERT(hs_get(hs_new_from_str("abc"), 4) == 'c');
}
