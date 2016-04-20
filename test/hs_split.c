/*
** hs_split.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 22:36:32 2016 antoine
** Last update Sat Apr 16 22:36:32 2016 antoine
*/

#include "../src/private.h"
#include "test.h"

static void     test_0(void)
{
  t_glist_hs    l;

  l = hs_split(hs("hello"), hs(""));
  ASSERT(glist_hs_length(&l) == 1);
  ASSERT(hs_equals(glist_hs_get(&l, 0), hs("hello")));
  l = hs_split(hs("a"), hs(","));
  ASSERT(glist_hs_length(&l) == 1);
  ASSERT(hs_equals(glist_hs_get(&l, 0), hs("a")));
}

static void     test_1(void)
{
  t_glist_hs    l;

  l = hs_split(hs("a,b"), hs(","));
  egc_debug_lock_on(l._items);
  ASSERT(glist_hs_length(&l) == 2);
  egc_debug_lock_on(glist_hs_get(&l, 0)._chars);
  egc_debug_lock_on(glist_hs_get(&l, 1)._chars);
  ASSERT(hs_equals(glist_hs_get(&l, 0), hs("a")));
  ASSERT(hs_equals(glist_hs_get(&l, 1), hs("b")));
  egc_debug_lock_off(glist_hs_get(&l, 0)._chars);
  egc_debug_lock_off(glist_hs_get(&l, 1)._chars);
  egc_debug_lock_off(l._items);
}

static void     test_2(void)
{
  t_glist_hs    l;

  l = hs_split(hs(","), hs(","));
  ASSERT(glist_hs_length(&l) == 2);
  ASSERT(hs_equals(glist_hs_get(&l, 0), hs("")));
}

static void     test_join(void)
{
  t_glist_hs    l;

  l = hs_split(hs("here,comes,the,sun"), hs(","));
  ASSERT(hs_equals(hs_join(hs("-"), &l), hs("here-comes-the-sun")));
}

void            test_suite_hs_split(void)
{
  test_0();
  test_1();
  test_2();
  test_join();
}
