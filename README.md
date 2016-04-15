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

```c
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
and returns the value returned by `main2()`.

You can exit the program from `main2()` with `egc_exit()`. It
stops the garbage collector and acts like `exit()`.



## Allocate garbage-collected memory

`egc_malloc()` acts like `malloc()` exept you should not `free()`
the returned pointer.

`egc_malloc_atomic()` is like `egc_malloc()` except the returned
block is not visited during garbage collection. Use this function
if the allocated block should not contain a pointer to a
garbage-collected block.

Avoid using `egc_realloc()` yet, it is still unstable.

Warning: Don't store a pointer returned by the system `malloc()`
inside a garbage-collected block (returned by `egc_malloc()`).
The blocks returned by `malloc()` are not visited by the garbage
collector, and can be faulty marked as unused during the garbage
collection. This can lead to hard-to-find bugs.

*TODO: Write more text here*



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
