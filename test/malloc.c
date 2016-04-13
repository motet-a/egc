/*
** malloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 01:16:30 2016 antoine
** Last update Thu Apr 14 01:16:30 2016 antoine
*/

#include "test.h"

static void     test_malloc_0(void)
{
  int           i;

  i = -1;
  while (++i < 1000)
    {
      if (!egc_malloc(i))
        FAIL();
    }
  ASSERT(1);
}

void            test_suite_malloc(void)
{
  test_malloc_0();
}
