/*
** collect.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Mar 31 13:07:36 2016 antoine
** Last update Thu Mar 31 13:07:36 2016 antoine
*/

#include "private.h"

static void     egc_heap_free_unmarked(t_heap *heap)
{
  t_block       *block;
  t_block_flags flags;

  block = NULL;
  while ((block = egc_get_next_block(heap, block)))
    {
      flags = block->flags;
      if (!(flags & BLOCK_FLAGS_MARK) && !(flags & BLOCK_FLAGS_FREE))
        {
          STATICS->total_free_count++;
          egc_block_free(block, heap);
          egc_heap_free_unmarked(heap);
          return ;
        }
    }
}

static void     egc_free_unmarked(void)
{
  t_heap        *heap;

  heap = STATICS->heaps;
  while (heap)
    {
      egc_heap_free_unmarked(heap);
      heap = heap->next;
    }
}

void            egc_collect_impl(void)
{
  LOG("egc_collect()");
  LOG("");
  egc_unmark();
  egc_mark_stack();
  egc_mark_user_statics();
  egc_free_unmarked();
  egc_defrag();
  STATICS->collection_count++;
  LOG("egc_collect() end");
  LOG("");
}

#if __x86_64__
void            egc_collect(void)
{
  (void)STATICS;
  AVT("pushq %rax\n pushq %rbx\n pushq %rcx\n pushq %rdx\n"
      "pushq %r8\n pushq %r9\n pushq %r10\n pushq %r11\n"
      "pushq %r12\n pushq %r13\n pushq %r14\n pushq %r15\n"
      "pushq %rsi\n pushq %rdi\n");
  (void)STATICS;
  egc_collect_impl();
  (void)STATICS;
  AVT("popq %rdi\n popq %rsi\n"
      "popq %r15\n popq %r14\n popq %r13\n popq %r12\n"
      "popq %r11\n popq %r10\n popq %r9\n popq %r8\n"
      "popq %rdx\n popq %rcx\n popq %rbx\n popq %rax\n");
  (void)STATICS;
}
#else
/*
** TODO: Test this function on x86
*/
void            egc_collect(void)
{
  AVT("pushl %eax\n pushl %ebx\n pushl %ecx\n pushl %edx\n"
      "pushl %esi\n pushl %edi\n");
  egc_collect_impl();
  AVT("popl %edi\n popl %esi\n"
      "popl %edx\n popl %ecx\n popl %ebx\n popl %eax\n");
}
#endif
