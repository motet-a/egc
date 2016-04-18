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

/*
** Don't access directly the members of this structure
*/
typedef struct  s_hs
{
  size_t        _length;
  char          *_chars;
}               t_hs;

t_hs    hs_new_empty(void);
t_hs    hs_new_from_str(const char *hsing);
t_hs    hs_new_from_char(char c);
t_hs    hs_new_from_n_chars(size_t n, const char *chars);

/*
** Use these functions to convert integers to a new
** heap string
*/
t_hs    hs_new_from_int(long n);
t_hs    hs_new_from_int_base(long n, unsigned base);
t_hs    hs_new_from_uint(unsigned long n);
t_hs    hs_new_from_uint_base(unsigned long n, unsigned base);

size_t  hs_length(t_hs hs);

/*
** Returns the character at the given index
**
** If hs is empty, returns '\0'.
*/
char    hs_get(t_hs hs, int index);

/*
** Concatenates left and right to a new heap string
*/
t_hs    hs_concat(t_hs left, t_hs right);

t_hs    hs_concat_hs_str(t_hs left, const char *right);
t_hs    hs_concat_str_hs(const char *left, t_hs right);
t_hs    hs_concat_str_str(const char *left, const char *right);

t_hs    hs_concat_hs_char(t_hs left, char right);
t_hs    hs_concat_char_hs(char left, t_hs right);

int     hs_equals(t_hs a, t_hs b);
int     hs_equals_str(t_hs a, const char *b);

/*
** Creates a new t_hs from the given format and arguments
**
** The format of the format string is the same as the printf() one.
*/
t_hs    hs_format(const char *format, ...);
t_hs    hs_vformat(const char *format, va_list list);
t_hs    hs_format_directive(const char **format_pointer, va_list list);

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

/*
** Like hs_print_*() functions, but prints a "\n" at the end
*/
int     hs_puts(t_hs hs);
int     hs_puts_err(t_hs hs);
int     hs_puts_file(t_hs hs, int output_file);

/*
** Returns the lowest index in hs where the substring is found
**
** Returns -1 on failure.
*/
int     hs_index_of(t_hs hs, t_hs substring);
int     hs_index_of_str(t_hs hs, const char *substring);
int     hs_index_of_char(t_hs hs, char c);

t_hs    hs_slice(t_hs hs, int start_index, int end_index);
t_hs    hs_slice_str(const char *string, int start_index, int end_index);

/*
** Forward declarations
*/
struct                          s_glist_hs;
typedef struct s_glist_hs       t_glist_hs_;

t_glist_hs_     hs_split(t_hs hs, t_hs separator);
t_glist_hs_     hs_split_hs_str(t_hs hs, const char *separator);
t_glist_hs_     hs_split_str_str(const char *str, const char *separator);

t_hs    hs_join(t_hs separator, const t_glist_hs_ *strings);
t_hs    hs_join_str_hs(const char *separator, const t_glist_hs_ *strings);

int     hs_get_real_index(t_hs hs, int index);

#endif /* HS_H */
