#!/usr/bin/env python3

import sys


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
#ifndef GLIST_H
# define GLIST_H

# INCLUDES

/*
** T_GLIST - a list of T_ITEM
*/
typedef struct          S_GLIST
{
  size_t                available;
  size_t                size;
  T_ITEM                *items;
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
int             GLIST_size(const T_GLIST *list);

/*
** Calls `f` on each element of the list
*/
void    GLIST_apply(const T_GLIST *list, T_GLIST_func f);

#endif /* EGC_H */
"""

SOURCE0_TEMPLATE = EPITECH_HEADER_COMMENT + """
#INCLUDES

T_GLIST                 GLIST_new(void)
{
  T_GLIST               list;

  list.available = 0;
  list.size = 0;
  list.items = NULL;
  return (list);
}

T_GLIST                 GLIST_copy(const T_GLIST *source)
{
  T_GLIST               new;
  int                   i;

  new.available = source->size;
  new.size = source->size;
  new.items = egc_malloc(sizeof(T_ITEM) * source->size);
  i = -1;
  while (++i < (int)new.size)
    new.items[i] = source->items[i];
  return (new);
}
"""

SOURCE1_TEMPLATE = EPITECH_HEADER_COMMENT + """
#INCLUDES

static void     grow(T_GLIST *list, size_t new_size)
{
  if (list->available >= new_size)
    return ;
  if (new_size < list->available * 2)
    new_size = list->available * 2;
  list->available = new_size;
  list->items = egc_realloc(list->items, sizeof(T_ITEM) * new_size);
}

void            GLIST_append(T_GLIST *list, T_ITEM item)
{
  grow(list, list->size + 1);
  list->items[list->size] = item;
  list->size++;
}

void            GLIST_append_all(T_GLIST *left,
                                 const T_GLIST *right)
{
  int   i;

  i = -1;
  while (++i < (int)right->size)
    GLIST_append(left, right->items[i]);
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
  return (list->items[index]);
}

T_ITEM          GLIST_set(T_GLIST *list,
                          int index,
                          T_ITEM new)
{
  T_ITEM        old;

  if (index == (int)list->size)
    {
      GLIST_append(list, new);
      return (new);
    }
  old = GLIST_get(list, index);
  list->items[index] = new;
  return (old);
}

int             GLIST_size(const T_GLIST *list)
{
  return (list->size);
}

void            GLIST_apply(const T_GLIST *list,
                            T_GLIST_func func)
{
  int           i;

  i = -1;
  while (++i < (int)list->size)
    func(i, list->items[i]);
}
"""

SOURCE_TEMPLATES = [
    SOURCE0_TEMPLATE,
    SOURCE1_TEMPLATE,
    SOURCE2_TEMPLATE,
]


def get_leading_space_count(string):
    space_count = 0
    for c in string:
        if c != ' ':
            break
        space_count += 1
    return space_count


def replace_in_line_once(line, old, new):
    is_pointer = new.endswith(' *')
    if is_pointer:
        new = new[:-2]
    before = line[:line.index(old)]
    after = line[line.index(old) + len(old):]
    assert before + old + after == line
    after_space_count = get_leading_space_count(after)
    after = after[after_space_count:]
    if after_space_count > 2:
        length_diff = len(new) - len(old)
        after_space_count -= length_diff
    after_spaces = after_space_count * ' '
    line = before + new + after_spaces
    if is_pointer:
        line += '*'
    line += after
    return line


def replace_in_line(line, old, new):
    while old in line:
        line = replace_in_line_once(line, old, new)
    return line


def indent(line, prev_lines):
    if (')' in line or line.endswith(',')) and '(' not in line:
        for prev_line in reversed(prev_lines):
            if '(' in prev_line and ')' not in prev_line:
                indent = prev_line.index('(') + 1
                line = ' ' * indent + line.strip()
                return line
    return line


def replace(string, old, new):
    lines = string.split('\n')
    new_lines = []
    for line in lines:
        if len(new_lines) > 0:
            line = indent(line, new_lines)
        line = replace_in_line(line, old, new)
        new_lines.append(line)
    return '\n'.join(new_lines)


def replace_multi(source, replacements):
    for old, new in replacements:
        source = replace(source, old, new)
    return source


def gen_content(source, item_type_name, item_type):
    replacements = [
        ('T_GLIST', 't_glist_' + item_type_name),
        ('S_GLIST', 's_glist_' + item_type_name),
        ('T_ITEM', item_type),
        ('GLIST_', 'glist_' + item_type_name + '_'),
    ]

    generated = replace_multi(source, replacements)
    return generated


def gen_header_content(item_type_name, item_type):
    return gen_content(HEADER_TEMPLATE, item_type_name, item_type)


def gen_sources_contents(item_type_name, item_type):
    return [gen_content(template, item_type_name, item_type)
            for template in SOURCE_TEMPLATES]


def check_line_length(string):
    for line in string.splitlines():
        if len(line) > 79:
            raise Exception("Too long line:\n" + line)


def gen_file(content, file_name, includes):
    print('Generating', file_name)
    includes = ['include ' + inc for inc in includes]
    replacements = [
        ('#INCLUDES', '\n'.join(['#' + i for i in includes])),
        ('# INCLUDES', '\n'.join(['# ' + i for i in includes])),
        ('#  INCLUDES', '\n'.join(['#  ' + i for i in includes])),
        ('FILE_NAME', file_name),
    ]
    generated = replace_multi(content, replacements)
    check_line_length(generated)
    return generated


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
