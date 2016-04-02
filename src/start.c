/*
** init.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:06:49 2016 antoine
** Last update Wed Mar 30 18:06:49 2016 antoine
*/

#include "egc_private.h"

t_statics       *init_statics(t_egc_private_data *private_data)
{
  t_statics     *statics;

#ifdef EGC_DEBUG
  statics = &g_egc_private_statics;
#else
  statics = (t_statics *)private_data;
#endif
  statics->magic_number = MAGIC_NUMBER;
  statics->magic_number++;
  statics->stack_bottom = (void *)private_data;
  return statics;
}

void            egc_start(t_egc_private_data *private_data,
                          t_egc_error_callback error_callback,
                          void *user_statics,
                          size_t user_statics_size)
{
  t_statics     *statics;

  statics = init_statics(private_data);
  statics->error_callback = error_callback;
  statics->user_statics = user_statics;
  statics->user_statics_size = user_statics_size;
  statics->malloc_count = 0;
  statics->free_count = 0;
  statics->heap_size = 1024;
  statics->heaps = NULL;
  statics->heaps = egc_heap_new(statics->heap_size, NULL);
  if (STATICS != statics)
    {
      error_callback("egc_start(): Internal error\n");
      exit(-1);
    }
  LOG("egc_start() statics:");
  LOG_POINTER(private_data);
  LOG("");
}
