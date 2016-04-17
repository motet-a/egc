/*
** hs_split.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 22:36:32 2016 antoine
** Last update Sat Apr 16 22:36:32 2016 antoine
*/

#include "../src/egc_private.h"
#include "test.h"

static void     test_0(void)
{
  t_glist_hs    l;

  l = hs_split_str_str("hello", "");
  ASSERT(glist_hs_size(&l) == 1);
  ASSERT(hs_equals_str(glist_hs_get(&l, 0), "hello"));
  l = hs_split_str_str("a", ",");
  ASSERT(glist_hs_size(&l) == 1);
  ASSERT(hs_equals_str(glist_hs_get(&l, 0), "a"));
}

static void     test_1(void)
{
  t_glist_hs    l;

  l = hs_split_str_str("a,b", ",");
  egc_debug_lock_on(l.items);
  ASSERT(glist_hs_size(&l) == 2);
  egc_debug_lock_on(glist_hs_get(&l, 0).chars);
  egc_debug_lock_on(glist_hs_get(&l, 1).chars);
  ASSERT(hs_equals_str(glist_hs_get(&l, 0), "a"));
  ASSERT(hs_equals_str(glist_hs_get(&l, 1), "b"));
  egc_debug_lock_off(glist_hs_get(&l, 0).chars);
  egc_debug_lock_off(glist_hs_get(&l, 1).chars);
  egc_debug_lock_off(l.items);
}

static void     test_2(void)
{
  t_glist_hs    l;

  l = hs_split_str_str(",", ",");
  ASSERT(glist_hs_size(&l) == 2);
  ASSERT(hs_equals_str(glist_hs_get(&l, 0), ""));
}

static void     test_join(void)
{
  t_glist_hs    l;

  l = hs_split_str_str("here,comes,the,sun", ",");
  ASSERT(hs_equals_str(hs_join_str_hs("-", &l), "here-comes-the-sun"));
}

void            test_suite_hs_split(void)
{
  test_0();
  test_1();
  test_2();
  test_join();
}
