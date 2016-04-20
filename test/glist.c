/*
** glist.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 15:00:41 2016 antoine
** Last update Sat Apr 16 15:00:41 2016 antoine
*/

#include "../include/egc.h"
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
  t_hs          s;

  a = hs_split(hs("a b"), hs(""));
  b = hs_split(hs("c d e"), hs(""));
  ASSERT(glist_hs_length(&a) == 2);
  ASSERT(glist_hs_length(&b) == 3);
  c = glist_hs_add(&a, &b);
  ASSERT(glist_hs_length(&c) == 5);
  s = hs_join(hs("-"), &c);
  ASSERT(hs_equals(s, hs("a-b-c-d-e")));
}

static void     test_glist_hs(void)
{
  t_glist_hs    l;

  l = glist_hs_new();

  glist_hs_append(&l, hs("a"));
  glist_hs_append(&l, hs("b"));
  glist_hs_append(&l, hs("c"));
  ASSERT(hs_equals(glist_hs_get(&l, 0), hs("a")));
  ASSERT(hs_equals(glist_hs_get(&l, 1), hs("b")));
  ASSERT(hs_equals(glist_hs_get(&l, 2), hs("c")));
}

void            test_suite_glist(void)
{
  test_append_and_size();
  test_add();
  test_glist_hs();
}
