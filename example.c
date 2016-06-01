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

/*
** Reads a character from the standard input
**
** If the EOF is reach or an error occured, '\0' is returned.
*/
static char     read_char(void)
{
  char          c;

  if (read(STDIN_FILENO, &c, 1) != 1)
    return ('\0');
  return (c);
}

/*
** Reads a line from the standard input
**
** The line is terminated by a Ctrl+D or a '\n'.
*/
static t_hs     read_line(void)
{
  t_hs          line;
  char          c;

  line = hs_new_empty();
  while (1)
    {
      c = read_char();
      if (!c || c == '\n')
        break ;
      line = hs_concat_hs_char(line, c);
    }
  return (line);
}

static int              main2()
{
  t_hs                  name;

  egc_printf("What's your name? ");
  name = read_line();
  egc_printf("Hello %hs!\n", name);
  return (0);
}

int                     main()
{
  return (egc_run(0, NULL, NULL, main2));
}
