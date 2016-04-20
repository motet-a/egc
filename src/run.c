/*
** run.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 10:34:36 2016 antoine
** Last update Thu Apr 14 10:34:36 2016 antoine
*/

#include "private.h"

static int      run(int argc,
                    char **argv,
                    t_egc_main_function aux_main)
{
  int           status;

  status = aux_main(argc, argv);
  return (status);
}

int             egc_run(int argc, char **argv, t_egc_main_function aux_main)
{
  int           status;
  t_statics     statics;

  egc_init(&statics);
  status = run(argc, argv, aux_main);
  egc_stop();
  return (status);
}
