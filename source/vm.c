#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "msg.h"

t_vm *vm_new(const size_t mem_size)
{
  t_vm *vm;

  if ((vm = malloc(sizeof(t_vm))) == NULL)
  {
    fprintf(stderr, VM_MSG_VMALLOCFAILED "(%s:%d)\n", __FILE__, __LINE__);
    return (NULL);
  }

  if ((vm->mem = malloc(mem_size)) == NULL)
  {
    fprintf(stderr, VM_MSG_VMMEMALLOCFAILED "(%s:%d)\n", __FILE__, __LINE__);
    return (NULL);
  }

  return (vm);
}

t_vm *vm_init(t_vm *vm, const uint8_t *prog)
{
  if (vm == NULL)
  {
    fprintf(stderr, VM_MSG_NULLVMPTR "(%s:%d)\n", __FILE__, __LINE__);
    return (NULL);
  }

  memset((void*)vm, 0, sizeof(t_vm)); /* Zero out the VM and its registers/memory */
  vm->sp = VM_MEM_SIZE;

  if (prog == NULL)
    fprintf(stderr, VM_MSG_NULLPROGPTR "(%s:%d)\n", __FILE__, __LINE__);
  else
    memcpy((char*)(vm->mem), (char*)prog, VM_MEM_SIZE);

  puts(VM_MSG_INITIALIZED);
  return (vm);
}

uint8_t vm_exec1(t_vm *vm)
{
  uint8_t vmstat;

  vmstat = vm_op_tab[vm->mem[vm->ip]](vm);

  if (vmstat == VM_STAT_FATAL)
    fprintf(stderr, VM_MSG_FATALERROR "(%s:%d)\n", __FILE__, __LINE__);
  ++(vm->ip);              /* Increment the instruction pointer */
  vm->ip %= VM_MEM_SIZE; /* Increment the instruction pointer */

  if (vmstat == VM_STAT_STOP)
    puts(VM_MSG_EXECHALTED);

  return vmstat;
}

uint8_t vm_exec(t_vm *vm)
{
  uint8_t vmstat;
  uint32_t cycle;

  cycle = 0;
  puts(VM_MSG_EXECSTARTED);
  while ((vmstat = vm_exec1(vm)) != VM_STAT_STOP)
  {
    if (cycle == VM_DUMP_CYCLE)
    {
      fprintf(stderr, VM_MSG_EXECSTOPPED, cycle);
      vm_dumpmem(vm);
      vmstat = VM_STAT_DUMP;
      return (vmstat);
    }
    ++cycle;
  }
  return (vmstat);
}
