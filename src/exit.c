/*
** exit.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 10:32:52 2016 antoine
** Last update Thu Mar 31 10:32:52 2016 antoine
*/

#include "private.h"

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
      LOG_UINT(STATICS->total_malloc_count);
      LOG_UINT(STATICS->total_free_count);
      LOG("egc_stop() Warning: total_malloc_count != total_free_count");
    }
  egc_heap_delete(STATICS->heaps);
}

void    egc_exit(int status)
{
  LOG("egc_exit()");
  egc_stop();
  exit(status);
}

void    egc_abort(void)
{
  EGC_IF_DEBUG(abort());
  EGC_IF_NOT_DEBUG(egc_log("egc_abort() called"));
  EGC_IF_NOT_DEBUG(exit(1));
}
