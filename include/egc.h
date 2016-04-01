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

typedef size_t  t_egc_private_data[32];

typedef void    (*t_egc_error_callback)(const char *message);

/*
** Starts EGC
**
** `private_data` is a pointer to a t_egc_private_data on the
** stack. EGC can't work if it is not on the stack.
**
** `error_cb` is a pointer to a function which will be called
** on error. Some my_putstr()-like function will do the job.
** Each error message is terminated with a new line.
**
** `user_statics` is the pointer returned by egc_get_statics().
** It can be NULL.
*/
void    egc_start(t_egc_private_data *private_data,
                  t_egc_error_callback error_cb,
                  void *user_statics);

void    egc_stop(void);

void    egc_exit(int status);

/*
** Returns a garbage-collected memory area
**
** Never returns NULL.
*/
void    *egc_malloc(size_t size);

void    *egc_malloc_atomic(size_t size);

/*
** Performs a garbage collection
*/
void    egc_collect(void);

/*
** Returns the `user_statics` pointer given to `egc_start()`
*/
void    *egc_get_statics(void);

#endif /* EGC_H */
