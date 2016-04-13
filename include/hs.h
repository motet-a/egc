/*
** hs.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 08:57:05 2016 antoine
** Last update Sat Apr  2 08:57:05 2016 antoine
*/

#ifndef HS_H
# define HS_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct  s_hs
{
  size_t        length;
  char          *chars;
}               t_hs;

t_hs    hs_new_empty(void);
t_hs    hs_new_from_str(const char *hsing);
t_hs    hs_new_from_char(char c);
t_hs    hs_new_from_length(size_t length, const char *chars);

/*
** Use these functions to convert integers to a new
** heap string
*/
t_hs    hs_new_int(long n);
t_hs    hs_new_int_base(long n, unsigned base);
t_hs    hs_new_uint(unsigned long n);
t_hs    hs_new_uint_base(unsigned long n, unsigned base);

/*
** Concatenates left and right
*/
t_hs    hs_concat(t_hs left, t_hs right);

t_hs    hs_concat_hs_str(t_hs left, const char *right);
t_hs    hs_concat_str_hs(const char *left, t_hs right);
t_hs    hs_concat_str_str(const char *left, const char *right);

t_hs    hs_concat_hs_char(t_hs left, char right);
t_hs    hs_concat_char_hs(char left, t_hs right);

/*
** Creates a new t_hs from the given format and arguments
**
** The format of the format string is the same as the printf() one.
*/
t_hs    hs_format(const char *format, ...);
t_hs    hs_vformat(const char *format, va_list list);

t_hs    hs_repr(t_hs hs);
t_hs    hs_escape_nuls(t_hs hs);

/*
** Returns a garbage-collected NUL-terminated string
*/
char    *hs_to_str(t_hs hs);

/*
** Prints a heap string to the standard output
*/
int     hs_print(t_hs hs);
int     hs_print_err(t_hs hs);
int     hs_print_file(t_hs hs, int output_file);

#endif /* HS_H */
