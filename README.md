# egc

[![Build Status](http://segfault.pro/job/egc/badge/icon)](http://segfault.pro/job/egc/)

A garbage collector written in C for EPITECH projects.

In fact, it was a garbage collector, but now it is more than a
garbage collector.

**Warning**: Don't use this in an EPITECH project since I use it in my
own projects.



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



## Test

Run the `test` executable in the `test/` directory:

```sh
./test/test
```



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

`egc_realloc()` acts like `realloc()`, but returns a
garbage-collected block too. An atomic block resized with
`egc_realloc()` remains atomic, a non-atomic one remains non-atomic.
*TODO: Add tests for that*.

Warning: Don't store a pointer returned by the system `malloc()`
inside a garbage-collected block (returned by `egc_malloc()`).
The blocks returned by `malloc()` are not visited by the garbage
collector, and can be faulty marked as unused during the garbage
collection. This can lead to hard-to-find bugs.

*TODO: Write more text here*



## Generic lists

egc comes with generic lists, implemented with an `egc_malloced`
array resized with `egc_realloc()` — a bit like `std::vector` in
C++.

Generic lists are generated with `glist_gen.py`. `make all` runs
this script if the generated sources are not present.

Generated source files are not removed on `make fclean`, and are
not regenerated on `make re`. You must use `make glist_clean` to
remove these ones.

All this stuff is still under development, still unstable and
still subject to major changes.



## Heap strings

egc comes with string manipulation functions. Their prototypes
are in `include/hs.h`.

A *heap string* is represented with the type `t_hs`. It is a
garbage-collected sequence of bytes, stored on the heap. Heap
strings should be considered immutable.

Heap strings can contain binary data and NULs.

Avoid accessing heap strings with pointers. In function arguments,
pass heap strings by value - unless you want to write a heap
string at the given address. Don't write this:

```c
void    print_string(t_hs *hs);
```

but:

```c
void    print_string(t_hs hs);
```

Moreover, don't use `const` heap strings. It is useless, since
a heap string should be considered immutable.

Heap strings can be created with the `hs()`, `hs_new_*()` or
`hs_format()` functions, concatenated with the `hs_concat_*()`
functions, and printed with the `hs_print_*()` or `egc_printf()`
functions.

You can get the length of a heap string `hs` with `hs_length()`.
Don't access directly the members of a `t_hs`.

You can convert a `t_hs` to a null-terminated C string with
`hs_to_str()`.



## printf-like functions

`egc_printf()` and `egc_fprintf()` are like `printf()` and
`fprintf()`, except that `printf()` and `fprintf()` support
flags and many more specifiers.

There is no `egc_sprintf()`, but `hs_format()` is a bit like
the GNU function `asprintf()`.

The directives `d`, `i`, `u`, `x`, `p`, `c` and `s` are supported.

The length specifiers `h`, `hh` and `l` are supported.

Use `%hs` to print heap strings:

```c
egc_printf("This is a plain old C string: %s\n", "hello");
egc_printf("This is a heap string: %hs\n", hs("hello"));
```


## Legacy string manipulation functions

There are some functions in `include/egc_string.h` to handle
NUL-terminated C strings (they are cloned from `string.h`).

Prefer *heap strings*.



## Debugging

If the macro `EGC_DEBUG` is defined, you can debug your program
with Valgrind and the suppression file `valgrind.supp`.

`make DEBUG=true` compiles egc with `EGC_DEBUG` defined.
