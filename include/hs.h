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

/*
** Returns an empty t_hs
*/
t_hs    hs_new_empty(void);

/*
** Converts a C string to a t_hs
*/
t_hs    hs(const char *c_string);

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

size_t  hs_length(t_hs string);

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

t_hs    hs_concat_hs_char(t_hs left, char right);
t_hs    hs_concat_char_hs(char left, t_hs right);

int     hs_equals(t_hs a, t_hs b);

int     hs_starts_with(t_hs string, t_hs prefix);
int     hs_ends_with(t_hs string, t_hs postfix);

/*
** Creates a new t_hs from the given format and arguments
**
** The format of the format string is the same as the printf() one.
*/
t_hs    hs_format(const char *format, ...);
t_hs    hs_vformat(const char *format, va_list list);
t_hs    hs_format_directive(const char **format_pointer, va_list list);

t_hs    hs_repr(t_hs string);

/*
** Returns the given string with NULs replaced by '\0'
*/
t_hs    hs_escape_nuls(t_hs string);

/*
** Returns a garbage-collected NUL-terminated string
**
** The NULs of the given string are escaped with '\0'.
*/
char    *hs_to_str(t_hs string);

/*
** Prints a heap string to the standard output
*/
int     hs_print(t_hs string);
int     hs_print_err(t_hs string);
int     hs_print_file(t_hs string, int output_file);

/*
** Like hs_print_*() functions, but prints a "\n" at the end
*/
int     hs_puts(t_hs string);
int     hs_puts_err(t_hs string);
int     hs_puts_file(t_hs string, int output_file);

/*
** Returns the lowest index in hs where the substring is found
**
** The search starts from start_index.
**
** Returns -1 on failure.
*/
int     hs_find(t_hs string, t_hs substring, size_t start_index);
int     hs_find_char(t_hs string, char c, size_t start_index);

t_hs    hs_slice(t_hs string, int start_index, int end_index);

/*
** Forward declarations
*/
struct                          s_glist_hs;
typedef struct s_glist_hs       t_glist_hs_;

t_glist_hs_     hs_split(t_hs string, t_hs separator);

t_hs    hs_join(t_hs separator, const t_glist_hs_ *strings);

int     hs_get_real_index(t_hs string, int index);

t_hs    hs_to_lower(t_hs string);
t_hs    hs_to_upper(t_hs string);

char    char_is_alpha(char c);
char    char_is_alpha_numeric(char c);
char    char_is_digit(char c);
char    char_is_lower(char c);
char    char_is_upper(char c);

char    char_to_lower(char c);
char    char_to_upper(char c);

/*
** Returns true if the given char is a space, a form-feed ('\f'),
** a newline ('\n'), a carriage return ('\r'), a horizontal tab
** ('\t') or a vertical tab ('\v').
*/
int     char_is_whitespace(char c);

int     hs_is_alpha(t_hs string);
int     hs_is_lower(t_hs string);
int     hs_is_upper(t_hs string);
int     hs_is_alpha_numeric(t_hs string);
int     hs_is_digit(t_hs string);
int     hs_is_hex_digit(t_hs string);

/*
** Returns true if the given string is a space, a form-feed ('\f'),
** a newline ('\n'), a carriage return ('\r'), a horizontal tab
** ('\t') or a vertical tab ('\v').
*/
int     hs_is_whitespace(t_hs string);

t_hs    hs_lstrip(t_hs string);
t_hs    hs_rstrip(t_hs string);
t_hs    hs_strip(t_hs string);

#endif /* HS_H */
