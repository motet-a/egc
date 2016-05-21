/*
** run_suites.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat May 21 10:01:26 2016 antoine
** Last update Sat May 21 10:01:26 2016 antoine
*/

#include "test.h"

void    run_suites(void)
{
  test_suite_statics();
  test_suite_set_to_zero();
  STATS;
  test_suite_malloc();
  STATS;
  test_suite_glist();
  STATS;
  test_suite_hs_get();
  test_suite_hs_format();
  test_suite_hs_slice();
  test_suite_hs_split();
  test_suite_hs_starts_with();
  test_suite_hs_find();
  test_suite_hs_strip();
  test_suite_hs_to_str();
}
