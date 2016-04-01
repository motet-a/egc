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
  egc_collect();
  if (STATICS->malloc_count != STATICS->free_count)
    {
      LOG("egc_stop() Warning: malloc_count != free_count");
    }
  egc_heap_delete(STATICS->heaps);
}

void    egc_exit(int status)
{
  egc_stop();
  /* TODO:  */
  exit(status);
}
