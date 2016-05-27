#!/usr/bin/env python3

import sys
import gen


EPITECH_HEADER_COMMENT = """/*
** FILE_NAME for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:01:50 2016 antoine
** Last update Thu Mar 31 13:01:50 2016 antoine
*/
"""

HEADER_TEMPLATE = EPITECH_HEADER_COMMENT + """
#ifndef ONCE_INCLUDE_GUARD
# define ONCE_INCLUDE_GUARD

# INCLUDES

/*
** T_GLIST - a list of T_ITEM
**
** Don't access these members directly.
*/
typedef struct          S_GLIST
{
  size_t                _available;
  size_t                _size;
  T_ITEM                *_items;
}                       T_GLIST;

typedef void (*T_GLIST_func)(int index, T_ITEM item);

/*
** Creates a new empty list
*/
T_GLIST         GLIST_new(void);

T_GLIST         GLIST_copy(const T_GLIST *source);

/*
** Appends an element to the end of the list
*/
void            GLIST_append(T_GLIST *list, T_ITEM item);

void            GLIST_append_all(T_GLIST *list,
                                 const T_GLIST *new_items);

T_GLIST         GLIST_add(const T_GLIST *left,
                          const T_GLIST *right);

T_ITEM          GLIST_get(const T_GLIST *list, int index);
T_ITEM          GLIST_set(T_GLIST *list,
                          int index,
                          T_ITEM n);

/*
** Returns the size of a list
*/
int             GLIST_length(const T_GLIST *list);

/*
** Calls `f` on each element of the list
*/
void    GLIST_apply(const T_GLIST *list, T_GLIST_func f);

#endif /* !ONCE_INCLUDE_GUARD */
"""

SOURCE0_TEMPLATE = EPITECH_HEADER_COMMENT + """
#INCLUDES

T_GLIST                 GLIST_new(void)
{
  T_GLIST               list;

  list._available = 0;
  list._size = 0;
  list._items = NULL;
  return (list);
}

T_GLIST                 GLIST_copy(const T_GLIST *source)
{
  T_GLIST               new;
  int                   i;

  new._available = source->_size;
  new._size = source->_size;
  new._items = egc_malloc(sizeof(T_ITEM) * source->_size);
  i = -1;
  while (++i < (int)new._size)
    new._items[i] = source->_items[i];
  return (new);
}
"""

SOURCE1_TEMPLATE = EPITECH_HEADER_COMMENT + """
#INCLUDES

static void     grow(T_GLIST *list, size_t new_size)
{
  if (list->_available >= new_size)
    return ;
  if (new_size < list->_available * 2)
    new_size = list->_available * 2;
  list->_available = new_size;
  list->_items = egc_realloc(list->_items, sizeof(T_ITEM) * new_size);
}

void            GLIST_append(T_GLIST *list, T_ITEM item)
{
  grow(list, list->_size + 1);
  list->_items[list->_size] = item;
  list->_size++;
}

void            GLIST_append_all(T_GLIST *left,
                                 const T_GLIST *right)
{
  int   i;

  i = -1;
  while (++i < (int)right->_size)
    GLIST_append(left, right->_items[i]);
}
"""

SOURCE2_TEMPLATE = EPITECH_HEADER_COMMENT + """
#INCLUDES

T_GLIST                 GLIST_add(const T_GLIST *left,
                                  const T_GLIST *right)
{
  T_GLIST               new;

  new = GLIST_new();
  GLIST_append_all(&new, left);
  GLIST_append_all(&new, right);
  return (new);
}

T_ITEM          GLIST_get(const T_GLIST *list, int index)
{
  return (list->_items[index]);
}

T_ITEM          GLIST_set(T_GLIST *list,
                          int index,
                          T_ITEM new)
{
  T_ITEM        old;

  if (index == (int)list->_size)
    {
      GLIST_append(list, new);
      return (new);
    }
  old = GLIST_get(list, index);
  list->_items[index] = new;
  return (old);
}

int             GLIST_length(const T_GLIST *list)
{
  return (list->_size);
}

void            GLIST_apply(const T_GLIST *list,
                            T_GLIST_func func)
{
  int           i;

  i = -1;
  while (++i < (int)list->_size)
    func(i, list->_items[i]);
}
"""

SOURCE_TEMPLATES = [
    SOURCE0_TEMPLATE,
    SOURCE1_TEMPLATE,
    SOURCE2_TEMPLATE,
]


def gen_content(content, item_type_name, item_type):
    replacements = [
        ('T_GLIST', 't_glist_' + item_type_name),
        ('S_GLIST', 's_glist_' + item_type_name),
        ('T_ITEM', item_type),
        ('GLIST_', 'glist_' + item_type_name + '_'),
        ('ONCE_INCLUDE_GUARD', 'GLIST_' + item_type_name.upper() + '_H_'),
    ]
    return gen.replace(content, replacements)


def gen_header_content(item_type_name, item_type):
    return gen_content(HEADER_TEMPLATE, item_type_name, item_type)


def gen_sources_contents(item_type_name, item_type):
    return [gen_content(template, item_type_name, item_type)
            for template in SOURCE_TEMPLATES]


def gen_file(content, file_name, includes):
    print('Generating', file_name)
    includes = ['include ' + inc for inc in includes]
    replacements = [
        ('#INCLUDES', '\n'.join(['#' + i for i in includes])),
        ('# INCLUDES', '\n'.join(['# ' + i for i in includes])),
        ('#  INCLUDES', '\n'.join(['#  ' + i for i in includes])),
        ('FILE_NAME', file_name),
    ]
    return gen.replace(content, replacements)


def write_to_dir(content, file_name, dir_path):
    import os
    path = os.path.join(dir_path, file_name)
    with open(path, 'w') as f:
        f.write(content)


def gen_and_write_header(item_type_name, item_type, dir_path):
    source = gen_header_content(item_type_name, item_type)
    file_name = 'glist_' + item_type_name + '.h'
    source = gen_file(source, file_name, ['"egc.h"'])
    write_to_dir(source, file_name, dir_path)


def gen_and_write_source(item_type_name, item_type, dir_path):
    sources = gen_sources_contents(item_type_name, item_type)
    for i, source in enumerate(sources):
        file_name = 'glist_' + item_type_name + '_' + str(i) + '.c'
        source = gen_file(source, file_name, ['"egc.h"'])
        write_to_dir(source, file_name, dir_path)


def gen_and_write_list(item_type_name, item_type, include_dir, source_dir):
    gen_and_write_header(item_type_name, item_type, include_dir)
    gen_and_write_source(item_type_name, item_type, source_dir)


def gen_standard_lists(types, include_dir, source_dir):
    for item_type_name, item_type in types:
        gen_and_write_list(item_type_name, item_type,
                           include_dir, source_dir)


def main():
    types = [
        ('int', 'int'),
        ('uint', 'unsigned int'),
        ('long', 'long'),
        ('ulong', 'unsigned long'),
        ('float', 'float'),
        ('double', 'double'),
        ('char', 'char'),
        ('hs', 't_hs'),
        ('voidp', 'void *'),
        ('str', 'const char *'),
    ]
    gen_standard_lists(types, 'include', 'src')


if __name__ == '__main__':
    main()
