/*
** glist.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 15:00:41 2016 antoine
** Last update Sat Apr 16 15:00:41 2016 antoine
*/

#include "../src/egc_private.h"
#include "test.h"

static void     test_append_and_size(void)
{
  t_glist_int   l;

  l = glist_int_new();
  ASSERT(glist_int_length(&l) == 0);
  glist_int_append(&l, 0);
  ASSERT(glist_int_length(&l) == 1);
  ASSERT(glist_int_get(&l, 0) == 0);
  glist_int_append(&l, 1);
  glist_int_append(&l, 2);
  ASSERT(glist_int_length(&l) == 3);
  ASSERT(glist_int_get(&l, 0) == 0);
  ASSERT(glist_int_get(&l, 1) == 1);
  ASSERT(glist_int_get(&l, 2) == 2);
}

static void     test_add(void)
{
  t_glist_hs    a;
  t_glist_hs    b;
  t_glist_hs    c;

  a = hs_split_str_str("a b", "");
  b = hs_split_str_str("c d e", "");
  ASSERT(glist_hs_length(&a) == 2);
  ASSERT(glist_hs_length(&b) == 3);
  c = glist_hs_add(&a, &b);
  ASSERT(glist_hs_length(&c) == 5);
  ASSERT(hs_equals_str(hs_join_str_hs("-", &c), "a-b-c-d-e"));
}

static void     test_glist_hs(void)
{
  t_glist_hs    l;
  t_hs          s;

  l = glist_hs_new();

  s = hs_new_from_str("a");
  glist_hs_append(&l, s);
  s = hs_new_from_str("b");
  glist_hs_append(&l, s);
  s = hs_new_from_str("c");
  glist_hs_append(&l, s);
  ASSERT(hs_equals_str(glist_hs_get(&l, 0), "a"));
  ASSERT(hs_equals_str(glist_hs_get(&l, 1), "b"));
  ASSERT(hs_equals_str(glist_hs_get(&l, 2), "c"));
}

void            test_suite_glist(void)
{
  test_append_and_size();
  test_add();
  test_glist_hs();
}
