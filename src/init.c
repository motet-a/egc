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
#include "private.h"

static t_statics        *init_statics(t_statics *statics)
{
  void                  *stack_bottom;

  stack_bottom = statics;
  statics->magic_number = MAGIC_NUMBER;
  statics->magic_number++;
#ifdef EGC_DEBUG
  statics = &g_egc_private_statics;
#endif
  statics->magic_number = MAGIC_NUMBER;
  statics->magic_number++;
  statics->stack_bottom = stack_bottom;
  return (statics);
}

static void     print_string(const char *string)
{
  while (*string)
    {
      write(STDERR_FILENO, string, 1);
      string++;
    }
}

void            egc_init(t_statics *statics)
{
  statics = init_statics(statics);
  statics->error_callback = &print_string;
  statics->user_statics = NULL;
  statics->user_statics_size = 0;
  statics->malloc_count = 0;
  statics->free_count = 0;
  statics->total_malloc_count = 0;
  statics->total_free_count = 0;
  statics->collection_count = 0;
  statics->heap_size = 10 * 1024;
  statics->heaps = NULL;
  statics->heaps = egc_heap_new(statics->heap_size, NULL);
  if (STATICS != statics)
    {
      print_string("egc_init(): Internal error\n");
      egc_abort();
    }
  LOG("egc_init() statics:");
  LOG_POINTER(statics);
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
