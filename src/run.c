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
                    char **env,
                    t_egc_main_function aux)
{
  int           status;

  status = aux(argc, argv, env);
  return (status);
}

int             egc_run(int argc,
                        char **argv,
                        char **env,
                        t_egc_main_function aux)
{
  int           status;
  t_statics     statics;

  egc_init(&statics);
  status = run(argc, argv, env, aux);
  egc_stop();
  return (status);
}
