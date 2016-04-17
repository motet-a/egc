/*
** statics.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sun Apr 17 08:12:19 2016 antoine
** Last update Sun Apr 17 08:12:19 2016 antoine
*/

#include "test.h"
#include "../include/egc.h"

/*
** We cannot perform any ASSERT() if the statics pointer is not
** pointing to a t_stats
*/
void            test_suite_statics(void)
{
  int           n;
  void          *old_statics;
  size_t        old_size;

  old_statics = egc_get_statics();
  old_size = egc_get_statics_size();
  egc_set_statics(&n, 0);
  egc_set_statics(old_statics, old_size);
  ASSERT(egc_get_statics() == old_statics);
  ASSERT(egc_get_statics_size() == old_size);
}
