/*
** main.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:38:51 2016 antoine
** Last update Wed Mar 30 18:38:51 2016 antoine
*/

#include "test.h"
#include "../include/egc.h"

static void             test0(void)
{
  int                   i;

  i = -1;
  while (++i < 1000)
    {
      egc_malloc(i);
    }
}

static void             test(void)
{
  void                  *data;

  data = egc_malloc(6);
  egc_malloc(0);
  egc_malloc(1024 * 1024 * 10);
  egc_malloc(12);
  if (!is_zero(data, 6))
    {
      print_error("egc_malloc() must initialize data\n");
      return ;
    }
  egc_strcpy(data, "hello");
  if (!string_equals(data, "hello"))
    {
      print_error("test() failure\n");
      return ;
    }
  egc_malloc(1024 * 1024 * 2);
  egc_malloc(6);
  egc_malloc(9);
}

static void             test1(void)
{
  t_hs                  hs;

  hs = hs_format("If you see %hs %s, it works.",
            hs_new_from_str("this"), "message");
  egc_collect();
  egc_printf("%hs\n", hs);
  egc_printf("%d %d %u %x %p\n", 123, -123, -128, 0xdeadbeef, hs.chars);
  printf("%d %d %u %x %p\n", 123, -123, -128, 0xdeadbeef, hs.chars);
}

int                     main(void)
{
  t_egc_private_data    private_data;

  egc_start(&private_data, &print_error, NULL, 0);
  test0();
  test();
  test1();
  egc_stop();
  return (0);
}
