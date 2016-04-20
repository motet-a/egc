/*
** malloc.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 01:16:30 2016 antoine
** Last update Thu Apr 14 01:16:30 2016 antoine
*/

#include "utils.h"
#include "test.h"
#include "../src/private.h"

static void     check_allocated_block(void *data, size_t size)
{
  t_block       *block;

  if (!data)
    FAIL();
  if (!is_zero(data, size))
    FAIL();
  block = data - sizeof(t_block);
  if (block->size < size)
    FAIL();
  if (size > 0)
    ((char *)data)[0] = 'a';
  if (size > 1)
    ((char *)data)[size - 1] = 'b';
}

static void     test_malloc_0(void)
{
  int           i;
  void          *data;

  i = -1;
  while (++i < 1000)
    {
      data = egc_malloc(i);
      check_allocated_block(data, i);
    }
  ASSERT(1);
}

static void     test_malloc_atomic(void)
{
  size_t        size;
  void          *data;

  size = 123;
  data = egc_malloc_atomic(size);
  check_allocated_block(data, size);
  ASSERT(1);
}

static void     test_realloc(void)
{
  char          *data;

  data = egc_realloc(NULL, 10);
  check_allocated_block(data, 10);
  data[0] = 'a';
  data = egc_realloc(data, 1);
  ASSERT(data[0] == 'a');
  data = egc_realloc(data, 1);
  ASSERT(data[0] == 'a');
  data = egc_realloc(data, 0);
  data = egc_realloc(data, 1);
  ASSERT(!data[0]);
  data[0] = 'a';
  data = egc_realloc(data, 100);
  ASSERT(data[0] == 'a');
  ASSERT(is_zero(data + 1, 99));
  data[99] = 'b';
  data = egc_realloc(data, 100);
  ASSERT(data[0] == 'a');
  ASSERT(is_zero(data + 1, 98));
  ASSERT(data[99] == 'b');
}

void            test_suite_malloc(void)
{
  test_malloc_0();
  test_malloc_atomic();
  test_realloc();
}
