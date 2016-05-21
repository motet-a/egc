/*
** egc.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 30 17:33:03 2016 antoine
** Last update Wed Mar 30 17:33:03 2016 antoine
*/

#ifndef EGC_H
# define EGC_H

# include <stdlib.h>
# include "egc_string.h"
# include "hs.h"

# include "glist_char.h"
# include "glist_double.h"
# include "glist_float.h"
# include "glist_hs.h"
# include "glist_int.h"
# include "glist_long.h"
# include "glist_str.h"
# include "glist_uint.h"
# include "glist_ulong.h"
# include "glist_voidp.h"

typedef void    (*t_egc_error_callback)(const char *message);

typedef int     (*t_egc_main_function)(int argc, char **argv);

/*
** Runs a garbage-collected program
**
** You should call this function before any other egc's function.
**
** This functions initializes egc and calls the given function pointer
** `aux_main`. `argc` and `argv` are passed unmodified to `aux_main`.
**
** The default error callback is the following:
**
**     void print_function(const char *string)
**     {
**       while (*string)
**         {
**           write(STDERR_FILENO, string, 1);
**           string++;
**         }
**     }
**
** It prints the error messages and the logs on the error output.
**
*/
int     egc_run(int argc, char **argv, t_egc_main_function aux_main);

/*
** Sets up pseudo-statics variables
**
** `statics` is the pointer returned by egc_get_statics().
** It can be NULL.
**
** `statics_size` is the size of the struct pointed to by `statics`.
** If `statics` is not a pointer to a struct, or if `statics_size`
** is zero, then `statics_size` should be specified as zero.
*/
void    egc_set_statics(void *statics, size_t statics_size);

/*
** Returns the `statics` pointer given to `egc_set_statics()`
**
** Returns NULL if `egc_set_statics()` has not been called.
*/
void    *egc_get_statics(void);

/*
** Returns the `static_size` integer given to `egc_set_statics()`
**
** Returns zero if `egc_set_statics()` has not been called.
*/
size_t  egc_get_statics_size(void);

/*
** Sets the error callback
**
** `error_cb` is a pointer to a function which will be called
** on error. Some my_putstr()-like function will do the job.
** Each error message is terminated with a new line.
*/
void    egc_set_error_callback(t_egc_error_callback error_callback);

/*
** Stops egc and exits the program
**
** Avoid to call directly exit(), prefer this function.
*/
void    egc_exit(int status);

/*
** Returns a garbage-collected memory area
**
** Never returns NULL.
*/
void    *egc_malloc(size_t size);

/*
** Like realloc()
**
** The returned pointer may be different than `data`.
*/
void    *egc_realloc(void *data, size_t size);

void    *egc_malloc_atomic(size_t size);

/*
** Some useful macros
*/
# define EGC_NEW(type)          (type *)egc_malloc(sizeof(type))
# define EGC_NEW_ATOMIC(type)   (type *)egc_malloc_atomic(sizeof(type))

/*
** Performs a garbage collection
*/
void    egc_collect(void);

/*
** Prints some statistics
*/
void    egc_print_stats(void);

#endif /* EGC_H */
