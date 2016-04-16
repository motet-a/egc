/*
** test.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 20:01:52 2016 antoine
** Last update Wed Mar  9 18:54:57 2016 Valentin Pichard
*/

#ifndef TEST_H
# define TEST_H

# include "../include/egc.h"

# define STRINGIFY_(s)          #s
# define STRINGIFY(s)           STRINGIFY_(s)

# define TEST_GET_POSITION()    (__FILE__ ":" STRINGIFY(__LINE__))

void                    fail_impl(const char *position);
void                    assert_impl(int a, const char *position);

# define FAIL()         fail_impl(TEST_GET_POSITION())
# define ASSERT(a)      assert_impl(a, TEST_GET_POSITION())

typedef struct          s_test_stats
{
  int                   failed_test_count;
  int                   total_test_count;
}                       t_test_stats;

# define STATS          ((t_test_stats *)egc_get_statics())

void    test_suite_glist(void);
void    test_suite_malloc(void);
void    test_suite_hs_format(void);
void    test_suite_hs_slice(void);
void    test_suite_hs_split(void);

#endif /* TEST_H */
