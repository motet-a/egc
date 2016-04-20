/*
** set_to_zero.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 22:44:27 2016 antoine
** Last update Sat Apr 16 22:44:27 2016 antoine
*/

#include "test.h"
#include "utils.h"
#include "../src/private.h"

static void     set_to_1(char *buffer, size_t length)
{
  while (length--)
    {
      buffer[length] = (char)1;
    }
}

void            test_suite_set_to_zero(void)
{
  char          buffer[32];

  {
    set_to_1(buffer, sizeof(buffer));
    egc_set_to_zero(buffer, sizeof(buffer));
    ASSERT(is_zero(buffer, sizeof(buffer)));
  }
  {
    set_to_1(buffer, sizeof(buffer));
    egc_set_to_zero(buffer + 1, sizeof(buffer) - 1);
    ASSERT(is_zero(buffer + 1, sizeof(buffer) - 1));
    ASSERT(buffer[0] == 1);
  }
  {
    set_to_1(buffer, sizeof(buffer));
    egc_set_to_zero(buffer + 1, sizeof(buffer) - 2);
    ASSERT(is_zero(buffer + 1, sizeof(buffer) - 2));
    ASSERT(buffer[0] == 1);
    ASSERT(buffer[sizeof(buffer) - 1] == 1);
  }
}
