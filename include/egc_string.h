/*
** egc_string.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr  2 09:20:49 2016 antoine
** Last update Sat Apr  2 09:20:49 2016 antoine
*/

#ifndef EGC_STRING_H_
# define EGC_STRING_H_

# include <stddef.h>
# include <stdarg.h>

size_t          egc_strlen(const char *string);
void            egc_strcpy(char *dest, const char *source);
void            egc_memcpy(char *dest, const char *source, size_t n);

int             egc_printf(const char *format, ...);
int             egc_fprintf(int file_descriptor, const char *format, ...);

int             egc_vprintf(const char *format, va_list list);
int             egc_vfprintf(int file, const char *format, va_list list);

#endif /* !EGC_STRING_H_ */
