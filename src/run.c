/*
** run.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 10:34:36 2016 antoine
** Last update Thu Apr 14 10:34:36 2016 antoine
*/

#include "egc_private.h"

static int      run(int argc,
                    char **argv,
                    t_egc_main_function aux_main,
                    t_statics **statics_ptr_ptr)
{
  *statics_ptr_ptr = STATICS;
  STATICS->return_address = __builtin_return_address(0);
  return (aux_main(argc, argv));
}

int             egc_run(int argc, char **argv, t_egc_main_function aux_main)
{
  int           status;
  t_statics     statics;
  t_statics     *statics_ptr;

  egc_init(&statics);
  status = run(argc, argv, aux_main, &statics_ptr);
  if (statics_ptr->exited)
    status = statics_ptr->exit_status;
  egc_stop();
  return (status);
}
