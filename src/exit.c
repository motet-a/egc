/*
** exit.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 10:32:52 2016 antoine
** Last update Thu Mar 31 10:32:52 2016 antoine
*/

#include "egc_private.h"

void    egc_stop()
{
  LOG("egc_stop() heap_count:");
  LOG_UINT(egc_get_heap_count());
  LOG("");
  LOG("egc_stop() collection_count:");
  LOG_UINT(STATICS->collection_count);
  LOG("");
  egc_collect();
  if (STATICS->total_malloc_count != STATICS->total_free_count)
    {
      LOG("egc_stop() Warning: total_malloc_count != total_free_count");
    }
  egc_heap_delete(STATICS->heaps);
}

static void     exit_impl(int status)
{
  exit(status);
}

void    egc_exit(int status)
{
  egc_stop();
  exit_impl(status);
}

void    egc_abort(void)
{
  egc_log("egc_abort() called");
  exit_impl(1);
}
