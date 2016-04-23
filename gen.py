#!/usr/bin/env python3

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


def indent_line(line, prev_lines):
    if (')' in line or line.endswith(',')) and '(' not in line:
        for prev_line in reversed(prev_lines):
            if '(' in prev_line and ')' not in prev_line:
                indent = prev_line.index('(') + 1
                line = ' ' * indent + line.strip()
                return line
    return line


def replace_once(string, old, new):
    lines = string.split('\n')
    new_lines = []
    for line in lines:
        if len(new_lines) > 0:
            line = indent_line(line, new_lines)
        line = replace_in_line(line, old, new)
        new_lines.append(line)
    return '\n'.join(new_lines)


def check_line_length(string):
    for line in string.splitlines():
        if len(line) > 79:
            raise Exception("Too long line:\n" + line)


def replace(source, replacements):
    for old, new in replacements:
        source = replace_once(source, old, new)
    check_line_length(source)
    return source
