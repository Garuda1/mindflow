#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "vm.h"

static void dump_entry(const uint8_t add, const uint8_t val)
{
  printf("%2X:%2X ", add, val);
}

void vm_dumpmem(const t_vm *dxvm)
{
  size_t x;
  size_t y;
  size_t i;

  puts("--- MEMORY DUMP ---");
  y = 0;
  while (y < (VM_MEM_SIZE / (VM_DUMPMEM_ENTRIES_PER_LINE-1)))
  {
    putchar('\n');
    x = 0;
    while (x < VM_DUMPMEM_ENTRIES_PER_LINE && (y * VM_DUMPMEM_ENTRIES_PER_LINE) + x < VM_MEM_SIZE)
    {
      dump_entry((y * VM_DUMPMEM_ENTRIES_PER_LINE) + x, dxvm->mem[(y * VM_DUMPMEM_ENTRIES_PER_LINE) + x]);
      ++x;
    }
    ++y;
  }
  #if VM_DUMPREGS == 1
  puts("Registers:\n");
  for (i = 0; i<sizeof(dxvm->reg); ++i)
    printf("reg[%lu]:  0x%.2X\n", i, dxvm->reg[i]);
  printf("%%sp: %u", dxvm->sp);
  printf("%%ip: %u", dxvm->ip);
  #endif
  puts("\n--- MEMORY DUMP ---\n");
}
