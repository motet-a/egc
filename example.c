/*
** example.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Apr 12 22:45:01 2016 antoine
** Last update Tue Apr 12 22:45:01 2016 antoine
*/

#include <unistd.h>
#include "include/egc.h"

static char     read_char(void)
{
  char          c;

  if (read(STDIN_FILENO, &c, 1) != 1)
    return ('\0');
  return c;
}

static t_hs     read_line(void)
{
  t_hs          line;
  char          c;

  line = hs_new_empty();
  while (1)
    {
      c = read_char();
      if (!c || c == '\n')
        break;
      line = hs_concat_hs_char(line, c);
    }
  return (line);
}

static void             whats_your_name(void)
{
  t_hs                  name;

  egc_printf("What's your name? ");
  name = read_line();
  egc_printf("Hello %hs!\n", name);
}

int                     main()
{
  t_egc_private_data    private_data;

  egc_start(&private_data);
  whats_your_name();
  egc_stop();
}
