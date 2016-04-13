# egc

A garbage collector written in C for EPITECH projects.



## Download and compile

```sh
git clone https://github.com/motet-a/egc.git
cd egc
make
```

You can compile `example.c` with the following command:

`cc -o example example.c libegc.a`

Read the **Debugging** section for debugging.



## Initialization and shutdown

The function `egc_start()` starts the garbage collector. Typically,
you should call `egc_start()` in the `main()` function.

The first argument of `egc_start()` should be a pointer to a
`t_egc_private_data` allocated on the stack.


egc should be stopped with `egc_stop()` to free some allocated
resources. You should always call it before exiting your program.
`egc_exit()` is the same as a call to `egc_stop()` and `exit()`.

Here is a typical `main()` function of a garbage-collected program:

```c
int                     main()
{
  t_egc_private_data    private_data;

  egc_start(&private_data);
  whats_your_name();
  egc_stop();
}
```



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
