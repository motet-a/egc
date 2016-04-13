# egc

A garbage collector written in C for EPITECH projects.



## Download and compile

```sh
git clone https://github.com/motet-a/egc.git
cd egc
make
```



## Heap strings

egc comes with string manipulation functions. Their prototypes
are in `include/hs.h`.

A *heap string* is represented with the type `t_hs`. It is a
garbage-collected sequence of bytes, stored on the heap.



## `egc_printf()`, `egc_fprintf()`

These are like `printf()` and `fprintf()`, except that `printf()`
and `fprintf()` support flags and many more specifiers.

There is no `egc_sprintf()`, but `hs_format()` is a bit like
`asprintf()`.



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

    static int              main2(int argc, char **arg)
    {
      /* Here, you can do as many egc_malloc() as you want */
    }

    int                     main(int argc, char **arg)
    {
      int                   r;
      t_egc_private_data    private_data;

      egc_start(&private_data, &print_error, NULL, 0);
      r = main2(argc, argv)
      egc_stop();
      return (r);
    }
