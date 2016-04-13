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

typedef size_t  t_egc_private_data[32];

typedef void    (*t_egc_error_callback)(const char *message);

/*
** Starts EGC
**
** You should call this function before any other egc's function.
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
** `egc_data` is a pointer to a `t_egc_private_data` on the
** stack. EGC can't work if it is not on the stack.
**
*/
void    egc_start(t_egc_private_data *egc_data);

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
** Returns the `statics` pointer given to `egc_start()`
*/
void    *egc_get_statics(void);

/*
** Sets the error callback
**
** `error_cb` is a pointer to a function which will be called
** on error. Some my_putstr()-like function will do the job.
** Each error message is terminated with a new line.
*/
void    egc_set_error_callback(t_egc_error_callback error_callback);

/*
** Stops egc
*/
void    egc_stop(void);

/*
** Stops egc and exits the program
**
** A call to `egc_exit(4)` is similar to:
**
**     egc_stop();
**     exit(4);
**
** Avoid to call directly exit(), prefer this function.
*/
void    egc_exit(int status);

/*
** Aborts the program execution
*/
void    egc_abort(void);

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

#endif /* EGC_H */
