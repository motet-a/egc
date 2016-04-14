# egc

A garbage collector written in C for EPITECH projects.



## Download and build

```sh
git clone https://github.com/motet-a/egc.git
cd egc
make
```

You can compile `example.c` with the following command:

`cc -o example example.c libegc.a`

See also the [Debugging](https://github.com/motet-a/egc#debugging)
section.



## Initialization and shutdown

egc should be started with `egc_run()`. This function accepts a
pointer to a function which should contain all the calls to the
other egc routines.

Here is a typical `main()` function of a garbage-collected program:

```
int     main2(int argc, char **argv)
{
  /* do garbage-collected stuff here */
  return (0);
}

int     main(int argc, char **argv)
{
  return (egc_run(argc, argv, main2));
}
```

`egc_run()` passes `argc` and `argv` unmodified to `main2()`,
and returns the value returned by `main2()` — or the argument of
a call to `egc_exit()`.

You can exit the program from `main2()` with `egc_exit()`. The value
returned by `egc_run()` will be the parameter of `egc_exit()` in this
case.



## Allocate garbage-collected memory

TODO



## Heap strings

egc comes with string manipulation functions. Their prototypes
are in `include/hs.h`.

A *heap string* is represented with the type `t_hs`. It is a
garbage-collected sequence of bytes, stored on the heap. Heap
strings should be considered immutable.

Heap strings can contain binary data and NULs.

Avoid accessing heap strings with pointers. In function arguments,
pass heap strings by value. Don't write this:

```c
void    print_string(t_hs *hs);
```

but:

```c
void    print_string(t_hs hs);
```

Moreover, don't use `const` heap strings. It is useless, since
a heap string should be considered immutable.

Heap strings can be created with the `hs_new_*()` and
`hs_format()` functions, concatenated with the `hs_concat_*()`
functions, and printed with `hs_print_*()` or `egc_printf()`
functions.

You can get the length of a heap string `hs` with `hs.length`.
You can access directly its bytes with `hs.chars` — but keep
in mind that it is not NUL-terminated and it can contain NULs.



## printf-like functions

`egc_printf()` and `egc_fprintf()` are like `printf()` and
`fprintf()`, except that `printf()` and `fprintf()` support
flags and many more specifiers.

There is no `egc_sprintf()`, but `hs_format()` is a bit like
the GNU function `asprintf()`.



## Legacy string manipulation functions

There are some functions in `include/egc_string.h` to handle
NUL-terminated C strings (they are cloned from `string.h`).

Prefer *heap strings*.



## Debugging

If the macro `EGC_DEBUG` is defined, you can debug your program
with Valgrind and the suppression file `valgrind.supp`.

`make DEBUG=true` compiles egc with `EGC_DEBUG` defined.



## Bugs

The function which contains the structure `t_egc_private_data` on
the stack is called "root function" in the following lines.

The pointers on the stack in the root function are not guaranteed
to be visited by the garbage collector. If a pointer in the root
function points to a memory block returned by `egc_malloc()`,
`egc_malloc_atomic()` or `egc_realloc()`, it can be invalidated.

The best practice to avoid that is to do nothing in the root
function except allocating a `t_egc_private_data` on the stack and
calling `egc_start()` and `egc_stop()`:

```c
static int              main2(int argc, char **arg)
{
  /* Here, you can do as many egc_malloc() as you want */
}

int                     main(int argc, char **arg)
{
  int                   r;
  t_egc_private_data    private_data;

  egc_start(&private_data);
  r = main2(argc, argv)
  egc_stop();
  return (r);
}
```
