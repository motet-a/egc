/*
** init.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 18:06:49 2016 antoine
** Last update Wed Mar 30 18:06:49 2016 antoine
*/

#include <unistd.h>
#include "egc_private.h"

static t_statics        *init_statics(t_egc_private_data *private_data)
{
  t_statics             *statics;

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

static void     print_string(const char *string)
{
  while (*string)
    {
      write(STDERR_FILENO, string, 1);
      string++;
    }
}

void            egc_start(t_egc_private_data *private_data)
{
  t_statics     *statics;

  statics = init_statics(private_data);
  statics->error_callback = &print_string;
  statics->user_statics = NULL;
  statics->user_statics_size = 0;
  statics->malloc_count = 0;
  statics->free_count = 0;
  statics->total_malloc_count = 0;
  statics->total_free_count = 0;
  statics->collection_count = 0;
  statics->heap_size = 1024;
  statics->heaps = NULL;
  statics->heaps = egc_heap_new(statics->heap_size, NULL);
  if (STATICS != statics)
    {
      print_string("egc_start(): Internal error\n");
      exit(-1);
    }
  LOG("egc_start() statics:");
  LOG_POINTER(private_data);
  LOG("");
}

void            egc_set_statics(void *statics, size_t statics_size)
{
  STATICS->user_statics = statics;
  STATICS->user_statics_size = statics_size;
}

void            egc_set_error_callback(t_egc_error_callback error_callback)
{
  STATICS->error_callback = error_callback;
}
