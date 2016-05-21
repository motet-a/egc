/*
** test.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Feb 23 00:12:28 2016 antoine
** Last update Tue Feb 23 00:12:28 2016 antoine
*/

#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "test.h"

void            fail_impl(const char *position)
{
  egc_printf("%s: Test failed\n", position);
  STATS->failed_test_count++;
}

void            assert_impl(int a, const char *position)
{
  if (!a)
    fail_impl(position);
  STATS->total_test_count++;
}

static void     run_tests(void)
{
  egc_collect();
  run_suites();
  egc_print_stats();
  egc_collect();
  egc_print_stats();
  egc_printf("%d tests, %d failures\n",
             STATS->total_test_count,
             STATS->failed_test_count);
  egc_exit(STATS->failed_test_count != 0);
}

/*
** There is a FAIL() at the end of this function to test
** the call to egc_exit() at the end of run_tests()
*/
static int      main2()
{
  t_test_stats  stats;

  stats.failed_test_count = 0;
  stats.total_test_count = 0;
  egc_set_statics(&stats, sizeof(t_test_stats));
  run_tests();
  FAIL();
  return (3);
}

int             main()
{
  return (egc_run(0, NULL, main2));
}
